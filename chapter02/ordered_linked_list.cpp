#include <stdio.h>
#include <malloc.h>
#include "ordered_linked_list.h"

void OrderedListInsert(LinkNode *&list, ElemType e) {
    // 指向插入位置前驱结点
    LinkNode *pre = list;

    // 查找插入结点的前驱结点pre
    while (nullptr != pre->next && pre->next->data < e) {
        pre = pre->next;
    }

    LinkNode *p = nullptr;
    p = (LinkNode *) malloc(sizeof(LinkNode));
    // 在pre结点之后插入p
    p->data = e;
    p->next = pre->next;
    pre->next = p;
}
