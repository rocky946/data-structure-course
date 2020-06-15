// 计算一棵给定二叉树的所有结点个数
#include <stdio.h>
#include "b_tree.h"

int Nodes(BTNode *b) {
    if (nullptr == b) {
        return 0;
    } else {
        return Nodes(b->lchild) + Nodes(b->rchild) + 1;
    }
}

int main() {
    char str[] = "A(B(D(,G)),C(E,F))";
    BTNode *b;
    CreateBTree(b, str);
    printf("disp: ");
    DisplayBTree(b);

    printf("\n结点个数：%d\n", Nodes(b));

    DestroyBTree(b);
    return 0;
}