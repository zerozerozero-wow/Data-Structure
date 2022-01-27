/**
 * 双向链表
 * @date    2022-1-27
 */

#include <malloc.h>

#define OK          1
#define ERROR       0
#define OVERFLOW    -2
typedef int Status;

typedef char ElemType;

/* 双向链表的存储结构 */
typedef struct DuLNode{
    ElemType data;      //数据域
    struct DuLNode *prior;      //直接前驱
    struct DuLNode *next;       //直接后继
}DuLNode, *DuLinkList;

/**
 * 在双向链表中，有些操作（如 ListLength, GetElem, LocateElem等）仅需涉及一个方向的
 * 指针，则它们的算法描述和线性链表的操作相同，但在插入、删除时有很大的不同，在双向链表中需
 * 同时修改两个方向上的指针，在插入结点时需要修改四个指针，在删除结点时需要修改两个指针。
 */

DuLNode *GetElem_Dul(DuLinkList L, int i);

/* 双向链表的插入 */
Status ListInsert_DuL(DuLinkList L, int i, ElemType e)
{
    /* 在带头结点的双向链表L中第i个位置之前插入元素e */
    DuLNode* p;
    if(!(p=GetElem_Dul(L, i)))      //在L中确定第i个元素的位置指针p
        return ERROR;               //p为NULL时，第i个元素不存在
    DuLNode *s = (DuLNode*)malloc(sizeof(DuLNode));     //生成新结点*s
    s->data = e;            //将结点*s数据域置为e
    s->prior = p->prior;    //将结点*s插入L中
    p->prior->next = s;
    s->next = p;
    p->prior = s;
    return OK;
}

/* 双向链表的删除 */
Status ListDelete_DuL(DuLinkList L, int i)
{
    /* 删除带头结点的双向链表L中的第i个元素 */
    DuLNode *p;
    if(!(p= GetElem_Dul(L, i)))
        return ERROR;
    p->prior->next = p->next;
    p->next->prior = p->prior;

    free(p);
    return OK;
}