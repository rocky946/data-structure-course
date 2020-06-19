// 孩子兄弟链存储结构下树的基本运算算法和求树t的高度
#include <stdio.h>
#include <malloc.h>
#define MAX_SIZE 100

// 孩子兄弟链存储结构类型
typedef struct tnode {
    // 节点的值
    char data;
    // 指向兄弟
    struct tnode *hp;
    // 指向孩子节点
    struct tnode *vp;
} TSBNode;

/**
 * 由str建立孩子兄弟链存储结构
 * @param str
 * @return
 */
TSBNode *CreateTree(char *str) {
    // 顺序栈
    struct {
        // 节点指针
        TSBNode *nodep;
        // 孩子个数
        int num;
    } St[MAX_SIZE];

    // 栈顶指针
    int top = -1;
    int i = 0, j;
    char ch = str[i];
    TSBNode *t = nullptr, *p = nullptr, *q;
    while (ch != '\0') {
        switch (ch) {
            case '(':
                // 有孩子，当前节点p进栈
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
                // 建立一个节点p存放ch
                p = (TSBNode *) malloc(sizeof(TSBNode));
                p->data = ch;
                p->hp = p->vp = nullptr;

                // 原为空树
                if (t == nullptr) {
                    t = p;
                }
                // 将其作为栈顶节点的一个孩子
                else {
                    // 第一个孩子用vp指向它
                    if (St[top].num == 0) {
                        St[top].nodep->vp = p;
                    }
                    // 其他孩子用栈顶节点的孩子节点的hp指向它
                    else {
                        q = St[top].nodep->vp;
                        for (j = 1; j < St[top].num; j++) {
                            q = q->hp;
                        }
                        q->hp = p;
                    }
                }
                break;
        }
        i++;
        ch = str[i];
    }
    return t;
}

/**
 * 输出孩子兄弟链存储结构
 * @param t
 */
void DispTree(TSBNode *t) {
    TSBNode *p;
    if (t != nullptr) {
        printf("%c", t->data);
        // 有孩子时输出一个'('
        if (t->vp != nullptr) {
            printf("(");
            // p指向节点t的第一个孩子
            p = t->vp;
            while (p != nullptr) {
                DispTree(p);
                p = p->hp;
                if (p != nullptr)
                    printf(",");
            }
            // 输出一个')'
            printf(")");
        }
    }
}

/**
 * 销毁树t
 * @param t
 */
void DestroryTree(TSBNode *&t) {
    if (t != nullptr) {
        DestroryTree(t->vp);
        DestroryTree(t->hp);
        // 释放根节点
        free(t);
    }
}

/**
 * 求树t高度
 * @param t 
 * @return 
 */
int TreeHeight2(TSBNode *t) {
    TSBNode *p;
    int h, maxh = 0;
    // 空树返回0
    if (t == nullptr) return 0;

    // 非空树,指向第1个孩子节点
    p = t->vp;
    // 扫描t的所有子树
    while (p != nullptr) {
        // 求出p子树的高度
        h = TreeHeight2(p);
        // 求所有子树的最大高度
        if (maxh < h) maxh = h;
        // 继续处理t的其他子树
        p = p->hp;
    }

    // 返回子树高度加1
    return maxh + 1;
}

int main() {
    char str[] = "A(B,C(E,F,G),D)";
    TSBNode *t;
    t = CreateTree(str);
    
    printf("t:");
    DispTree(t);
    
    printf("\n树t的高度:%d\n", TreeHeight2(t));
    
    DestroryTree(t);
    return 1;
}
