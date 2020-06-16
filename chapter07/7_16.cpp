// 输出二叉树中值为x的结点的所有祖先。
#include <stdio.h>
#include "b_tree.h"

/**
 * 判断b是否是x的祖先
 * @param b
 * @param x
 * @return
 */
bool ancestor(BTNode *b, ElemType x) {
    if (nullptr == b) {
        return false;
    } else if ((nullptr != b->lchild && x == b->lchild->data)
            || (nullptr != b->rchild && x == b->rchild->data)) {
        printf("%c ", b->data);
        return true;
    } else if (ancestor(b->lchild, x) || ancestor(b->rchild, x)) {
        printf("%c ", b->data);
        return true;
    } else {
        return false;
    }
}

/**
 *
 * @param b
 * @param x
 * @param path 路径结点数组
 * @param d 路径中结点个数
 * @return
 */
bool ancestor1(BTNode *b, ElemType x, ElemType path[], int d) {
    bool find;
    // 空树返回false
    if (nullptr == b) {
        return false;
    }
    // 将当前结点加入path
    d++;
    path[d] = b->data;
    // 当前结点值为x,输出
    if (b->data == x) {
        for (int i = 0; i < d; ++i) {
            printf("%c ", path[i]);
        }
        printf("\n");
        return true;
    }

    // 在左子树中查找
    find = ancestor1(b->lchild, x, path, d);
    // 在左子树中成功找到
    if (find) {
        return true;
    }
    // 左子树中没有找到，在右子树中查找
    else {
        return ancestor1(b->rchild, x, path, d);
    }
}

int main() {
    char str[] = "A(B(D(,G)),C(E,F))";
    BTNode *b;
    CreateBTree(b, str);
    printf("disp: ");
    DisplayBTree(b);

    printf("\n");
    ElemType x = 'G';
    printf("%c在b中的祖先结点: ", x);
    ancestor(b, x);

    printf("\n");
    ElemType path[100];
    int d = -1;
    ancestor1(b, x, path, d);

    DestroyBTree(b);
    return 0;
}