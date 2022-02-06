/**
 * 单链表的实现和基本操作
 * @date    2022-1-21
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
typedef struct LNode {
    ElemType data;          //结点数据域
    struct LNode *next;     //结点指针域
} LNode, *LinkList;         //LinkList为指向结构体LNode的指针类型

/**
 * @brief 1.单链表的初始化
 * @details 构造一个空的单链表L
 * @details 使用方法：InitList(&L);
 * @param L 头指针的指针
 * @retval OK 成功
 * @note 2022/2/6已验证
 */
Status InitList(LinkList *L) {
    *L = (LNode *) malloc(sizeof(LNode));      //生成新结点作为头结点，用头指针L指向头结点
    (*L)->next = NULL;                              //头结点指针域置空
    return OK;
}

/**
 * @brief 2.单链表的取值
 * @details 在带头结点的单链表L中根据序号i获取元素的值，用e返回L中第i个数据元素的值
 * @param L 头指针
 * @param i 位置序号
 * @param e 取出值
 * @retval  ERROR i值不合法
 * @retval  OK 成功
 */
Status GetElem(LinkList L, int i, ElemType *e) {
    /* 初始化，p指向首元结点，计数器j初值赋值为1 */
    LNode *p = L->next;
    int j = 1;

    while (p && j < i)     //顺链域向后扫描，直到p为空或p指向第i个元素
    {
        p = p->next;    //p指向下一个结点
        ++j;            //计数器j相应加1
    }
    if (!p || j > i) return ERROR; //i值不合法
    *e = p->data;        //取第i个结点的数据域
    return OK;
}

/**
 * @brief 3.单链表的按值查找
 * @param L 头指针
 * @param e 查找值
 * @return 查找成功返回值为e的结点地址p，查找失败p为NULL
 */
LNode *LocateElem(LinkList L, ElemType e) {
    /* 初始化，p指向首元结点 */
    LNode *p = L->next;

    while (p && p->data != e)        //顺链域向后扫描，直到p为空或p所指结点的数据域等于e
        p = p->next;                //p指向下一个结点
    return p;                       //查找成功返回值为e的结点地址p，查找失败p为NULL
}

/**
 * @brief 4.单链表的插入
 * @details 在带头结点的单链表L中第i个位置插入值为e的新结点
 * @param L 头指针
 * @param i 插入的位置序号
 * @param e 插入的数据
 * @return 成功返回OK
 */
Status ListInsert(LinkList L, int i, ElemType e) {
    LNode *p = L;
    int j = 0;

    /* 查找第i-1个结点，p指向该结点 */
    while (p && (j < i - 1)) {
        p = p->next;
        ++j;
    }
    /* i>n+1 或 i<1 */
    if (!p || j > i - 1) return ERROR;

    LNode *s = (LNode *) malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

/**
 * @brief 5.单链表的删除
 * @details 在带头结点的单链表L中，删除第i个元素
 * @param L 头指针
 * @param i 位置序号
 * @return 删除位置不合理返回ERROR，成功返回OK
 */
Status ListDelete(LinkList L, int i) {
    LNode *p = L;
    int j = 0;

    /* 查找第i-1个结点，p指向该结点 */
    while ((p->next) && (j < i - 1)) {
        p = p->next;
        ++j;
    }

    /* 当i>n或i<1时，删除位置不合理 */
    if (!(p->next) || (j > i - 1)) return ERROR;

    /* 临时保存被删结点的地址以备释放 */
    LNode *q = p->next;
    p->next = q->next;
    free(q);
    return OK;
}

/**
 * @brief 前插法创建单链表
 * @details HOW TO USE : CreateList_H(&L, 结点个数);
 * @param L 头指针的指针
 * @param n 元素个数
 * @note 2022/2/6已验证
 */
void CreateList_H(LinkList *L, int n) {
    /* 这两行等价于初始化单链表，即创建一个空的单链表L */
    *L = (LinkList) malloc(sizeof(LNode));
    (*L)->next = NULL;

    for (int i = 0; i < n; ++i) {
        LNode *p = (LNode *) malloc(sizeof(LNode));
        printf("Please enter a char\n");
        scanf(" %c",&p->data);        //输入元素值赋给新结点*p的数据域
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

/**
 * @brief 后插法创建单链表
 * @details HOW TO USE : CreateList_R(&L, 结点个数);
 * @param L 头结点
 * @param n 元素个数
 * @note 2022/2/6已验证
 */
void CreateList_R(LinkList *L, int n) {
    *L = (LinkList) malloc(sizeof(LNode));
    (*L)->next = NULL;

    LNode *r = *L;       //尾指针r指向头结点
    for (int i = 0; i < n; ++i) {
        LNode *p = (LNode *) malloc(sizeof(LNode));
        printf("Please enter a char\n");
        scanf(" %c",&p->data);        //输入元素值赋给新结点*p的数据域
        p->next = NULL;
        r->next = p;
        r = p;
    }
}

/**
 * @brief 插入到一个有序单链表。
 * @param L 指向头指针的指针
 * @param new_value 要插入的值
 * @return 成功返回OK，失败返回ERROR
 */
Status sll_insert(register LNode **L, ElemType new_value) {
    register LNode *current;
    register LNode *new;

    /**
     * 寻找正确的插入位置，方法是按序访问链表，直到到达一个其值大于或等于
     * 新值的结点
     */
    while ((current = *L) != NULL && current->data < new_value) {
        L = &current->next;
    }

    /**
     * 为新结点分配内存，并把新值存储到新结点中，如果内存分配失败，函数返回ERROR
     */
    new = (LNode *) malloc(sizeof(LNode));
    if (new == NULL)
        return ERROR;
    new->data = new_value;

    /**
     * 在链表中插入新结点，并返回OK
     */
    new->next = current;
    *L = new;
    return OK;
}

int main() {
    /* 初始化单链表 */
    LinkList L = NULL;
    InitList(&L);

    /* 前/后插法创建单链表 */
    CreateList_R(&L,5);


    return 0;
}
