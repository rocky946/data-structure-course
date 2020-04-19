#include <stdio.h>
#include <malloc.h>
#include "cdlinked_list.h"

void CreateDLinkedListF(DLinkNode *&list, const ElemType *a, int n) {
    // 创建头结点
    list = (DLinkNode *) malloc(sizeof(DLinkNode));
    // 初始化头结点的前驱和后继为null
    list->prior = list->next = nullptr;

    DLinkNode *p = nullptr;
    for (int i = 0; i < n; ++i) {
        p = (DLinkNode *) malloc(sizeof(DLinkNode));
        p->data = a[i];

        // 将p结点插到头结点之后
        p->next = list->next;
        // 若list是非空双链表
        if (nullptr != list->next) {
            list->next->prior = p;
        }
        p->prior = list;
        list->next = p;
    }
}

void CreateDLinkedListR(DLinkNode *&list, const ElemType *a, int n) {
    // 创建头结点
    list = (DLinkNode *) malloc(sizeof(DLinkNode));
    // 初始化头结点的前驱为null
    list->prior = nullptr;
    // 尾指针,初始化指向头结点
    DLinkNode *r = list;

    DLinkNode *p = nullptr;
    for (int i = 0; i < n; ++i) {
        p = (DLinkNode *) malloc(sizeof(DLinkNode));
        p->data = a[i];
        // 将p插入到p结点之后
        r->next = p;
        p->prior = r;
        // r继续指向尾结点
        r = p;
    }

    // 设置尾结点的next为null
    r->next = nullptr;
}

void InitList(DLinkNode *&list) {
    list = (DLinkNode *) malloc(sizeof(DLinkNode));
    list->prior = list->next = nullptr;
}

void DestroyList(DLinkNode *&list) {
    DLinkNode *p = list;

    while (p != nullptr) {
        // 释放空间
        free(p->prior);

        p = p->next;
    }

    // 循环结束p指向尾结点
    free(p);
}

bool ListEmpty(DLinkNode *list) {
    return list->next == nullptr;
}

int ListLength(DLinkNode *list) {
    int length = 0;

    // p指向首节点
    DLinkNode *p = list->next;

    while (nullptr != p) {
        length++;
        p = p->next;
    }

    return length;
}

void DispList(DLinkNode *list) {
    // p指向首结点
    DLinkNode *p = list->next;

    while (nullptr != p) {
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n");
}

bool GetElem(DLinkNode *list, int i, ElemType &e) {
    if (i <=0)
        return false;

    int j = 0;
    // p指向头结点
    DLinkNode *p = list;

    // 扫描单链表
    while (j < i && p != nullptr) {
        j++;
        p = p->next;
    }

    // 不存在第i个数据结点
    if (nullptr == p) {
        return false;
    }
    // 存在
    else {
        e = p->data;
        return true;
    }
}

int LocateElem(DLinkNode *list, ElemType &e) {
    int i = 1;

    DLinkNode *p = list->next;

    while (nullptr != p) {
        if (e == p->data) {
            break;
        }
        p = p->next;
        i++;
    }

    // 不存在值为e的结点，返回0
    if (nullptr == p) {
        return 0;
    } else {
        return i;
    }
}

bool ListInsert(DLinkNode *&list, int i, ElemType e) {
    /*
     * 先找到第i-1个结点，若存在则插入
     */
    int j = 0;
    DLinkNode *p = list;
    if (i <= 0) {
        return false;
    }

    // 查找第i-1个结点
    while (j < i - 1 && nullptr != p) {
        j++;
        p = p->next;
    }

    // 未找到第i-1个结点，返回false
    if (nullptr == p) {
        return false;
    } else {
        DLinkNode *s = (DLinkNode *) malloc(sizeof(DLinkNode));
        s->data = e;
        s->next = p->next;
        // 若p不是尾指针
        if (nullptr != p->next) {
            p->next->prior = s;
        }
        s->prior = p;
        p->next = s;

        return true;
    }
}

bool ListDelete(DLinkNode *&list, int i, ElemType &e) {
    /*
     * 查找第i-1个结点p，若p存在且p的next q也存在，则删除q
     */
    int j = 0;
    DLinkNode *p = list;

    if (i <= 0) {
        return false;
    }

    // 查找第i-1个结点
    while (j < i - 1 && nullptr != p) {
        j++;
        p = p->next;
    }

    // 未找到第i个结点
    if (nullptr == p) {
        return false;
    } else {
        DLinkNode *q = p->next;
        // 存在第i个结点
        if (nullptr != q) {
            // 删除q
            e = q->data;
            p->next = q->next;

            // 若q存在后继
            if (nullptr != q->next) {
                q->next->prior = p;
            }

            free(q);
            return true;
        } else {
            return false;
        }
    }
}
