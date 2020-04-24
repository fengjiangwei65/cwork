
#include <stdio.h>
#include <stdlib.h>
#include "task_queue.h"


int main() {

    LIST_HEAD(task_head);
    INIT_LIST_HEAD(&task_head);


    InsertTask(&task_head, 1, 10, NULL, NULL);
    InsertTask(&task_head, 2, 9, NULL, NULL);
    InsertTask(&task_head, 3, 8, NULL, NULL);
    InsertTask(&task_head, 4, 7, NULL, NULL);
    InsertTask(&task_head, 5, 6, NULL, NULL);
    InsertTask(&task_head, 6, 5, NULL, NULL);

    printf("task_head.prev:%x.\n", task_head.prev);
    task_node_t *ptn=NULL;
    list_head_t* po=&task_head;
    for(; po!=NULL; po=&ptn->list) { 
        ptn=NextTask(po, &task_head);
        if (NULL!=ptn)
            printf("task_node.msg_id[%u], current_state[%d].\n", ptn->msg_id, ptn->current_state);
    }

    for(int i=0; i<20; i++) {
        ptn = FindTaskByMsgID(i, &task_head);
        if (NULL!=ptn)
            printf("find task_node.msg_id[%u], current_state[%d].\n", ptn->msg_id, ptn->current_state);
        else
            printf("find ptn==NULL.\n");
    }
    
    int rc = DeleteTaskByMsgID(4, &task_head);
    printf("delete node msg_id=4, result[%d].\n", rc);
    ptn = FindTaskByMsgID(4, &task_head);
    if (NULL!=ptn)
        printf("find task_node.msg_id[%u], current_state[%d].\n", ptn->msg_id, ptn->current_state);
    else
        printf("find ptn==NULL.\n");

    for(po=&task_head, ptn=NULL; po!=NULL; po=&ptn->list) { 
        ptn=NextTask(po, &task_head);
        if (NULL!=ptn)
            printf("task_node.msg_id[%u], current_state[%d].\n", ptn->msg_id, ptn->current_state);
    }

    rc = DeleteTaskByMsgID(14, &task_head);
    printf("delete node msg_id=14, result[%d].\n", rc);
 


    return 0;
}

