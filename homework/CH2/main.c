/**
 * @author
 *
 *
 *         /#########       /##      /##      /#########
 *        |____ ##__/      | ##     | ##     | ##___   ##
 *            | ##         | ###########     | ##   \  ##
 *            | ##         | ##______ ##     | #########
 *         /##  ##         | ##     | ##     | ##______/
 *        |  #####         | ##     | ##     | ##
 *         \____/          |__/     |__/     |__/
 */

//#define MY_ANSWERS
#define ANSWERS

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
 *      Status intersectList(LinkList A, LinkList B);
 * 4.已知两个链表A和B分别表示两个集合，其元素递增排列。请设计算法求出两个集合A和B的差集（
 * 即仅由在A中出现而不在B中出现的元素所构成的集合），并以同样的形式存储，同时返回该集合的元素
 * 个数。
 *      int differenceList(LinkList A, LinkList B, LinkList C);
 * 5.设计算法将一个带头结点的单链表A分解为两个具有相同结构的链表B和C，其中B表的结点为A中
 * 值小于零的结点，而C表中的结点为A表中值大于零的结点（链表A中的元素为非零整数，要求B、C表
 * 利用A表的结点
 *      Status decomposeList(LinkList A, LinkList B, LinkList C);
 * 6.设计一个算法，通过一趟遍历确定长度为n的单链表中值最大的结点
 *      int locateMaxNode(LinkList A);
 * 7.设计一个算法，将链表中所有结点的链接方向“原地”逆转，即要求仅利用原表的存储空间，换句话
 * 说，要求算法的空间复杂度为O(1)
 *      Status changeDirection(LinkList A);
 * 8.设计一个算法，删除递增有序链表中值大于 mink 且小于 maxk 的所有元素（mink 和 maxk 是
 * 给定的两个参数，其值可以和表中的元素相同，也可以不同）
 *      Status limitList(LinkList A, ElemType mink, ElemType maxk);
 * 9.已知 p 指向双向循环链表中的一个结点，其结点结构为 data、prior、next 三个域，写出算法
 * change(p)，交换 p 所指向的结点及其前驱节点的顺序
 *
 * 10.已知长度为n的线性表A采用顺序存储结构，请写一个时间复杂度为O（n）、空间复杂度为O（1）的
 * 算法，该算法可删除线性表中所有值为 item 的数据元素
 *
 */
#ifdef MY_ANSWERS
Status mergeList1(LinkList A, LinkList B);
Status mergeList2(LinkList A, LinkList B);
Status intersectList(LinkList A, LinkList B);
int differenceList(LinkList A, LinkList B, LinkList C);
#endif

#ifdef ANSWERS

void mergeList1(LinkList La, LinkList Lb, LinkList *Lc);

void mergeList2(LinkList La, LinkList Lb, LinkList *Lc);

void mixList(LinkList La, LinkList Lb, LinkList *Lc);

void differenceList(LinkList La, LinkList Lb, int *n);

void discomposeList(LinkList A, LinkList *B, LinkList *C);

ElemType maxNodeInList(LinkList L);

void inverseList(LinkList L);

void limitList(LinkList L, int mink, int maxk);

void deleteItem(ElemType A[], int n, ElemType item);

#endif

int main() {
    int aTest[] = {1, 3, 5, 7, 9};
    int bTest[] = {3, 4, 8, 9, 10};

    LinkList A = (LNode *) malloc(sizeof(LNode));
    A->next = NULL;
    LinkList B = (LNode *) malloc(sizeof(LNode));
    B->next = NULL;
    LinkList C = (LNode *) malloc(sizeof(LNode));
    C->next = NULL;

    LNode *aTail = A;
    LNode *bTail = B;

    for (int i = 0; i < 5; i++) {
        LNode *p = (LNode *) malloc(sizeof(LNode));
        LNode *q = (LNode *) malloc(sizeof(LNode));

        p->data = aTest[i];
        p->next = NULL;
        q->data = bTest[i];
        q->next = NULL;

        aTail->next = p;
        bTail->next = q;

        aTail = p;
        bTail = q;
    }

    /* TEST FUNCTION */
    int n;
    differenceList(A, B, &n);

    return 0;
}

#ifdef MY_ANSWERS

/**
 * @brief 1.将两个递增的有序链表合并为一个递增的有序链表。要求结果链表仍使用原来两个链表的存储空间，
 * 不另外占用其他的存储空间。表中不允许有重复的数据。
 * @param A 链表A的头指针
 * @param B 链表B的头指针
 * @return OK成功
 * @note 2022/2/8测试通过
 * @note 测试数据：
 *          int aTest[] = {1, 3, 5, 7, 9};
 *          int bTest[] = {2, 4, 5, 8, 10};
 */
Status mergeList1(LinkList A, LinkList B) {
    /* pa and pb point to the head node of A and
     * the initial node of B respectively
     */
    LNode *pa = A;
    LNode *pb = B->next;

    /* insert the nodes in B into A */
    while (pb) {     //when pb is not empty
        //the order of the two conditions cannot be exchanged
        while ((pa->next != NULL) && (pb->data > pa->next->data)) {
            pa = pa->next;
        };

        if (pa->next == NULL) {
            pa->next = pb;
            break;
        }

        if (pb->data == pa->next->data) {
            pb = pb->next;
            continue;
        }
        /* insert the nodes into A */
        LNode *pb_next = pb->next;
        pb->next = pa->next;
        pa->next = pb;
        pb = pb_next;
    }

    return OK;
}

/**
 * @brief 2.将两个非递减的有序链表合并为一个非递增的有序链表。要求结果链表仍使用原来两个链表的存储空
 * 间，不另外占用其他的存储空间。表中允许有重复的数据。
 * @param A A链表头指针
 * @param B B链表头指针
 * @return OK 成功
 * @note 测试数据：
 *           int aTest[] = {1, 3, 3, 7, 9};
 *           int bTest[] = {3, 4, 8, 8, 10};
 * @note 合并后：10,9,8,8,7,4,3,3,3,1
 */
Status mergeList2(LinkList A, LinkList B) {
    /* pa and pb point to the head node of A and
     * the initial node of B respectively
     */
    LNode *pa = A;
    LNode *pb = B->next;

    /* insert the nodes in B into A */
    while (pb) {     //when pb is not empty
        //the order of the two conditions cannot be exchanged
        while ((pa->next != NULL) && (pb->data > pa->next->data)) {
            pa = pa->next;
        };

        if (pa->next == NULL) {
            pa->next = pb;
            break;
        }

        /* insert the nodes into A */
        LNode *pb_next = pb->next;
        pb->next = pa->next;
        pa->next = pb;
        pb = pb_next;
    }

    /* reverse the linked list A */
    pa = A->next;
    LNode *pa_next = pa->next;
    LNode *pa_next_next = pa->next->next;
    while(pa_next_next->next){
        /* change the direction */
        pa_next->next = pa;
        /* pointers move on */
        pa = pa_next;
        pa_next = pa_next_next;
        pa_next_next = pa_next_next->next;
    }
    pa_next->next = pa;
    pa_next_next->next = pa_next;
    A->next->next = NULL;
    A->next = pa_next_next;

    return OK;
}

/**
 * @brief 3.已知两个链表A和B分别表示两个集合，其元素递增排列。请设计一个算法，用于求出A与B的交集，
 * 并存放在A链表中。
 * @param A
 * @param B
 * @return
 * @note 测试数据：
 *          int aTest[] = {1, 3, 5, 8, 10};
 *          int bTest[] = {0, 5, 8, 10, 13};
 * @note 输出：5, 8, 10
 */
Status intersectList(LinkList A, LinkList B) {
    LNode *pa = A;          //point to the head node
    LNode *pb = B->next;    //point to the initial node

    while(pa->next){
        while(pb){
            if(pa->next->data == pb->data){
                pa = pa->next;
                break;
            }
            pb = pb->next;
        }

        if(!pb)     //if not find in B
            pa->next = pa->next->next;
        pb=B->next; //reset the pb
    }
    return OK;
}

/**
 * @brief 4.已知两个链表A和B分别表示两个集合，其元素递增排列。请设计算法求出两个集合A和B的差集（
 * 即仅由在A中出现而不在B中出现的元素所构成的集合），并以同样的形式存储，同时返回该集合的元素
 * 个数。
 * @param A 链表A的头指针
 * @param B 链表B的头指针
 * @param C 将要存放结果的链表的头指针
 * @return 结果集合的元素的个数
 * @note 测试数据：
 * @note    int aTest[] = {0, 3, 5, 8, 9};
 *          int bTest[] = {3, 5, 9, 10, 13};
 * @note 返回：{0, 8},2
 */
int differenceList(LinkList A, LinkList B, LinkList C) {
    LNode *pa = A->next;
    LNode *pb = B->next;
    LNode *pc = C;
    int num = 0;

    pos1:
    while(pa){
        while (pb){
            if(pa->data == pb->data){
                pb = B->next;
                pa = pa->next;
                goto pos1;
            }
            pb = pb->next;
        }
        pb = B->next;
        pc->next = (LNode *) malloc(sizeof(LNode));
        pc->next->next = NULL;
        pc->next->data = pa->data;
        pc = pc->next;
        num++;
        pa = pa->next;
    }
    return num;
};

#endif


/* answers */
#ifdef ANSWERS

void mergeList1(LinkList La, LinkList Lb, LinkList *Lc) {
    LNode *pa = La->next;
    LNode *pb = Lb->next;
    *Lc = La;
    LNode *pc = *Lc;

    while (pa && pb) {
        if (pa->data < pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        } else if (pa->data > pb->data) {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        } else {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
            LNode *q = pb->next;
            free(pb);
            pb = q;
        }
    }
    pc->next = pa ? pa : pb;
    free(Lb);
}

void mergeList2(LinkList La, LinkList Lb, LinkList *Lc) {
    LNode *pa = La->next;
    LNode *pb = Lb->next;
    *Lc = La;
    LNode *pc = *Lc;

    (*Lc)->next = NULL;
    while (pa || pb) {
        LNode *q = NULL;
        if (!pa) {
            q = pb;
            pb = pb->next;
        } else if (!pb) {
            q = pa;
            pa = pa->next;
        } else if (pa->data <= pb->data) {
            q = pa;
            pa = pa->next;
        } else {
            q = pb;
            pb = pb->next;
        }
        q->next = (*Lc)->next;
        (*Lc)->next = q;
    }
    free(Lb);
}

void mixList(LinkList La, LinkList Lb, LinkList *Lc) {
    LNode *pa = La->next;
    LNode *pb = Lb->next;
    *Lc = La;
    LNode *pc = *Lc;
    LNode *u = NULL;
    while (pa && pb) {
        if (pa->data == pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
            u = pb;
            pb = pb->next;
            free(u);
        } else if (pa->data < pb->data) {
            u = pa;
            pa = pa->next;
            free(u);
        } else {
            u = pb;
            pb = pb->next;
            free(u);
        }
    }
    while (pa) {
        u = pa;
        pa = pa->next;
        free(u);
    }
    while (pb) {
        u = pb;
        pb = pb->next;
        free(u);
    }
    pc->next = NULL;
    free(Lb);
}

void differenceList(LinkList La, LinkList Lb, int *n) {
    LNode *pa = La->next;
    LNode *pb = Lb->next;
    LNode *pre = La;
    while (pa && pb) {
        if (pa->data < pb->data) {
            pre = pa;
            pa = pa->next;
            (*n)++;
        } else if (pa->data > pb->data) {
            pb = pb->next;
        } else {
            pre->next = pa->next;
            LNode *u = pa;
            pa = pa->next;
            free(u);
        }
    }
}

void discomposeList(LinkList A, LinkList *B, LinkList *C) {
    LNode *p = A->next;
    *B = A;
    (*B)->next = NULL;
    (*C)->next = NULL;

    while (p != NULL) {
        LNode *r = p->next;
        if (p->data < 0) {
            p->next = (*B)->next;
            (*B)->next = p;
        } else {
            p->next = (*C)->next;
            (*C)->next = p;
        }
        p = r;
    }
}

ElemType maxNodeInList(LinkList L) {
    if (L->next == NULL)return ERROR;
    LNode *pmax = L->next;
    LNode *p = L->next->next;
    while (p != NULL) {
        if (p->data > pmax->data)
            pmax = p;
        p = p->next;
    }
    return pmax->data;
}

void inverseList(LinkList L) {
    LNode *p = L->next;
    L->next = NULL;

    LNode *q = NULL;
    while (p) {
        q = p->next;
        p->next = L->next;
        L->next = p;
        p = q;
    }
}

void limitList(LinkList L, int mink, int maxk) {
    LNode *p = L->next;
    LNode *q = NULL;
    LNode *pre = NULL;
    while (p && p->data <= mink) {
        pre = p;
        p = p->next;
    }
    if (p) {
        while (p && p->data < maxk)
            p = p->next;
        q = pre->next;
        pre->next = p;
        while (q != p) {
            LNode *s = q->next;
            free(q);
            q = s;
        }
    }
}

/**
 * answer9
 * void change(p){
 *      q=p->llink;
 *      q->llink->rlink=p;      //p的前驱的前驱之后继为p
 *      p->llink=q->llink;      //p的前驱指向其前驱的前驱
 *      q->rlink=p->rlink;      //p的前驱的后继为p的后继
 *      q->llink=p;             //p与其前驱交换
 *      p->rlink->llink=q;      //p的后继的前驱指向原p的前驱
 *      p->rlink=q;             //p的后继指向其原来的前驱
 * }
 */

void deleteItem(ElemType *A, int n, ElemType item) {
    int i = 1, j = n;
    while (i < j) {
        while (i < j && A[i] != item)
            i++;
        if (i < j) {
            while (i < j && A[j] == item)
                j--;
        }
        if (i < j) A[i++] = A[j--];
    }
}

#endif
