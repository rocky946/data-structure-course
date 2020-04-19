#include <stdio.h>
#include "ordered_array_list.h"

int main() {
    int a[5] = {1, 2, 5, 7, 9};
    int length = sizeof(a) / sizeof(a[0]);

    SqList *list = nullptr;

    CreateList(list, a, length);
    printf("ListLength: %d\n", ListLength(list));
    printf("ListEmpty: %d\n", ListEmpty(list));
    printf("init_disp:");
    DispList(list);

    ElemType e = 12;
    OrderedListInsert(list, e);
    printf("ListLength: %d\n", ListLength(list));
    printf("ordered_insert_disp:");
    DispList(list);

    DestroyList(list);
    return 0;
}