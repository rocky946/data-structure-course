#include <stdio.h>
#include <malloc.h>
#include "b_tree.h"

void CreateBTree(BTNode *&b, char *str) {
    // St数组作为顺序栈
    BTNode *St[MAX_SIZE];
    BTNode *p = nullptr;
    int top = -1, k = 0, j = 0;
    char ch = str[j];
    // 初始时二叉链为空
    b = nullptr;

    // 循环扫描str中的字符
    while (ch != '\0') {
        switch (ch) {
            // 开始处理左孩子结点
            case '(':
                top++;
                St[top] = p;
                k = 1;
                break;
            // 栈顶结点的子树处理完毕
            case ')':
                top--;
                break;
            // 开始处理右孩子结点
            case ',':
                k = 2;
                break;
            // 处理字符
            default:
                // 创建一个结点
                p = (BTNode *) malloc(sizeof(BTNode));
                p->data = ch;
                // 左右指针初始都设置为空
                p->lchild = p->rchild = nullptr;

                // 若尚未建立根结点,p所指结点就作为根结点
                if (b == nullptr) {
                    b = p;
                }
                // 已建立根节点
                else {
                    switch (k) {
                        // 新建结点作为栈顶结点的左孩子
                        case 1:
                            St[top]->lchild = p;
                            break;
                        case 2:
                            St[top]->rchild = p;
                            break;
                        default:
                            break;
                    }
                }
        }

        // 继续扫描str
        j++;
        ch = str[j];
    }
}

void DestroyBTree(BTNode *&b) {
    if (nullptr != b) {
        DestroyBTree(b->lchild);
        DestroyBTree(b->rchild);
        free(b);
    }
}

BTNode *FindNode(BTNode *b, ElemType x) {
    BTNode *p = nullptr;

    if (nullptr == b) {
        return nullptr;
    } else if (b->data == x) {
        return b;
    } else {
        p = FindNode(b->lchild, x);
        // 在左子树中找到了
        if (nullptr != p) {
            return p;
        }
        // 左子树未找到，找右子树
        else {
            return FindNode(b->rchild, x);
        }
    }
}

BTNode *LchildNode(BTNode *p) {
    return p->lchild;
}

BTNode *RchildNode(BTNode *p) {
    return p->rchild;
}

int BTHeight(BTNode *b) {
    int lchildh, rchildh;

    // 空数的高度为0
    if (nullptr == b) {
        return 0;
    } else {
        // 求左子树的高度
        lchildh = BTHeight(b->lchild);
        // 求右子树的高度
        rchildh = BTHeight(b->rchild);
        return lchildh > rchildh ? lchildh + 1 : rchildh + 1;
    }
}

void DisplayBTree(BTNode *b) {
    if (nullptr != b) {
        printf("%c", b->data);

        // 有孩子结点时才输出'('
        if (nullptr != b->lchild || nullptr != b->rchild) {
            printf("(");
            // 递归处理左子树
            DisplayBTree(b->lchild);

            // 有右孩子结点时才输出','
            if (nullptr != b->rchild) {
                printf(",");
            }

            // 递归处理右子树
            DisplayBTree(b->rchild);

            // 有孩子结点时才输出','
            printf(")");
        }
    }
}
