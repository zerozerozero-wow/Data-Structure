#include <malloc.h>
#include "../Inc/sequential_stack.h"

Status InitStack(SqStack *S) {
    S->base = (SElemType *) malloc(sizeof(SElemType) * MAXSIZE);
    if (!S->base)return OVERFLOW;
    S->top = S->base;
    S->stacksize = MAXSIZE;
    return OK;
}

Status Push(SqStack *S, int e) {
    if (S->top - S->base == S->stacksize) return ERROR;
    *S->top++ = e;
    return OK;
}

Status Pop(SqStack *S, int *e) {
    if (S->top == S->base) return ERROR;
    *e = *--S->top;
    return OK;
}

SElemType GetTop(SqStack S) {
    if (S.top != S.base)
        return *(S.top - 1);
}
