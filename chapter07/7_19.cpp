// 将二叉树的顺序存储结构转换成二叉链存储结构
#include <stdio.h>
#include <malloc.h>
#include "b_tree.h"

typedef ElemType SqBTree[MAX_SIZE];

BTNode *trans(SqBTree a, int i) {
    BTNode *b;
    if (i > MAX_SIZE) {
        return nullptr;
    }

    // 空结点返回null
    if (a[i] == '#') {
        return nullptr;
    }

    // 创建根结点
    b = (BTNode *) malloc(sizeof(BTNode));
    b->data = a[i];
    // 递归创建左子树
    b->lchild = trans(a, 2 * i);
    // 递归创建右子树
    b->rchild = trans(a, 2 * i + 1);

    return b;
}

int main() {
    ElemType a[] = "0ABCD#EF##G####################";
    BTNode *b = trans(a, 1);
    printf("b: ");
    DisplayBTree(b);
    printf("\n");
    DestroyBTree(b);

    return 0;
}