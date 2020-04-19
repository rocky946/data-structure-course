#include <stdio.h>
#include "dlinked_list.h"

int main() {
    int a[] = {3, 1, 4, 9, 8, 11};
//    int a[] = {};
    int n = sizeof(a) / sizeof(a[0]);

    // 创建双链表
    DLinkNode *list = nullptr;
//    CreateDLinkedListF(list, a, n);
    CreateDLinkedListR(list, a, n);
    printf("ListEmpty: %d\n", ListEmpty(list));
    printf("ListLength: %d\n", ListLength(list));
    DispList(list);

    ElemType e;
    int ret = GetElem(list, 3,e );
    if (ret) {
        printf("GetElem, e(3) = %d\n", e);
    }

    e = 4;
    ret = LocateElem(list, e);
    printf("LocateElem, e(4) = %d \n", ret);

    ListInsert(list, 2, e);
    printf("ListLength: %d\n", ListLength(list));
    DispList(list);

    ListDelete(list, 6, e);
    printf("ListLength: %d\n", ListLength(list));
    DispList(list);

    DestroyList(list);

    return 0;
}