// 先序、中序、后序非递归遍历算法
#include "sq_stack.h"
#include <stdio.h>

/**
 * 先序非递归遍历算法1
 * @param b
 */
void PreOrder1(BTNode *b) {
    BTNode *p;
    // 定义栈指针st
    SqStack *st;
    // 初始化栈st
    InitStack(st);

    if (nullptr != b) {
        // 根节点进栈
        Push(st, b);

        // 栈不为空时循环
        while (!StackEmpty(st)) {
            // 退栈结点p并访问
            Pop(st, p);
            printf("%c ", p->data);

            // 有右孩子时将其进栈
            if (nullptr != p->rchild) {
                Push(st, p->rchild);
            }
            // 有左孩子时将其进栈
            if (nullptr != p->lchild) {
                Push(st, p->lchild);
            }
        }
        printf("\n");
    }
    // 销毁栈
    DestroyStack(st);
}

/**
 * 先序非递归遍历算法2
 * @param b
 */
void PreOrder2(BTNode *b) {
    BTNode *p;
    // 定义栈指针st
    SqStack *st;
    // 初始化栈st
    InitStack(st);
    p = b;

    while (!StackEmpty(st) || nullptr != p) {
        // 访问结点p及其所有左下结点并进栈
        while (nullptr != p) {
            // 访问结点p
            printf("%c ", p->data);
            // 结点p进栈
            Push(st, p);
            // 移动到左孩子
            p = p->lchild;
        }

        // 若栈不空
        if (!StackEmpty(st)) {
            // 出栈结点p
            Pop(st, p);
            // 转向处理其右子树
            p = p->rchild;
        }
    }
    printf("\n");
    DestroyStack(st);
}

/**
 * 中序非递归遍历算法
 * @param b
 */
void InOrder(BTNode *b) {
    BTNode *p;
    // 定义栈指针st
    SqStack *st;
    // 初始化栈st
    InitStack(st);
    p = b;

    while (!StackEmpty(st) || nullptr != p) {
        // 访问结点p及其所有左下结点并进栈
        while (nullptr != p) {
            // 结点p进栈
            Push(st, p);
            // 移动到左孩子
            p = p->lchild;
        }

        // 若栈不空
        if (!StackEmpty(st)) {
            // 出栈结点p
            Pop(st, p);
            // 访问结点p
            printf("%c ", p->data);
            // 转向处理其右子树
            p = p->rchild;
        }
    }
    printf("\n");
    DestroyStack(st);
}

/**
 * 后序非递归遍历算法
 * @param b
 */
void PostOrder(BTNode *b) {
    BTNode *p, *r;
    bool flag;
    // 定义栈指针st
    SqStack *st;
    // 初始化栈st
    InitStack(st);
    p = b;

    do {
        // 访问结点p及其所有左下结点并进栈
        while (nullptr != p) {
            // 结点p进栈
            Push(st, p);
            // 移动到左孩子
            p = p->lchild;
        }

        // r指向刚访问的结点，初始时为空
        r = nullptr;
        // flag为栈表示正在处理栈顶结点
        flag = true;
        while (!StackEmpty(st) && flag) {
            // 取当前栈顶结点p
            GetTop(st, p);
            // 若结点p的右孩子为空或者为刚刚访问过的结点
            if (p->rchild == r) {
                // 访问结点p
                printf("%c ", p->data);
                // 出栈p
                Pop(st, p);
                // r指向刚访问过得结点
                r = p;
            }
            // 转向处理其右子树
            else {
                p = p->rchild;
                // 表示当前不是处理栈顶结点
                flag = false;
            }
        }
    }
    // 栈不空循环
    while (!StackEmpty(st));

    printf("\n");
    DestroyStack(st);
}

int main() {
    char str[] = "A(B(D(,G)),C(E,F))";
    BTNode *b;
    CreateBTree(b, str);
    printf("disp: ");
    DisplayBTree(b);

    printf("\n先序非递归遍历方法1：\n");
    PreOrder1(b);
    printf("\n先序非递归遍历方法2：\n");
    PreOrder2(b);

    printf("\n中序非递归遍历：\n");
    InOrder(b);

    printf("\n后序非递归遍历：\n");
    PostOrder(b);

    DestroyBTree(b);

    return 0;
}
