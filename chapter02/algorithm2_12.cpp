// 有一个带头结点的循环双链表L，设计一个算法删除第一个data域值为x的结点
#include <stdio.h>
#include <malloc.h>
#include "cdlinked_list.h"

bool DeleteElem(DLinkNode *&list, ElemType x) {
    DLinkNode *p = list->next;

    while (p != list) {
        if (x == p->data) {
            break;
        }
        p = p->next;
    }

    // 不存在值为e的结点
    if (p == list) {
        printf("不存在%d\n", x);
        return false;
    } else {
        // 删除p
        p->prior->next = p->next;
        p->next->prior = p->prior;
        free(p);
        return true;
    }
}

int main() {
    int a[] = {3, 1, 4, 9, 8, 11};
    int n = sizeof(a) / sizeof(a[0]);

    // 创建双链表
    DLinkNode *list = nullptr;
    CreateCDLinkedListR(list, a, n);
    printf("ListEmpty: %d\n", ListEmpty(list));
    printf("ListLength: %d\n", ListLength(list));
    printf("init_disp:");
    DispList(list);

    bool ret = DeleteElem(list, 12);
    printf("Delete ret: %d\n", ret);
    printf("delete_disp:");
    DispList(list);

    DestroyList(list);

    return 0;
}