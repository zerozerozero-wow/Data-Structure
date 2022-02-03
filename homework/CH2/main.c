#include <stdio.h>
#include <malloc.h>

typedef int ElemType;
typedef int Status;
#define OK  1
#define ERROR 0

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

/**
 * 算法设计题
 * 1.将两个递增的有序链表合并为一个递增的有序链表。要求结果链表仍使用原来两个链表的存储空间，
 * 不另外占用其他的存储空间。表中不允许有重复的数据。
 *      Status mergeList1(LinkList A, LinkList B);
 * 2.将两个非递减的有序链表合并为一个非递增的有序链表。要求结果链表仍使用原来两个链表的存储空
 * 间，不另外占用其他的存储空间。表中允许有重复的数据。
 *      Status mergeList2(LinkList A, LinkList B);
 * 3.已知两个链表A和B分别表示两个集合，其元素递增排列。请设计一个算法，用于求出A与B的交集，
 * 并存放在A链表中。
 *
 * 4.已知两个链表A和B分别表示两个集合，其元素递增排列。请设计算法求出两个集合A和B的差集（
 * 即仅由在A中出现而不在B中出现的元素所构成的集合），并以同样的形式存储，同时返回该集合的元素
 * 个数。
 *
 * 5.设计算法将一个带头结点的单链表A分解为两个具有相同结构的链表B和C，其中B表的结点为A中
 * 值小于零的结点，而C表中的结点为A表中值大于零的结点（链表A中的元素为非零整数，要求B、C表
 * 利用A表的结点
 *
 * 6.设计一个算法，通过一趟遍历确定长度为n的单链表中值最大的结点
 *
 * 7.设计一个算法，将链表中所有结点的链接方向“原地”逆转，即要求仅利用原表的存储空间，换句话
 * 说，要求算法的空间复杂度为O(1)
 *
 * 8.设计一个算法，删除递增有序链表中值大于 mink 且小于 maxk 的所有元素（mink 和 maxk 是
 * 给定的两个参数，其值可以和表中的元素相同，也可以不同）
 *
 * 9.已知 p 指向双向循环链表中的一个结点，其结点结构为 data、prior、next 三个域，写出算法
 * change(p)，交换 p 所指向的结点及其前驱节点的顺序
 *
 * 10.已知长度为n的线性表A采用顺序存储结构，请写一个时间复杂度为O（n）、空间复杂度为O（1）的
 * 算法，该算法可删除线性表中所有值为 item 的数据元素
 */

Status mergeList1(LinkList A, LinkList *B);

Status mergeList2(LinkList A, LinkList B);

int main() {
    int aTest[] = {1,3,5,7,9};
    int bTest[] = {2,4,5,8,10};

    for(int i=0;i<5;i++){
        LinkList A = (LNode *)malloc(sizeof(LNode));
        A->next = (LNode *)malloc(sizeof(LNode));
        A->next->data
    }

    return 0;
}

/**
 * @brief 1.将两个递增的有序链表合并为一个递增的有序链表。要求结果链表仍使用原来两个链表的存储空间，
 * 不另外占用其他的存储空间。表中不允许有重复的数据。
 * @param A 链表A的头指针
 * @param B 链表B的头指针
 * @return OK成功
 */
Status mergeList1(LinkList A, LinkList *B) {
    LNode *cp = A;
    LNode *max = (*B)->next;

    while(cp->next != NULL) {
        while(max->data >= cp->next->data){
            cp = cp->next;
        }
        if(max->data == cp->data) {
            max = max->next;
            continue;
        }
        *B = max->next;
        max->next = cp->next;
        cp->next = max;
        max = *B;
    }
    return OK;
};


