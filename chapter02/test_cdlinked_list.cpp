#include <stdio.h>
#include "cdlinked_list.h"

int main() {
    int a[] = {3, 1, 4, 9, 8, 11};
//    int a[] = {};
    int n = sizeof(a) / sizeof(a[0]);

    // 创建双链表
    DLinkNode *list = nullptr;
//    CreateCDLinkedListF(list, a, n);
    CreateCDLinkedListR(list, a, n);
    printf("ListEmpty: %d\n", ListEmpty(list));
    printf("ListLength: %d\n", ListLength(list));
    printf("init_disp:");
    DispList(list);

    int index = 1;
    ElemType e;
    int ret = GetElem(list, index,e );
    if (ret) {
        printf("GetElem, e(%d) = %d\n", index, e);
    }

    e = 6;
    ret = LocateElem(list, e);
    printf("LocateElem, e(%d) = %d \n", e, ret);

    index = 7;
    printf("ListInsert: 在第%d个位置上插入%d\n", index, e);
    ListInsert(list, index, e);
    printf("ListLength: %d\n", ListLength(list));
    printf("insert_disp:");
    DispList(list);

    index = 6;
    printf("ListDelete: 删除第%d个位置元素\n", index);
    ListDelete(list, index, e);
    printf("ListLength: %d\n", ListLength(list));
    printf("delete_disp:");
    DispList(list);

    DestroyList(list);

    return 0;
}