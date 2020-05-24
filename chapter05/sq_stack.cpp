#include <stdio.h>
#include <malloc.h>
#include "sq_stack.h"

void InitStack(SqStack *&stack) {
    stack = (SqStack *) malloc(sizeof(SqStack));
    // 栈顶指针置为-1
    stack->top = -1;
}

void DestroyStack(SqStack *&stack) {
    free(stack);
}

bool StackEmpty(SqStack *stack) {
    return stack->top == -1;
}

bool Push(SqStack *&stack, ElemType e) {
    // 栈满，即栈上溢出
    if (stack->top == MAX_SIZE-1) {
        return false;
    }

    //栈顶指针加1
    stack->top++;
    // 将元素e放在栈顶指针处
    stack->data[stack->top] = e;

    return true;
}

bool Pop(SqStack *&stack, ElemType &e) {
    // 栈空
    if (stack->top == -1) {
        return false;
    }

    e = stack->data[stack->top];
    stack->top--;

    return true;
}

bool GetTop(SqStack *stack, ElemType &e) {
    // 栈空
    if (stack->top == -1) {
        return false;
    }

    e = stack->data[stack->top];

    return true;
}
