// 输出一棵给定二叉树的所有叶子结点
#include <stdio.h>
#include "b_tree.h"

void DispLeaf(BTNode *b) {
    if (nullptr != b) {
        // 访问叶子结点
        if (nullptr == b->lchild && nullptr == b->rchild) {
            printf("%c ", b->data);
        }
        // 输出左子树中的叶子结点
        DispLeaf(b->lchild);
        // 输出右子树中的叶子结点
        DispLeaf(b->rchild);
    }
}

int main() {
    char str[] = "A(B(D(,G)),C(E,F))";
    BTNode *b;
    CreateBTree(b, str);
    printf("disp: ");
    DisplayBTree(b);

    printf("\n");
    DispLeaf(b);

    DestroyBTree(b);

    return 0;
}