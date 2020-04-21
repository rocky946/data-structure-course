// 序列1...n按照顺序依次进栈，判断出栈序列a[0...n-1]是否合法
#include <stdio.h>
#include "sq_stack.h"

bool ValidSeq(const int a[], int n) {
    bool flag;

    SqStack *stack = nullptr;
    InitStack(stack);

    ElemType e;
    int k = 0;

    for (int i = 1; i <= n; ++i) {
        // 序列1..n按照序列进栈
        Push(stack, i);

        while (!StackEmpty(stack)) {
            GetTop(stack, e);
            // 匹配就出栈
            if (a[k] == e) {
                Pop(stack, e);
                k++;
            } else {
                // 不匹配退出while循环
                break;
            }
        }
    }

    flag = StackEmpty(stack);
    DestroyStack(stack);
    return flag;
}

int main() {
    int a[] = {1, 2, 3, 4, 5};

    bool flag = ValidSeq(a, 5);
    printf("flag: %d\n", flag);

    return 0;
}