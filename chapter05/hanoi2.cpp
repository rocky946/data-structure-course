// 非递归求解汉诺塔问题
#include <stdio.h>
#include "sq_stack.h"

/**
 *
 * @param n 盘片数量
 * @param x 原始塔
 * @param y 中间塔
 * @param z 目标塔
 */
void Hanoi2(int n, char x, char y, char z) {
    // 定义顺序栈指针
    SqStack *stack;
    // 子任务
    ElemType e, e1, e2, e3;

    // 参数错误时直接返回
    if (n <= 0) return;

    // 初始化栈
    InitStack(stack);
    e.n = n;
    e.x = x;
    e.y = y;
    e.z = z;
    e.flag = false;
    Push(stack, e);

    // 栈不空循环
    while (!StackEmpty(stack)) {
        // 出栈元素
        Pop(stack, e);

        // 不能直接移动盘片
        if (!e.flag) {
            e1.n = e.n - 1;
            e1.x = e.y;
            e1.y = e.x;
            e1.z = e.z;
            if (e1.n == 1)
                e1.flag = true;
            // 有一个以上盘片时不能直接移动
            else
                e1.flag = false;
            // 处理Hanoi(n-1,y,x,z)步骤
            Push(stack, e1);

            e2.n = e.n;
            e2.x = e.x;
            e2.y = e.y;
            e2.z = e.z;
            e2.flag = true;
            // 处理move(n,x,z)步骤
            Push(stack, e2);

            e3.n = e.n - 1;
            e3.x = e.x;
            e3.y = e.z;
            e3.z = e.y;
            // 只有一个盘片时可直接移动
            if (e3.n == 1)
                e3.flag = true;
            // 有一个以上盘片时不能直接移动
            else
                e3.flag = false;
            // 处理Hanoi(n-1,x,z,y)步骤
            Push(stack, e3);
        }
        // 可以直接移动
        else {
            printf("\t将第%d个盘片从%c移动到%c\n", e.n, e.x, e.z);
        }
    }
}

int main() {
    int n = 3;

    Hanoi2(n, 'X', 'Y', 'Z');

    return 0;
}