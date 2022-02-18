#ifndef STACK_AND_QUEUE_SEQUENTIAL_QUEUE_H
#define STACK_AND_QUEUE_SEQUENTIAL_QUEUE_H


#define Status  int
#define OK      1
#define OVERFLOW -1
#define ERROR   0

#define MAXQSIZE    100
#define QElemType   int
typedef struct {
    QElemType *base;
    int front;
    int rear;
} SqQueue;

Status InitQueue(SqQueue *Q);

int QueueLength(SqQueue Q);

Status EnQueue(SqQueue *Q, QElemType e);

Status DeQueue(SqQueue *Q, QElemType *e);

QElemType GetHead(SqQueue Q);

#endif //STACK_AND_QUEUE_SEQUENTIAL_QUEUE_H
