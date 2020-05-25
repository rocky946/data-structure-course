// 假设有一个不带头结点的单链表list,设计一个算法释放其中的所有结点
#include <stdio.h>
#include <malloc.h>
#include "linked_list.h"

void Release(LinkNode *&list) {
    if (nullptr != list) {
        Release(list->next);
        free(list);
    }
}

int main() {
    int a[] = {3, 1, 4, 9, 8, 11};
    int n = sizeof(a) / sizeof(a[0]);

    // 创建单链表
    LinkNode *list = nullptr;
    CreateLinkedListR(list, a, n);
    DispList(list);

    Release(list);

    return 0;
}