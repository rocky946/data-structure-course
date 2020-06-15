// 二叉树先序、中序、后序遍历递归算法
#include <stdio.h>
#include "b_tree.h"

/**
 * 先序遍历递归算法
 * @param b
 */
void PreOrder(BTNode *b) {
    if (nullptr != b) {
        // 访问根结点
        printf("%c ", b->data);
        // 先序遍历左子树
        PreOrder(b->lchild);
        // 先序遍历右子树
        PreOrder(b->rchild);
    }
}

/**
 * 中序遍历递归算法
 * @param b
 */
void InOrder(BTNode *b) {
    if (nullptr != b) {
        // 中序遍历左子树
        InOrder(b->lchild);
        // 访问根结点
        printf("%c ", b->data);
        // 中序遍历右子树
        InOrder(b->rchild);
    }
}

/**
 * 后序遍历递归算法
 * @param b
 */
void PostOrder(BTNode *b) {
    if (nullptr != b) {
        // 后序遍历左子树
        PostOrder(b->lchild);
        // 后序遍历右子树
        PostOrder(b->rchild);
        // 访问根结点
        printf("%c ", b->data);
    }
}

int main() {
    char str[] = "A(B(D(,G)),C(E,F))";
    BTNode *b;
    CreateBTree(b, str);
    printf("disp: ");
    DisplayBTree(b);

    printf("\n先序遍历：\n");
    PreOrder(b);
    printf("\n中序遍历：\n");
    InOrder(b);
    printf("\n后序遍历：\n");
    PostOrder(b);

    DestroyBTree(b);

    return 0;
}