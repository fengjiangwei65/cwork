#ifndef _SYSINFO_H_
#define _SYSINFO_H_
#include <pthread.h>
#include <MQTTClient.h>

enum BLE_TASK {
    BLE_NONE_TASK = 0, // 没有任务
    BLE_DISCOVER_LOCK = 1, // 扫描锁
};

typedef struct SysInfo {
    int inited;
    MQTTClient mqtt_c;
    // 去除 这个mutex, 建议所有操作, 都写到相应的.c文件, 每次修改获取都自动加锁,
    // 以免某程序忘记加锁,减少出错
	//pthread_mutex_t* mutex;
    char wifi_ssid[128];
    char wifi_pswd[32];
    char user_id[64];
    char user_pswd[32];
    void* userinfo;
    char lock1_id[32];
    char lock2_id[32];
    char lock3_id[32];
    char lock4_id[32];
    char lock5_id[32];
    void* lock1info;
    void* lock2info;
    void* lock3info;
    void* lock4info;
    void* lock5info;    
}sysinfo_t;

// 操作都会使用互斥锁

int sysinfoInit(sysinfo_t *sysinfo);

#endif