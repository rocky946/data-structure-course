// 孩子链存储结构下树的基本运算算法和求树t的高度
#include <stdio.h>
#include <malloc.h>

#define MAX_SONS 10
#define MAX_SIZE 100

typedef char ElemType;

// 孩子链存储结构中的结点类型
typedef struct node {
    // 结点的值
    ElemType data;
    // 指向孩子结点
    struct node *sons[MAX_SIZE];
} TSonNode;

/**
 * 由str建立孩子链存储结构
 * @param str
 * @return
 */
TSonNode *CreateTree(char *str) {
    // 定义顺序栈
    struct {
        // 节点指针
        TSonNode *nodep;
        // 孩子个数
        int num;
    } St[MAX_SIZE];

    // 栈顶指针
    int top = -1;
    int i = 0, j;
    char ch = str[i];
    TSonNode *t = nullptr, *p;

    while (ch != '\0') {
        switch (ch) {
            case '(':
                // 有孩子，当前节点*p进栈
                top++;
                St[top].nodep = p;
                St[top].num = 0;
                break;
            case ')':
                // 退栈
                top--;
                break;
            case ',':
                // 栈顶节点增加一个孩子
                St[top].num++;
                break;
            default:
                p = (TSonNode *) malloc(sizeof(TSonNode));
                // 建立一个节点p存放ch
                p->data = ch;
                // 所有孩子指针初始化为NULL
                for (j = 0; j < MAX_SONS; j++) {
                    p->sons[j] = nullptr;
                }

                // 原为空树
                if (t == nullptr) {
                    t = p;
                }
                // 将其作为栈顶节点的一个孩子
                else {
                    St[top].nodep->sons[St[top].num] = p;
                }
                break;
        }
        i++;
        ch = str[i];
    }
    return t;
}

/**
 * 输出孩子链存储结构
 * @param t
 */
void DispTree(TSonNode *t) {
    int i;
    if (t != nullptr) {
        printf("%c", t->data);
        // t节点至少有一个孩子
        if (t->sons[0] != nullptr) {
            // 输出一个左括号
            printf("(");
            for (i = 0; i < MAX_SONS; i++) {
                DispTree(t->sons[i]);
                // 如果有下一个孩子
                if (t->sons[i + 1] != nullptr) {
                    //输出一个','
                    printf(",");
                }
                // 如果没有下一个孩子,退出循环
                else {
                    break;
                }
            }
            // 所有孩子输出结束，输出一个右括号
            printf(")");
        }
    }
}

/**
 * 销毁树t
 * @param t
 */
void DestroryTree(TSonNode *&t) {
    int i;
    if (t != nullptr) {
        for (i = 0; i < MAX_SONS; i++) {
            // 有子树
            if (t->sons[i] != nullptr)
                // 销毁该子树
                DestroryTree(t->sons[i]);
            // 再没有子树,退出循环
            else
                break;
        }
        // 释放根节点
        free(t);
    }
}

/**
 * 求树t高度
 * @param t
 * @return
 */
int TreeHeight1(TSonNode *t) {
    TSonNode *p;
    int i, h, maxh = 0;

    // 空树返回高度0
    if (t == nullptr) return 0;

    // 处理非空树
    for (i = 0; i < MAX_SONS; i++) {
        // p指向t的第i-1个孩子节点
        p = t->sons[i];
        // 若存在第i-1个孩子
        if (p != nullptr) {
            // 求出对应子树的高度
            h = TreeHeight1(p);
            // 求所有子树的最大高度
            if (maxh < h) maxh = h;
        }
    }
    // 返回子树高度加1
    return maxh + 1;
}

int main() {
    char str[] = "A(B,C(E,F,G),D)";
    TSonNode *t;
    t = CreateTree(str);

    printf("t:");
    DispTree(t);

    printf("\n树t的高度:%d\n", TreeHeight1(t));

    DestroryTree(t);
    return 0;
}

