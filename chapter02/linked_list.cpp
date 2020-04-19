#include <stdio.h>
#include <malloc.h>
#include "linked_list.h"

void CreateLinkedListF(LinkNode *&list,  const ElemType *a, int n) {
    // 创建头结点
    list = (LinkNode *) malloc(sizeof(LinkNode));
    // 头插法创建单链表，头结点next置为空
    list->next = nullptr;

    // 数据结点
    LinkNode *p = nullptr;

    for (int i = 0; i < n; ++i) {
        // 创建数据结点
        p = (LinkNode *) malloc(sizeof(LinkNode));
        p->data = a[i];

        // 将结点p插入到原首结点之前，头结点之后
        p->next = list->next;

        list->next = p;
    }
}

void CreateLinkedListR(LinkNode *&list, const ElemType *a, int n) {
    // 创建头结点
    list = (LinkNode *) malloc(sizeof(LinkNode));
    // 初始化空链表
    list->next = nullptr;
    // 尾指针，始终指向尾结点，初始时指向头结点
    LinkNode *r = list;

    // 数据结点
    LinkNode *p = nullptr;

    for (int i = 0; i < n; ++i) {
        // 创建数据结点
        p = (LinkNode *) malloc(sizeof(LinkNode));
        p->data = a[i];

        // 将p插入到尾结点之后
        r->next = p;
        // r重新指向尾结点
        r = p;
    }

    // 尾插法创建单链表，最终将尾结点的next域置为nullptr
    r->next = nullptr;
}

void InitList(LinkNode *&list) {
    list = (LinkNode *) malloc(sizeof(LinkNode));
    list->next = nullptr;
}

void DestroyList(LinkNode *&list) {
    // pre指向p的前驱结点
    LinkNode *pre = list;
    LinkNode *p = list->next;

    while (p != nullptr) {
        // 释放空间
        free(pre);

        // pre、p后移一个结点
        pre = p;
        p = p->next;
    }

    // 循环结束p为nullptr，pre指向尾结点
    free(p);
}

bool ListEmpty(LinkNode *list) {
    return list->next == nullptr;
}

int ListLength(LinkNode *list) {
    int length = 0;

    // p指向首节点
    LinkNode *p = list->next;

    while (nullptr != p) {
        length++;
        p = p->next;
    }

    return length;
}

void DispList(LinkNode *list) {
    // p指向首结点
    LinkNode *p = list->next;

    while (nullptr != p) {
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n");
}


bool GetElem(LinkNode *list, int i, ElemType &e) {
    if (i <=0)
        return false;

    int j = 0;
    // p指向头结点
    LinkNode *p = list;

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

int LocateElem(LinkNode *list, ElemType &e) {
    int i = 1;

    LinkNode *p = list->next;

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

bool ListInsert(LinkNode *&list, int i, ElemType e) {
    /*
     * 先找到第i-1个结点，若存在则插入
     */
    int j = 0;
    LinkNode *p = list;
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
        LinkNode *s = (LinkNode *) malloc(sizeof(LinkNode));
        s->data = e;
        s->next = p->next;
        p->next = s;

        return true;
    }
}

bool ListDelete(LinkNode *&list, int i, ElemType &e) {
    /*
     * 查找第i-1个结点p，若p存在且p的next q也存在，则删除q
     */
    int j = 0;
    LinkNode *p = list;

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
        LinkNode *q = p->next;
        // 存在第i个结点
        if (nullptr != q) {
            // 删除q
            p->next = q->next;
            e = q->data;
            free(q);
            return true;
        } else {
            return false;
        }
    }
}
