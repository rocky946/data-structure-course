#include "bst.h"
#include <stdio.h>

/**
 *
 * 返回一颗二叉排序树中的最大结点关键字
 * @param p
 * @return
 */
KeyType maxnode(BSTNode *p) {
    while (nullptr != p->rchild) {
        p = p->rchild;
    }
    return p->key;
}

/**
 * 返回一颗二叉排序树中的最小结点关键字
 * @param p
 * @return
 */
KeyType minnode(BSTNode *p) {
    while (nullptr != p->lchild) {
        p = p->lchild;
    }
    return p->key;
}

void maxminnode(BSTNode *p) {
    if (nullptr != p) {
        if (nullptr != p->lchild) {
            printf("左子树的最大结点为：%d\n", maxnode(p->lchild));
        }
        if (nullptr != p->rchild) {
            printf("右子树的最小结点为：%d\n", minnode(p->rchild));
        }
    }
}

int main() {
    BSTNode *bt;
    int n = 12, x = 46;
    KeyType a[] = {25, 18, 46, 2, 53, 39, 32, 4, 74, 67, 60, 11};

    bt = CreateBST(a, n);
    printf("BST:");
    DispBST(bt);
    printf("\n");

    maxminnode(bt);

    return 0;
}