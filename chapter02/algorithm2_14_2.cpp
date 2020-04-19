// 例2.14(p66)
// 假设有两个有序表LA和LB，设计一个算法，将它们合并成一个有序表LC(假设每个有序表中和两个
// 有序表间不存在重复元素)，要求不破坏原有表LA和LB
// 算法二：采用单链表存放有序表时的二路归并算法
#include <stdio.h>
#include <malloc.h>
#include "ordered_linked_list.h"

void UnionList(LinkNode *LA, LinkNode *LB, LinkNode *&LC) {
    LinkNode *p = LA->next, *q = LB->next, *s = nullptr;
    LC = (LinkNode *) malloc(sizeof(LinkNode));
    // LC尾指针
    LinkNode *r = LC;

    while (nullptr != p && nullptr != q) {
        if (p->data < q->data) {
            // 复制p所指结点
            s = (LinkNode *) malloc(sizeof(LinkNode));
            s->data = p->data;
            r->next = s;
            r = s;

            p = p->next;
        } else {
            s = (LinkNode *) malloc(sizeof(LinkNode));
            s->data = q->data;
            r->next = s;
            r = s;

            q = q->next;
        }
    }

    while (nullptr != p) {
        s = (LinkNode *) malloc(sizeof(LinkNode));
        s->data = p->data;
        r->next = s;
        r = s;

        p = p->next;
    }

    while (nullptr != q) {
        s = (LinkNode *) malloc(sizeof(LinkNode));
        s->data = q->data;
        r->next = s;
        r = s;

        q = q->next;
    }

    r->next = nullptr;
}

int main() {
    // 创建LA
    LinkNode *LA = nullptr;
    ElemType a[] = {1, 3, 5};
    int n = sizeof(a) / sizeof(a[0]);
    CreateLinkedListR(LA, a, n);
    printf("LA：");
    DispList(LA);

    // 创建LB
    LinkNode *LB = nullptr;
    ElemType b[] = {2, 4, 8, 10};
    n = sizeof(b) / sizeof(b[0]);
    CreateLinkedListR(LB, b, n);
    printf("LB：");
    DispList(LB);

    // 创建LC
    LinkNode *LC = nullptr;
    UnionList(LA, LB, LC);
    printf("LC：");
    DispList(LC);

    DestroyList(LA);
    DestroyList(LB);
    DestroyList(LC);

    return 0;
}
