// 查找
#include <stdio.h>
#include "clinked_list.h"

int Count(LinkNode *list, ElemType e) {
    int i = 0;
    LinkNode * p = list->next;
    while (p != list) {
        if (e == p->data) {
            i++;
        }
        p = p->next;
    }
    return i;
}

int main() {
    int a[] = {3, 1, 4, 9, 8, 11, 9};
    int n = sizeof(a) / sizeof(a[0]);

    // 创建循环单链表
    LinkNode *list = nullptr;
    CreateCLinkedListR(list, a, n);
    printf("ListEmpty: %d\n", ListEmpty(list));
    printf("ListLength: %d\n", ListLength(list));
    printf("init_disp:");
    DispList(list);

    ElemType e = 12;
    int count = Count(list, e);
    printf("count:%d\n", count);

    return 0;
}