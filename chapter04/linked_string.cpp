#include <stdio.h>
#include <malloc.h>
#include "linked_string.h"

void StrAssign(LinkStrNode *&s, char *cstr) {
    LinkStrNode *r, *p;
    s = (LinkStrNode *) malloc(sizeof(LinkStrNode));
    // r始终指向尾结点
    r = s;

    for (int i = 0; cstr[i] != '\0'; ++i) {
        p = (LinkStrNode *) malloc(sizeof(LinkStrNode));
        p->data = cstr[i];
        r->next = p;
        r = p;
    }

    // 最终将尾结点的next域置为空
    r->next = nullptr;
}

void DestroyStr(LinkStrNode *&s) {
    // pre指向p的前驱结点
    LinkStrNode *pre = s, *p = s->next;

    while (nullptr != p) {
        free(pre);
        pre = p;
        p = pre->next;
    }

    // 循环结束时p为nullptr,pre指向尾结点，释放它
    free(pre);
}

void StrCopy(LinkStrNode *&s, LinkStrNode *t) {
    LinkStrNode *p = t->next, *q, *r;
    s = (LinkStrNode *) malloc(sizeof(LinkStrNode));
    // r始终指向尾结点
    r = s;

    // 扫描链串t的所有结点
    while (nullptr != p) {
        q = (LinkStrNode *) malloc(sizeof(LinkStrNode));
        // 将p结点复制到q结点
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }

    // 最终将尾结点的next域置为空
    r->next = nullptr;
}

bool StrEqual(LinkStrNode *s, LinkStrNode *t) {
    // p,q分别扫描链串s和t的数据结点
    LinkStrNode *p = s->next, *q = t->next;

    while (nullptr != p && nullptr != q && p->data == q->data) {
        p = p->next;
        q = q->next;
    }

    // s和t的长度相等且对应位置的字符均相同时返回true
    return nullptr == p && nullptr == q;
}

int StrLength(LinkStrNode *s) {
    LinkStrNode *p = s->next;

    int i = 0;
    while (nullptr != p) {
        i++;
        p = p->next;
    }

    return i;
}

LinkStrNode *Concat(LinkStrNode *s, LinkStrNode *t) {
    LinkStrNode *str, *p = s->next, *q, *r;
    str = (LinkStrNode *) malloc(sizeof(LinkStrNode));
    r = str;

    // 扫描s的所有数据结点
    while (nullptr != p) {
        q = (LinkStrNode *) malloc(sizeof(LinkStrNode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }

    p = t->next;
    // 扫描t的所有数据结点
    while (nullptr != p) {
        q = (LinkStrNode *) malloc(sizeof(LinkStrNode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }

    // 最终将尾结点的next域置为空
    r->next = nullptr;
    return str;
}

LinkStrNode *SubStr(LinkStrNode *s, int i, int j) {
    LinkStrNode *str, *p = s->next, *q, *r;
    str = (LinkStrNode *) malloc(sizeof(LinkStrNode));
    // 初始化str为空串
    str->next = nullptr;
    r = str;

    // 参数不正确时返回空串
    if (i <= 0 || i > StrLength(s) || j < 0 || i + j - 1 > StrLength(s)) {
        return str;
    }

    int k;
    // 让p指向链串s的第i个数据结点
    for (k = 1; k < i; k++) {
        p = p->next;
    }

    // 将s的从第i个结点开始的j个结点复制到str
    for (k = 1; k < j; k++) {
        q = (LinkStrNode *) malloc(sizeof(LinkStrNode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }

    // 最终将尾结点的next域置为空
    r->next = nullptr;
    return str;
}

LinkStrNode *InsStr(LinkStrNode *s, int i, LinkStrNode *t) {
    LinkStrNode *str, *p = s->next, *p1 = t->next, *q, *r;
    str = (LinkStrNode *) malloc(sizeof(LinkStrNode));
    // 初始化str为空串
    str->next = nullptr;
    r = str;
    
    // 参数不合法返回空串
    if (i <= 0 || i > StrLength(s) + 1) {
        return str;
    }
    
    // 将s的前i-1个数据结点复制到str
    int k;
    for (k = 1; k < i; k++) {
        q = (LinkStrNode *) malloc(sizeof(LinkStrNode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }
    
    // 将t的所有结点复制到str
    while (nullptr != p1) {
        q = (LinkStrNode *) malloc(sizeof(LinkStrNode));
        q->data = p1->data;
        r->next = q;
        r = q;
        p1 = p1->next;
    }
    
    // 将p结点及其后面的结点复制到str
    while (nullptr != p) {
        q = (LinkStrNode *) malloc(sizeof(LinkStrNode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }
    
    // 最终将尾结点的next域置为空
    r->next = nullptr;
    return str;
}

LinkStrNode *DelStr(LinkStrNode *s, int i, int j) {
    LinkStrNode *str, *p = s->next, *q, *r;
    str = (LinkStrNode *) malloc(sizeof(LinkStrNode));
    // 初始化str为空串
    str->next = nullptr;
    r = str;

    // 参数不正确时返回空串
    if (i <= 0 || i > StrLength(s) || j < 0 || i + j - 1 > StrLength(s)) {
        return str;
    }

    // 将s的前i-1个数据结点复制到str
    int k;
    for (k = 1; k < i; k++) {
        q = (LinkStrNode *) malloc(sizeof(LinkStrNode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }
    
    // 让p沿next跳j个结点
    for (k = 0; k < j; k++) {
        p = p->next;
    }

    // 将p结点及其后面的结点复制到str
    while (nullptr != p) {
        q = (LinkStrNode *) malloc(sizeof(LinkStrNode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }

    // 最终将尾结点的next域置为空
    r->next = nullptr;
    return str;
}

LinkStrNode *RepStr(LinkStrNode *s, int i, int j, LinkStrNode *t) {
    LinkStrNode *str, *p = s->next, *p1 = t->next, *q, *r;
    str = (LinkStrNode *) malloc(sizeof(LinkStrNode));
    // 初始化str为空串
    str->next = nullptr;
    r = str;
    
    // 参数不正确时返回空串
    if (i <= 0 || i > StrLength(s) || j < 0 || i + j - 1 > StrLength(s)) {
        return str;
    }

    // 将s的前i-1个数据结点复制到str
    int k;
    for (k = 1; k < i; k++) {
        q = (LinkStrNode *) malloc(sizeof(LinkStrNode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }

    // 让p沿next跳j个结点
    for (k = 0; k < j; k++) {
        p = p->next;
    }

    // 将t的所有结点复制到str
    while (nullptr != p1) {
        q = (LinkStrNode *) malloc(sizeof(LinkStrNode));
        q->data = p1->data;
        r->next = q;
        r = q;
        p1 = p1->next;
    }

    // 将p结点及其后面的结点复制到str
    while (nullptr != p) {
        q = (LinkStrNode *) malloc(sizeof(LinkStrNode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }

    // 最终将尾结点的next域置为空
    r->next = nullptr;
    return str;
}

void DispStr(LinkStrNode *s) {
    LinkStrNode *p = s->next;
    while (nullptr != p) {
        printf("%c", p->data);
        p = p->next;
    }
    printf("\n");
}
