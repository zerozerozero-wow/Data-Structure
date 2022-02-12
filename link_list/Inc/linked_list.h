/**
 * @file    linked_list.h
 * @brief   单链表的实现和基本操作
 * @date    2022-2-7
 */

#ifndef LINK_LIST_LINKED_LIST_H
#define LINK_LIST_LINKED_LIST_H

#include <stdio.h>
#include <malloc.h>

#define OK          1
#define ERROR       0
#define OVERFLOW    -2
typedef int Status;

/* 数据域的数据元素定义 */
typedef char ElemType;

/* 结点结构体定义 */
typedef struct LNode {
    ElemType data;          //结点数据域
    struct LNode *next;     //结点指针域
} LNode, *LinkList;         //LinkList为指向结构体LNode的指针类型

Status InitList(LinkList *L);
Status GetElem(LinkList L, int i, ElemType *e);
LNode *LocateElem(LinkList L, ElemType e);
Status ListInsert(LinkList L, int i, ElemType e);
Status ListDelete(LinkList L, int i);
void CreateList_H(LinkList *L, int n);
void CreateList_R(LinkList *L, int n);
Status sll_insert(register LNode **L, ElemType new_value);
int ListLength(LinkList L);
void MergeList(LinkList LA, LinkList LB);
void MergeList_L(LinkList LA, LinkList LB, LinkList *LC);
void TraverseList(LinkList p);

#endif
