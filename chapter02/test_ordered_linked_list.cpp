#include <stdio.h>
#include "ordered_linked_list.h"

int main() {
    int a[] = {1, 3, 5, 7, 9};
    int n = sizeof(a) / sizeof(a[0]);

    // 创建单链表
    LinkNode *list = nullptr;
    CreateLinkedListR(list, a, n);
    printf("ListEmpty: %d\n", ListEmpty(list));
    printf("ListLength: %d\n", ListLength(list));

    printf("init_disp:");
    DispList(list);

    ElemType e = 0;
    OrderedListInsert(list, e);
    printf("ListLength: %d\n", ListLength(list));
    printf("ordered_insert_disp:");
    DispList(list);
    DestroyList(list);

    return 0;
}