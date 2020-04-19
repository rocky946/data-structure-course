// 设计一个算法，判断带头结点的循环双链表(含两个以上的结点)中的数据结点是否对称
#include <stdio.h>
#include <malloc.h>
#include "cdlinked_list.h"

bool Symm(DLinkNode *list) {
    // 首指针
    DLinkNode *p = list->next;
    // 尾指针
    DLinkNode *q = list->prior;

    while (p != q && p->next != q) {
        if (p->data != q->data) {
            return false;
        }
        p = p->next;
        q = q->prior;
    }

    // 最后比较中间结点
    return p->data == q->data;
}

int main() {
    int a[] = {3, 1, 2, 1, 3};
    int n = sizeof(a) / sizeof(a[0]);

    // 创建双链表
    DLinkNode *list = nullptr;
    CreateCDLinkedListR(list, a, n);
    printf("ListEmpty: %d\n", ListEmpty(list));
    printf("ListLength: %d\n", ListLength(list));
    printf("init_disp:");
    DispList(list);

    bool ret = Symm(list);
    printf("Symm ret: %d\n", ret);

    DestroyList(list);

    return 0;
}