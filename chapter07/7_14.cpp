// 求二叉树b中指定层次k的结点个数
#include <stdio.h>
#include "b_tree.h"

/**
 *
 * @param b
 * @param h b所指的结点层次
 * @param k 所求结点层次
 * @param n 第k层结点个数
 */
void Lnodenum(BTNode *b, int h, int k, int &n) {
    // 空数直接返回
    if (nullptr == b) {
        return;
    }
    // 处理非空树
    else {
        // 当前访问的结点在第k层时n增1
        if (h == k) {
            n++;
        }
        // 若当前结点层次小于k，递归处理左、右子树
        else if (h < k) {
            Lnodenum(b->lchild, h + 1, k, n);
            Lnodenum(b->rchild, h + 1, k, n);
        }
    }
}

/**
 * 方法二：上述算法引用型参数n使用全局变量代替
 * @param b
 * @param h b所指的结点层次
 * @param k 所求结点层次
 */
int n1 = 0;
void Lnodenum1(BTNode *b, int h, int k) {
    // 空树直接返回
    if (nullptr == b) {
        return;
    }
    // 处理非空树
    else {
        // 当前访问的结点在第k层时n增1
        if (h == k) {
            n1++;
        }
        // 若当前结点层次小于k，递归处理左、右子树
        else if (h < k) {
            Lnodenum(b->lchild, h + 1, k, n1);
            Lnodenum(b->rchild, h + 1, k, n1);
        }
    }
}

int main() {
    char str[] = "A(B(D(,G)),C(E,F))";
    BTNode *b;
    CreateBTree(b, str);
    printf("disp: ");
    DisplayBTree(b);

    printf("\n");
    int k = 4;
    int n = 0;
    Lnodenum(b, 1, k, n);
    Lnodenum1(b, 1, k);

    printf("方法一第%d层结点个数: %d\n", k, n);
    printf("方法二第%d层结点个数: %d\n", k, n1);

    DestroyBTree(b);
    return 0;
}