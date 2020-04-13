#include <stdio.h>
#include <unistd.h>  //linux

enum
{
    DONE,
	CMD_INIT,
    INITED,
	CMD_REQ_USERINFO,
    CMD_UPDATE_USERINFO,
    CMD_CONNECT_LOCK,
    CMD_UPDATE_LOCKSTATUS,
    CMD_UNLOCK,
};


FsmTable_t IgnSMTable[] =
{
	{  CMD_REQ_USERINFO,        GetUserInfo,        CMD_UPDATE_USERINFO},
	{  CMD_UPDATE_USERINFO,     DealUserInfo,       CMD_CONNECT_LOCK},
    {  CMD_CONNECT_LOCK,        ScanLock,           CMD_UPDATE_LOCKSTATUS},
    {  CMD_UPDATE_LOCKSTATUS,   UpdateLockState,    DONE},
	{  CMD_UNLOCK,              UnLock,             CMD_UPDATE_LOCKSTATUS},

};

typedef struct FsmTable_s
{
	//int event;
	int CurState;
	void (*eventActFun)();
	int NextState;
}FsmTable_t;


typedef struct FSM_s
{
	FsmTable_t* FsmTable;
	int curState;
}FSM_t;

int g_max_num;  //״̬���ﺬ�е�״̬����


void GetUserInfo()
{
	//send request to server to get userinfo
	printf("send request to server to get userinfo!\n");
}

void DealUserInfo()
{
	//Recv UserInfo from server 
	printf("recv userinfo from server!\n");
}

void ScanLock()
{
	//Scan and connect with locks
	printf("scan & connect with locks!\n");
}

void UpdateLockState()
{
	//update lock status to server
	printf("update lock status to server!\n");
}

void UnLock()
{
	//unlock
	printf("unlock!\n");
}

/*״̬��ע��*/
void FSM_Regist(FSM_t* pFsm, FsmTable_t* pTable)
{
	pFsm->FsmTable = pTable;
}

/*״̬Ǩ��*/
void FSM_StateTransfer(FSM_t* pFsm, int state)
{
	pFsm->curState = state;
}


/*�¼�����*/
void FSM_EventHandle(FSM_t* pFsm, int event)
{
	FsmTable_t* pActTable = pFsm->FsmTable;
	void (*eventActFun)() = NULL;  //����ָ���ʼ��Ϊ��
	int NextState;
	int CurState = pFsm->curState;
	int flag = 0; //��ʶ�Ƿ���������

	/*��ȡ��ǰ��������*/
	for (int i = 0; i<g_max_num; i++)
	{
		//���ҽ�����ǰ״̬������ָ�����¼����Ҳ�ִ����
		if (event == pActTable[i].event && CurState == pActTable[i].CurState)
		{
			flag = 1;
			eventActFun = pActTable[i].eventActFun;
			NextState = pActTable[i].NextState;
			break;
		}
	}


	if (flag) //�������������
	{
		/*����ִ��*/
		if (eventActFun)
		{
			eventActFun();
		}

		//��ת����һ��״̬
		FSM_StateTransfer(pFsm, NextState);
	}
	else
	{
		// do nothing
	}
}

//��ʼ��FSM
void InitFsm(FSM_t* pFsm)
{
	g_max_num = sizeof(XiaoMingTable) / sizeof(FsmTable_t);
	pFsm->curState = SLEEP;
	FSM_Regist(pFsm, XiaoMingTable);
}


//�����õ�
void test(int *event)
{
	if (*event == 3)
	{
		*event = 1;
	}
	else
	{
		(*event)++;
	}
	
}


int main()
{
	FSM_t fsm;
	InitFsm(&fsm);
	int event = EVENT1; 
	//С����һ��,�ܶ���ʼ��һ����һ�죬��������ͬ�Ļ
	while (1)
	{
		printf("event %d is coming...\n", event);
		FSM_EventHandle(&fsm, event);
		printf("fsm current state %d\n", fsm.curState);
		test(&event); 
		sleep(1);  //����1�룬����۲�
	}

	return 0;
}
