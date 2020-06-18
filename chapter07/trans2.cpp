// 将二叉树的二叉链存储结构转换成顺序存储结构
#include <stdio.h>
#include "b_tree.h"

typedef ElemType SqBTree[MAX_SIZE];

void trans2(BTNode *b, SqBTree a, int i) {
    if (nullptr != b) {
        // 创建根结点
        a[i] = b->data;
        // 递归创建左子树
        trans2(b->lchild, a, 2 * i);
        // 递归创建右子树
        trans2(b->rchild, a, 2 * i + 1);
    }
}

int main() {
    char str[] = "A(B(D(,G)),C(E,F))";
    BTNode *b;
    CreateBTree(b, str);
    printf("disp: ");
    DisplayBTree(b);

    SqBTree a;
    int i;
    for (i = 0; i < MAX_SIZE; ++i) {
        a[i] = '#';
    }

    trans2(b, a, 1);
    printf("\n顺序二叉树：");
    for (i = 0; i < MAX_SIZE; ++i) {
        printf("%c", a[i]);
    }
    printf("\n");

    DestroyBTree(b);
    return 0;
}