#include <stdio.h>
#include <malloc.h>
#include "linked_stack.h"

void InitStack(LinkStNode *&stack) {
    stack = (LinkStNode *) malloc(sizeof(LinkStNode));
    stack->next = nullptr;
}

void DestroyStack(LinkStNode *&stack) {
    LinkStNode *pre = stack;
    LinkStNode *p = pre->next;

    while (nullptr != p) {
        free(pre);
        pre = p;
        p = pre->next;
    }

    free(pre);
}

bool StackEmpty(LinkStNode *stack) {
    return stack->next == nullptr;
}

void Push(LinkStNode *&stack, ElemType e) {
    // 新建结点P
    LinkStNode *p = nullptr;
    p = (LinkStNode *) malloc(sizeof(LinkStNode));

    // 插入p结点作为首结点
    p->data = e;
    p->next = stack->next;
    stack->next = p;
}

bool Pop(LinkStNode *&stack, ElemType &e) {
    // 栈空
    if (stack->next == nullptr) {
        return false;
    }

    // p指向首结点
    LinkStNode *p = stack->next;
    e = p->data;
    stack->next = p->next;
    free(p);

    return true;
}

bool GetTop(LinkStNode *stack, ElemType &e) {
    // 栈空
    if (stack->next == nullptr) {
        return false;
    }

    e = stack->next->data;

    return true;
}
