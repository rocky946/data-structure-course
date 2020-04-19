#include <stdio.h>
#include <malloc.h>
#include "ordered_linked_list.h"

void CommNode(LinkNode *&la, LinkNode *lb, LinkNode *lc) {
    LinkNode *pa = la->next, *pb = lb->next, *pc = lc->next;
    LinkNode *q = nullptr, *r = nullptr;

    // 将la作为新建单链表的头结点
    la->next = nullptr;
    // r始终指向新单链表的尾结点
    r = la;

    while (nullptr != pa) {
        // 比较pa、pb
        while (nullptr != pb && pa->data > pb->data) {
            pb = pb->next;
        }

        // 比较pa、pc
        while (nullptr != pc && pa->data > pc->data) {
            pc = pc->next;
        }

        // 若pa是公共结点，将pa插入到la中
        if (nullptr != pb && nullptr != pc &&
            pa->data == pb->data && pa->data == pc->data) {
            r->next = pa;
            r = pa;
            pa = pa->next;
        }
        // 非公共结点，删除
        else {
            q = pa;
            pa = pa->next;
            free(q);
        }
    }

    // 尾结点的next置为空
    r->next = nullptr;
}

int main() {
    // 创建la
    LinkNode *la = nullptr;
    ElemType a[] = {1, 3, 5, 8};
    int n = sizeof(a) / sizeof(a[0]);
    CreateLinkedListR(la, a, n);
    printf("la：");
    DispList(la);

    // 创建lb
    LinkNode *lb = nullptr;
    ElemType b[] = {2, 3, 5, 7, 8};
    n = sizeof(b) / sizeof(b[0]);
    CreateLinkedListR(lb, b, n);
    printf("lb：");
    DispList(lb);

    // 创建lc
    LinkNode *lc = nullptr;
    ElemType c[] = {1, 5, 6, 7, 8};
    n = sizeof(b) / sizeof(b[0]);
    CreateLinkedListR(lc, c, n);
    printf("lc：");
    DispList(lc);

    printf("common_list:");
    CommNode(la, lb, lc);
    DispList(la);

    DestroyList(la);
    DestroyList(lb);

    return 0;
}