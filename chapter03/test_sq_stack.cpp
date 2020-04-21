#include <stdio.h>
#include "sq_stack.h"

int main() {
    SqStack *stack = nullptr;
    InitStack(stack);

    char e = 1;
    bool ret = false;
//    e = 2;
//    Push(stack, e);
//    e = 3;
//    Push(stack, e);

    Pop(stack, e);
    printf("Pop ret: %d, e: %d\n", ret, e);

    GetTop(stack, e);
    printf("GetTop ret: %d, e: %d\n", ret, e);

    DestroyStack(stack);

    return 0;
}