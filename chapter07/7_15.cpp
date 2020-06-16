// 判断两棵二叉树是否相似
#include <stdio.h>
#include "b_tree.h"

/**
 * b1，b2两棵二叉树相似时返回true，否则返回false
 * @param b1
 * @param b2
 * @return
 */
bool Like(BTNode *b1, BTNode *b2) {
    bool like1, like2;
    if (nullptr == b1 && nullptr == b2) {
        return true;
    } else if (nullptr == b1 || nullptr == b2) {
        return false;
    }
    // 判断左右子树是否相似
    else {
        like1 = Like(b1->lchild, b2->lchild);
        like2 = Like(b1->rchild, b2->rchild);
        return like1 && like2;
    }
}

int main() {
    char str1[] = "A(B(D(,G)),C(E,F))";
    BTNode *b1;
    CreateBTree(b1, str1);
    printf("disp1: ");
    DisplayBTree(b1);

    char str2[] = "a(b(d(,g)),c(e,f))";
    BTNode *b2;
    CreateBTree(b2, str2);
    printf("disp2: ");
    DisplayBTree(b2);

    printf("\n");
    bool like = Like(b1, b2);
    if (like) {
        printf("相似\n");
    } else {
        printf("不相似\n");
    }

    DestroyBTree(b1);
    DestroyBTree(b2);
    return 0;
}