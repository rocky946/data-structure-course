#include <stdio.h>
#include "sq_stack.h"

/**
 * 判断str是否为对称串
 * @param str
 * @return
 */
bool Symmetry(ElemType str[]) {
    SqStack *stack = nullptr;
    InitStack(stack);

    int i = 0;
    while (str[i] != '\0') {
        Push(stack, str[i]);
        i++;
    }

    int j = 0;
    ElemType e;
    while (!StackEmpty(stack)) {
        Pop(stack, e);

        if (str[j] != e) {
            DestroyStack(stack);
            return false;
        }
        j++;
    }

    DestroyStack(stack);
    return true;
}

int main() {
    ElemType e[6] = {'2', '2', '3', '2', '1', '\0'};

    bool ret = Symmetry(e);
    printf("ret: %d\n", ret);

    return 0;
}