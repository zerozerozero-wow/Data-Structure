#ifndef STACK_AND_QUEUE_SEQUENTIAL_STACK_H
#define STACK_AND_QUEUE_SEQUENTIAL_STACK_H

/* 顺序栈的存储结构 */
#define Status int
#define OK 1
#define SElemType int
#define MAXSIZE 100         //顺序栈存储空间的初始分配量
typedef struct {
    SElemType *base;        //栈底指针
    SElemType *top;         //栈顶指针
    int stacksize;          //栈可用的最大容量
} SqStack;

/* 顺序栈的实现 */
Status InitStack(SqStack *S);

Status Push(SqStack *S, SElemType e);

Status Pop(SqStack *S, SElemType *e);

SElemType GetTop(SqStack S);

#endif
