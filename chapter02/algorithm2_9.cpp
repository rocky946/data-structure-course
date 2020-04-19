#include <stdio.h>
#include "dlinked_list.h"

/**
 * 逆置双链表
 * @param list
 */
void Reverse(DLinkNode *&list) {
    // 构造只有头结点的双链表list
    DLinkNode *p = list->next;
    list->next = nullptr;

    DLinkNode *q = nullptr;
    while (nullptr != p) {
        // 头插法会修改p的next,用q暂存
        q = p->next;
        p->next = list->next;
        // 若list非空
        if (nullptr != list->next) {
            list->next->prior = p;
        }
        list->next = p;
        p->prior = list;

        // p重新指向后继结点
        p = q;
    }
}

int main() {
    int a[] = {3, 1, 4, 9, 8, 11};
    int n = sizeof(a) / sizeof(a[0]);

    // 创建双链表
    DLinkNode *list = nullptr;
    CreateDLinkedListR(list, a, n);
    printf("ListEmpty: %d\n", ListEmpty(list));
    printf("ListLength: %d\n", ListLength(list));
    DispList(list);

    printf("------------\n");

    Reverse(list);
    printf("ListEmpty: %d\n", ListEmpty(list));
    printf("ListLength: %d\n", ListLength(list));
    DispList(list);

    DestroyList(list);

    return 0;
}