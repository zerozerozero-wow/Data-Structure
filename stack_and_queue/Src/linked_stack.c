#include "../Inc/linked_stack.h"
#include "malloc.h"

Status InitStack(LinkStack *S) {
    *S = NULL;
    return OK;
}

Status Push(LinkStack *S, int e) {
    StackNode *p = (StackNode *) malloc(sizeof(StackNode));
    p->data = e;
    p->next = *S;
    *S = p;
    return OK;
}

Status Pop(LinkStack *S, int *e) {
    if (*S == NULL) return ERROR;
    *e = (*S)->data;
    StackNode *p = *S;
    *S = (*S)->next;
    free(p);
    return OK;
}

SElemType GetTop(LinkStack S) {
    if (S != NULL)
        return S->data;
}
