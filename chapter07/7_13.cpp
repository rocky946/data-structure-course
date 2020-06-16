// 求二叉树中指定结点的层次
#include <stdio.h>
#include "b_tree.h"

int Level(BTNode *b, ElemType x, int h) {
    int l;
    if (nullptr == b) {
        return 0;
    } else if (b->data == x) {
        return h;
    } else {
        // 在左子树中查找
        l = Level(b->lchild, x, h + 1);
        // 在左子树中找到了，返回l
        if (l != 0) {
            return l;
        }
        // 在左子树中未找到，再在右子树中查找
        else {
            return Level(b->rchild, x, h + 1);
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
    ElemType x = 'O';
    int h = Level(b, x, 1);
    if (h == 0) {
        printf("b中不存在%c结点\n", x);
    } else {
        printf("在b中%c结点的层次为%d\n", x, h);
    }

    DestroyBTree(b);
    return 0;
}
