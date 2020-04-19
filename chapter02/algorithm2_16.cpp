#include <stdio.h>
#include <malloc.h>
#include "ordered_linked_list.h"

void DeleteSame(LinkNode *&list) {
    LinkNode *p = list->next;
    LinkNode *q = nullptr;

    while (nullptr != p->next) {
        // 找到重复结点
        if (p->data == p->next->data) {
            // 删除p.next
            q = p->next;
            p->next = q->next;
            free(q);
        } else {
            p = p->next;
        }
    }
}

int main() {
    LinkNode *list = nullptr;
    ElemType a[] = {1, 3, 4, 4, 5, 5, 8};
    int n = sizeof(a) / sizeof(a[0]);
    CreateLinkedListR(list, a, n);
    printf("init_disp: ");
    DispList(list);

    DeleteSame(list);
    printf("delete_disp: ");
    DispList(list);

    DestroyList(list);

    return 0;
}