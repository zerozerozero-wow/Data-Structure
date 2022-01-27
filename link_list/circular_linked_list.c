/**
 * 循环链表的实现和基本操作
 * @date    2022-1-27
 */

#include <stdio.h>
#include <malloc.h>

#define OK          1
#define ERROR       0
#define OVERFLOW    -2
typedef int Status;

/* 数据域的数据元素定义 */
typedef char ElemType;

/* 结点结构体定义 */
typedef struct LNode{
    ElemType data;          //结点数据域
    struct LNode *next;     //结点指针域
}LNode, *LinkList;          //LinkList为指向结构体LNode的指针类型

