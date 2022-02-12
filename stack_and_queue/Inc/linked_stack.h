#ifndef STACK_AND_QUEUE_LINKED_STACK_H
#define STACK_AND_QUEUE_LINKED_STACK_H

#define Status int
#define OK 1
#define OVERFLOW -1
#define ERROR 0

/* 链栈的存储结构 */
#define SElemType int
typedef struct StackNode{
    SElemType data;
    struct StackNode *next;
}StackNode,*LinkStack;

/* 链栈的实现 */
Status InitStack(LinkStack *S);
Status Push(LinkStack *S, SElemType e);
Status Pop(LinkStack *S, SElemType *e);
SElemType GetTop(LinkStack S);

#endif //STACK_AND_QUEUE_LINKED_STACK_H
