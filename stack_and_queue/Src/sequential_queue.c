#include <malloc.h>
#include "../Inc/sequential_queue.h"

Status InitQueue(SqQueue *Q) {
    Q->base = (QElemType *) malloc(sizeof(QElemType) * MAXQSIZE);
    if (!Q->base) exit(OVERFLOW);
    Q->front = Q->rear;
    return OK;
}

int QueueLength(SqQueue Q) {
    return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

Status EnQueue(SqQueue *Q, int e) {
    if ((Q->rear + 1) % MAXQSIZE == Q->front)
        return ERROR;
    Q->base[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXQSIZE;
    return OK;
}

Status DeQueue(SqQueue *Q, int *e) {
    if (Q->front == Q->rear) return ERROR;
    *e = Q->base[Q->front];
    Q->front = (Q->front + 1) % MAXQSIZE;
    return OK;
}

QElemType GetHead(SqQueue Q) {
    if (Q.front != Q.rear)
        return Q.base[Q.front];
    return ERROR;
}
