#include <stdio.h>
#include "linked_stack.h"

int main() {
    LinkStNode *stack = nullptr;
    InitStack(stack);

    int ret;
    ret = StackEmpty(stack);
    printf("init empty: %d\n", ret);

    Push(stack, 1);
    Push(stack, 2);
    Push(stack, 3);

    ret = StackEmpty(stack);
    printf("push empty: %d\n", ret);

    ElemType e;
    GetTop(stack, e);
    printf("get top: %d\n", e);

    while (!StackEmpty(stack)) {
        Pop(stack, e);
        printf("pop: %d\n", e);
    }

    ret = StackEmpty(stack);
    printf("pop empty: %d\n", ret);

    DestroyStack(stack);

    return 0;

}