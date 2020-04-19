#include <stdio.h>
#include <malloc.h>
#include "linked_list.h"

void split(LinkNode *list, LinkNode *&l1, LinkNode *&l2) {
    // l1使用list的头结点，使用尾插法建立l1
    l1 = list;
    // l1尾指针
    LinkNode *r = l1;

    // 使用头插法建立l2
    l2 = (LinkNode *) malloc(sizeof(LinkNode));
    l2->next = nullptr;

    LinkNode *p = list->next;
    LinkNode *q = nullptr;

    // 遍历list，建立l1，l2
    while (nullptr != p) {
        r->next = p;
        r = p;

        // 向后移动一个结点
        p = p->next;
        if (nullptr != p) {
            // 头插法建表会改变p的next域，故先将p.next暂存起来
            q = p->next;
            p->next = l2->next;
            l2->next = p;
            p = q;
        }
    }

    r->next = nullptr;
}

int main() {
    int a[] = {3, 1, 4, 9, 8, 11, 2, 8, 19};
    int n = sizeof(a) / sizeof(a[0]);

    // 创建单链表
    LinkNode *list = nullptr;
    CreateLinkedListR(list, a, n);
    printf("ListEmpty: %d\n", ListEmpty(list));
    printf("ListLength: %d\n", ListLength(list));
    DispList(list);

    LinkNode *l1, *l2;
    split(list, l1, l2);
    printf("l1-empty: %d\n", ListEmpty(l1));
    printf("l1-length: %d\n", ListLength(l1));
    DispList(l1);
    printf("l2-empty: %d\n", ListEmpty(l2));
    printf("l2-length: %d\n", ListLength(l2));
    DispList(l2);


    DispList(list);

    DestroyList(l2);
    DestroyList(list);
}


