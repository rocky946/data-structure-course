#include <stdio.h>
#include "linked_list.h"

int main() {
    int a[] = {3, 1, 4, 9, 8, 11};
//    int a[] = {};
    int n = sizeof(a) / sizeof(a[0]);

    // 创建单链表
    LinkNode *list = nullptr;
//    CreateLinkedListF(list, a, n);
    CreateLinkedListR(list, a, n);
    printf("ListEmpty: %d\n", ListEmpty(list));
    printf("ListLength: %d\n", ListLength(list));
    DispList(list);

    ElemType e;
    int ret = GetElem(list, 9,e );
    if (ret) {
        printf("GetElem, e(3) = %d\n", e);
    }

    e = 20;
    ret = LocateElem(list, e);
    printf("LocateElem, e(%d) = %d \n", e, ret);

    ListInsert(list, 1, e);
    printf("ListLength: %d\n", ListLength(list));
    DispList(list);

    ListDelete(list, 6, e);
    printf("ListLength: %d\n", ListLength(list));
    DispList(list);

    DestroyList(list);

    return 0;
}