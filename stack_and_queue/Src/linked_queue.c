#include <malloc.h>
#include "../Inc/linked_queue.h"

Status InitQueue(LinkQueue *Q) {
    Q->front=Q->rear=(QNode *)malloc(sizeof(QNode));
    Q->front->next = NULL;
    return OK;
}

Status EnQueue(LinkQueue *Q, int e) {
    QNode *p = (QNode*) malloc(sizeof(QNode));
    p->data = e;
    p->next = NULL;
    Q->rear->next=p;
    Q->rear=p;
    return OK;
}

Status DeQueue(LinkQueue *Q, int *e) {
    if(Q->front==Q->rear) return ERROR;
    QNode *p = Q->front->next;
    *e=p->data;
    Q->front->next=p->next;
    if(Q->rear==p) Q->rear=Q->front;
    free(p);
    return OK;
}

QElemType GetHead(LinkQueue Q) {
    if(Q.front!=Q.rear)
        return Q.front->next->data;
    return ERROR;
}
