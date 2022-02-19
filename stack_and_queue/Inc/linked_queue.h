#ifndef STACK_AND_QUEUE_LINKED_QUEUE_H
#define STACK_AND_QUEUE_LINKED_QUEUE_H

#define Status int
#define OK  1
#define ERROR 0
#define QElemType int

typedef struct QNode {
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct {
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;

Status InitQueue(LinkQueue *Q);

Status EnQueue(LinkQueue *Q, QElemType e);

Status DeQueue(LinkQueue *Q, QElemType *e);

QElemType GetHead(LinkQueue Q);

#endif //STACK_AND_QUEUE_LINKED_QUEUE_H
