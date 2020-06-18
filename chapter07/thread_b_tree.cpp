// 中序线索二叉树算法
#include <stdio.h>
#include <malloc.h>

#define MAX_SIZE 100
typedef char ElemType;

// 线索二叉树结点类型
typedef struct node {
    // 结点数据域
    ElemType data;
    // 线索标记
    int ltag, rtag;
    // 左孩子或线索指针
    struct node *lchild;
    // 右孩子或线索指针
    struct node *rchild;
} TBTNode;

void CreateTBTree(TBTNode *&b, char *str) {
    // St数组作为顺序栈
    TBTNode *St[MAX_SIZE];
    TBTNode *p = nullptr;
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
                p = (TBTNode *) malloc(sizeof(TBTNode));
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

void DisplayTBTree(TBTNode *b) {
    if (nullptr != b) {
        printf("%c", b->data);

        // 有孩子结点时才输出'('
        if (nullptr != b->lchild || nullptr != b->rchild) {
            printf("(");
            // 递归处理左子树
            DisplayTBTree(b->lchild);

            // 有右孩子结点时才输出','
            if (nullptr != b->rchild) {
                printf(",");
            }

            // 递归处理右子树
            DisplayTBTree(b->rchild);

            // 有孩子结点时才输出','
            printf(")");
        }
    }
}

// 全局变量
TBTNode *pre;

/**
 * 对二叉树p进行中序线索化
 * @param p
 */
void Thread(TBTNode *&p) {
    if (nullptr != p) {
        // 左子树线索化
        Thread(p->lchild);

        // 左子树不存在，进行前驱结点线索化
        if (nullptr == p->lchild) {
            p->lchild = pre;
            p->ltag = 1;
        } else {
            p->ltag = 0;
        }

        // 对pre的后继结点线索化
        if (nullptr == pre->rchild) {
            pre->rchild = p;
            pre->rtag = 1;
        } else {
            pre->rtag = 0;
        }
        pre = p;

        // 右子树线索化
        Thread(p->rchild);
    }
}

/**
 * 中序线索化二叉树
 * @param b
 * @return
 */
TBTNode *CreateThread(TBTNode *b) {
    TBTNode *root;
    // 创建头结点
    root = (TBTNode *) malloc(sizeof(TBTNode));
    root->ltag = 0;
    root->rtag = 1;
    root->rchild = b;

    // 空二叉树,root->lchild指向自身
    if (nullptr == b) {
        root->lchild = root;
    } else {
        root->lchild = b;
        // 结点p的前驱结点
        pre = root;
        // 中序遍历线索化二叉树
        Thread(b);
        // 最后处理，加入指向头结点的线索
        pre->rchild = root;
        pre->rtag = 1;
        // 头结点右线索化
        root->rchild = pre;
    }

    return root;
}

/**
 * 销毁去掉头结点的线索二叉树
 * @param b
 */
void DestroyTBTree1(TBTNode *&b) {
    // b有左孩子，销毁左子树
    if (b->ltag == 0) {
        DestroyTBTree1(b->lchild);
    }

    // b有右孩子，销毁右子树
    if (b->rtag == 0) {
        DestroyTBTree1(b->rchild);
    }
    free(b);
}

/**
 * 销毁带头结点的中序线索树
 * @param tb
 */
void DestroyTBTree(TBTNode *&tb) {
    // 释放以tb->lchild为根结点的树
    DestroyTBTree1(tb->lchild);
    // 释放头结点
    free(tb);
}

/**
 * 遍历中序线索二叉树
 * @param tb 中序线索二叉树头结点
 */
void ThInOrder(TBTNode *tb) {
    // p指向根结点
    TBTNode *p = tb->lchild;

    while (p != tb) {
        // 找开始结点
        while (p->ltag == 0) {
            p = p->lchild;
        }

        // 访问开始结点
        printf("%c", p->data);

        while (p->rtag == 1 && p->rchild != tb) {
            p = p->rchild;
            printf("%c", p->data);
        }

        p = p->rchild;
    }
}

int main() {
    char str[] = "A(B(D(,G)),C(E,F))";
    TBTNode *b;
    CreateTBTree(b, str);
    printf("disp: ");
    DisplayTBTree(b);

    printf("\n");
    TBTNode *tb = CreateThread(b);
    printf("线索中序序列：");
    ThInOrder(tb);
    printf("\n");

    DestroyTBTree(tb);

    return 0;
}