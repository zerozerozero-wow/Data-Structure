/**
 * 线性表的顺序表示和实现
 * @date 2022.1.20
 */

#include <stdio.h>
#include <malloc.h>

/* 预定义常量及类型 */
#define OK          1
#define ERROR       0
#define OVERFLOW   -2
typedef int Status;

/* 数据元素类型 */
typedef char ElemType;

/* 顺序表的存储结构 */
#define MAXSIZE 100     //顺序表可能达到的最大长度
typedef struct {
    ElemType *elem;     //存储空间的基地址
    int length;         //当前长度
} SqList;

/* 顺序表中基本操作的实现 */
/**
 * @brief 1.初始化
 * @param L 为引用类型
 * @retval OK   成功
 * @note 动态分配线性表的存储区域可以更有效地利用系统地资源，当不需要该线性表时，可以使用销毁操作及时释放占用的存储空间
 */
Status InitList(SqList *L)
{
    /* 构造一个空的顺序表L */
    (*L).elem = (ElemType *)malloc(sizeof(ElemType)*MAXSIZE);   //为顺序表分配一个大小为MAXSIZE的数组空间
    if(!(*L).elem) exit(OVERFLOW);                 //存储分配失败退出
    (*L).length = 0;                                     //空表长度为0
    return OK;
}

/**
 * @brief 2.顺序表的取值
 * @param L 已经存在的一个线性表
 * @param i 需要取值的位置序号
 * @param e 取出值，为引用类型
 * @retval OK   成功
 */
Status GetElem(SqList L, int i, ElemType *e)
{
    if(i<1 || i>L.length) return ERROR;     //判断i值是否合理，若不合理，返回ERROR
    *e = L.elem[i-1];                       //elem[i-1]单元存储第i个数据元素
    return OK;
}

/**
 * @brief 3.顺序表的查找
 * @param L 已经存在的顺序表
 * @param e 需要查找的对象
 * @return 成功则返回序号，失败返回0
 */
int LocateElem(SqList L, ElemType e)
{
    for(int i=0;i<L.length;i++)
        if(L.elem[i] == e) return i+1;      //查找成功，返回序号i+1
    return 0;                               //查找失败，返回0
}

/**
 * @brief 4.顺序表的插入
 * @param L 已经存在的顺序表
 * @param i 插入位置（1<=i<=n+1）
 * @param e 要插入的新元素
 * @retval OK   成功
 */
Status ListInsert(SqList *L, int i, ElemType e)
{
    /* 在顺序表L中的第i个位置之前插入新的元素e，i值的合法范围是1<=i<=L.length+1 */
    if((i<1) || (i>(*L).length+1)) return ERROR;
    if((*L).length == MAXSIZE) return ERROR;
    for(int j=(*L).length-1;j>=i-1;j--)
        (*L).elem[j+1] = (*L).elem[j];
    (*L).elem[i-1] = e;
    ++(*L).length;
    return OK;
}

/**
 * @brief 5.顺序表的删除
 * @param L 一个存在的线性表
 * @param i 需要删除的元素位置
 * @retval OK   成功
 */
Status ListDelete(SqList *L, int i)
{
    /* 在顺序表L中删除第i个元素，i值的合法范围是1<=i<=L.length */
    if((i<1) || (i>(*L).length-1)) return ERROR;
    for(int j=i;j<=(*L).length-1;j++)
        (*L).elem[j-1] = (*L).elem[j];
    --(*L).length;
    return OK;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
