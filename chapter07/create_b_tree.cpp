// 构造二叉树
#include <stdio.h>
#include <malloc.h>
#include "b_tree.h"

/**
 * 根据先序和中序序列构造二叉树
 * @param pre 先序序列
 * @param in 中序序列
 * @param n 二叉树结点个数
 * @return 二叉树根结点指针
 */
BTNode *CreateBT1(char *pre, char *in, int n) {
    BTNode *b;
    char *p;
    int k;
    if (n <= 0) {
        return nullptr;
    }

    // 创建二叉树结点b
    b = (BTNode *) malloc(sizeof(BTNode));
    b->data = *pre;

    // 在中序序列中找等于*pre字符的位置k
    for (p = in; p < in + n; p++) {
        // pre指向根结点
        if (*p == *pre) {
            // 在in中找到后退出循环
            break;
        }
    }

    // 确定根结点在in中的位置
    k = p - in;

    // 递归构造左子树
    b->lchild = CreateBT1(pre + 1, in, k);
    // 递归构造右子树
    b->rchild = CreateBT1(pre + k + 1, p + 1, n - k - 1);

    return b;
}

/**
 * 根据后序和中序序列构造二叉树
 * @param post 后序序列
 * @param in 中序序列
 * @param n 二叉树结点个数
 * @return 二叉树根结点指针
 */
BTNode *CreateBT2(char *post, char *in, int n) {
    BTNode *b;
    char r, *p;
    int k;
    if (n <= 0) {
        return nullptr;
    }

    // 根结点值
    r = *(post + n - 1);
    // 创建二叉树结点b
    b = (BTNode *) malloc(sizeof(BTNode));
    b->data = r;

    // 在中序序列中查找根结点
    for (p = in; p < in + n; p++) {
        if (*p == r) {
            // 在in中找到后退出循环
            break;
        }
    }

    // 确定根结点在in中的位置
    k = p - in;

    // 递归构造左子树
    b->lchild = CreateBT2(post, in, k);
    // 递归构造右子树
    b->rchild = CreateBT2(post + k, p + 1, n - k - 1);

    return b;
}

int main() {
    ElemType pre[] = "ABDGCEF", in[] = "DGBAECF", post[] = "GDBEFCA";
    BTNode *b1, *b2;
    b1 = CreateBT1(pre, in, 7);
    printf("b1:");
    DisplayBTree(b1);
    printf("\n");
    
    b2 = CreateBT2(post, in, 7);
    printf("b2:");
    DisplayBTree(b2);
    printf("\n");
    
    DestroyBTree(b1);
    DestroyBTree(b2);
    return 1;
}