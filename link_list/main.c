#include "Inc/linked_list.h"

int main() {
    /* 初始化单链表 */
    LinkList L = NULL;
    InitList(&L);

    /* 前/后插法创建单链表 */
    CreateList_R(&L,5);

    /* 单链表的取值 */
    ElemType e;
    GetElem(L,1,&e);
    printf("%c",e);

    /* 单链表的按值查找 */
    LNode *p = LocateElem(L,'a');

    /* 单链表的插入 */
    ListInsert(L,1,'t');
    GetElem(L,1,&e);
    printf("%c",e);

    /* 单链表的删除 */
    ListDelete(L,1);
    GetElem(L,1,&e);
    printf("%c",e);

    return 0;
}
