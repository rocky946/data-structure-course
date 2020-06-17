// 采用后序遍历非递归算法输出从根节点到每个叶子节点的路径逆序列
#include "sq_stack.h"
#include <stdio.h>

void AllPath1(BTNode *b) {
    BTNode *p, *r;
    bool flag;
    // 定义栈指针st
    SqStack *st;
    // 初始化栈st
    InitStack(st);
    p = b;

    do {
        // 访问结点p及其所有左下结点并进栈
        while (nullptr != p) {
            // 结点p进栈
            Push(st, p);
            // 移动到左孩子
            p = p->lchild;
        }

        // r指向刚访问的结点，初始时为空
        r = nullptr;
        // flag为栈表示正在处理栈顶结点
        flag = true;
        while (!StackEmpty(st) && flag) {
            // 取当前栈顶结点p
            GetTop(st, p);
            // 若结点p的右孩子为空或者为刚刚访问过的结点
            if (p->rchild == r) {
                // 若p为叶子结点
                if (nullptr == p->lchild && nullptr == p->rchild) {
                    // 输出栈中的所有结点值
                    for (int i = st->top; i > 0; i--) {
                        printf("%c->", st->data[i]->data);
                    }
                    printf("%c\n", st->data[0]->data);
                }

                // 出栈p
                Pop(st, p);
                // r指向刚访问过得结点
                r = p;
            }
                // 转向处理其右子树
            else {
                p = p->rchild;
                // 表示当前不是处理栈顶结点
                flag = false;
            }
        }
    }
        // 栈不空循环
    while (!StackEmpty(st));
}

int main() {
    char str[] = "A(B(D(,G)),C(E,F))";
    BTNode *b;
    CreateBTree(b, str);
    printf("disp: ");
    DisplayBTree(b);

    printf("所有叶子结点到根节点的序列:\n");
    AllPath1(b);

    DestroyBTree(b);

    return 0;
}