// 有一个带头结点的单链表L(至少有一个数据结点),设计一个算法使其元素递增有序排列
#include <stdio.h>
#include <malloc.h>
#include "linked_list.h"

void Sort(LinkNode *&list) {
    // p指向list的第2个数据结点
    LinkNode *p = list->next->next;
    // 构造只含有一个数据结点的有序单链表
    list->next->next = nullptr;

    LinkNode *pre = nullptr, *q = nullptr;

    while (nullptr != p) {
        // 从有序单链表开头进行比较，pre指向插入结点的前驱结点
        pre = list;

        // 寻找pre
        while (nullptr != pre->next && pre->next->data < p->data) {
            pre = pre->next;
        }

        // 临时保存p后继结点
        q = p->next;
        // 在pre所指结点之后插入p所指结点
        p->next = pre->next;
        pre->next = p;
        p = q;
    }
}

int main() {
    int a[] = {3, 1, 4, 9, 8, 11, 2, 20, 19};
    int n = sizeof(a) / sizeof(a[0]);

    // 创建单链表
    LinkNode *list = nullptr;
    CreateLinkedListR(list, a, n);
    printf("ListEmpty: %d\n", ListEmpty(list));
    printf("ListLength: %d\n", ListLength(list));
    DispList(list);

    Sort(list);
    printf("ListEmpty: %d\n", ListEmpty(list));
    printf("ListLength: %d\n", ListLength(list));
    DispList(list);

    DestroyList(list);
}