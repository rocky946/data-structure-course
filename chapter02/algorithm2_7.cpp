// 删除一个单链表L中元素值最大的结点(假设这样的结点唯一)
#include <stdio.h>
#include <malloc.h>
#include "linked_list.h"

void DelMaxNode(LinkNode *&list) {
    LinkNode *pre = list;
    // 元素值最大结点的前驱
    LinkNode *maxPre = pre;

    while (nullptr != pre->next) {
        if (pre->next->data > maxPre->next->data) {
            maxPre = pre;
        }

        pre = pre->next;
    }

    if (!ListEmpty(list)) {
        // 删除maxPre.next，即元素值最大结点
        LinkNode *q = maxPre->next;
        maxPre->next = q->next;
        free(q);
    } else {
        printf("空表\n");
    }
}

int main() {
    int a[] = {3, 1, 4, 9, 8, 11, 2, 20, 19};
//    int a[] = {};
    int n = sizeof(a) / sizeof(a[0]);

    // 创建单链表
    LinkNode *list = nullptr;
    CreateLinkedListR(list, a, n);
    printf("ListEmpty: %d\n", ListEmpty(list));
    printf("ListLength: %d\n", ListLength(list));
    DispList(list);

    DelMaxNode(list);
    printf("ListEmpty: %d\n", ListEmpty(list));
    printf("ListLength: %d\n", ListLength(list));
    DispList(list);
}