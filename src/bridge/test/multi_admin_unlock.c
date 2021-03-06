#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/time.h>
#include <syslog.h>
#include <stdlib.h>
#include <bridge/bridge_main/ign_constants.h>
#include <bridge/bridge_main/log.h>
#include <bridge/bridge_main/sysinfo.h>
#include <bridge/bridge_main/ign.h>
#include <bridge/bridge_main/task.h>
#include <bridge/bridge_main/thread_helper.h>
#include <bridge/bridge_main/mutex_helper.h>
#include <bridge/bridge_main/task_queue.h>
#include <bridge/bridge_main/wait_ble.h>
#include <bridge/ble/ble_discover.h>
#include <bridge/ble/lock.h>
#include <bridge/ble/ble_pairing.h>
#include <bridge/bridge_main/lock_list.h>
#include <bridge/ble/ble_admin.h>
#include <bridge/ble/ble_pairing.h>
#include <ctype.h>

void saveTaskData(task_node_t *ptn)
{
    if (!ptn) return;

    if(ptn->ble_data && ptn->ble_data_len)
    {
        ble_data_t *ble_data = ptn->ble_data;
        int task_type = ptn->task_type;
        switch (task_type)
        {
        case TASK_BLE_ADMIN_UNLOCK:
        {
            serverLog(LL_NOTICE, "saving ble TASK_BLE_ADMIN_UNLOCK data");
            ble_admin_result_t *admin_unlock_result = (ble_admin_result_t *)ble_data->ble_result;
            int unlock_error = admin_unlock_result->unlock_result;
            if (unlock_error)
            {
                serverLog(LL_ERROR, "unlock error");
            }
            else
            {
                serverLog(LL_ERROR, "unlock success");
            }
                    
            break;
        }
        default:
            break;
        }
    }
}


int testUnLock(igm_lock_t *lock) {
    serverLog(LL_NOTICE,"UnLock cmd ask invoker to release the lock.");
      
    ble_admin_param_t *admin_param = (ble_admin_param_t *)malloc(sizeof(ble_admin_param_t));
    bleInitAdminParam(admin_param);
    bleSetAdminParam(admin_param, lock);

    ble_data_t *ble_data = malloc(sizeof(ble_data_t));
    bleInitData(ble_data);
    bleSetBleParam(ble_data, admin_param, sizeof(ble_admin_param_t));

    fsm_table_t *unlock_fsm = getAdminUnlockFsmTable();
    int fsm_max_n = getAdminUnlockFsmTableLen();
    int current_state = BLE_ADMIN_BEGIN;
    int error = 0;

    task_node_t *tn = (task_node_t *)malloc(sizeof(task_node_t));
    tn->ble_data = ble_data;

    tn->sm_table_len = fsm_max_n;
    tn->task_sm_table = unlock_fsm;

    tn->task_type = TASK_BLE_ADMIN_UNLOCK;

    for (int j = 0; j < fsm_max_n; j++)
    {
        if (current_state == tn->task_sm_table[j].cur_state) {
            // 增加一个判断当前函数, 是否当前函数出错. 0 表示没问题
			int event_result = tn->task_sm_table[j].eventActFun(tn);
            if (event_result)
            {
                serverLog(LL_ERROR, "%d step error", j);
                error = 1;
                break;
            }
            else
            {
                current_state = tn->task_sm_table[j].next_state;
            }
		}
    }
    if (error)
    {
        serverLog(LL_NOTICE, "unlock error");
        return error;
    }

    // saveTaskData(tn);
   
    bleReleaseBleResult(ble_data);
    free(ble_data);
    ble_data = NULL;
    free(tn);
    tn = NULL;
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
      serverLog(LL_NOTICE, "%s <device_address> <admin_key> <passwd> \n", argv[0]);
      return 1;
    }
    serverLog(LL_NOTICE,"test ble unlock ing to start.");
    
    serverLog(LL_NOTICE,"select the lock you want to unlock.");
    igm_lock_t lock;
    initLock(&lock);
    setLockAddr(&lock, argv[1], strlen(argv[1]));
    serverLog(LL_NOTICE, "setLockAddr success");

    uint8_t tmp_buff[100];
    memset(tmp_buff, 0, sizeof(tmp_buff));
    int admin_len = hexStrToByte(argv[2], tmp_buff, strlen(argv[2]));
    setLockKey(&lock, tmp_buff, admin_len);
    serverLog(LL_NOTICE, "setLockAdminKey success");

    memset(tmp_buff, 0, sizeof(tmp_buff));
    int password_size = hexStrToByte(argv[3], tmp_buff, strlen(argv[3]));
    setLockPassword(&lock, tmp_buff, password_size);
    serverLog(LL_NOTICE, "setLockPassword success");

    serverLog(LL_NOTICE, "multi unlock cmd test go");
    int n_test = 200;
    int res;
    while (n_test)
    {
        serverLog(LL_NOTICE, "multi unlock cmd %d th test", n_test);
        res = testUnLock(&lock);
        n_test--;
    }
    return res;
}

