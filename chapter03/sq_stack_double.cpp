#include <stdio.h>
#include <malloc.h>
#include "sq_stack_double.h"

void InitStack_d(SqStack_d *&stack_d) {
    stack_d = (SqStack_d *) malloc(sizeof(SqStack_d));
    // 栈顶指针置为-1
    stack_d->top = -1;
}

void DestroyStack_d(SqStack_d *&stack_d) {
    free(stack_d);
}

bool StackEmpty_d(SqStack_d *stack_d) {
    return stack_d->top == -1;
}

bool Push_d(SqStack_d *&stack_d, ElemType_d e) {
    // 栈满，即栈上溢出
    if (stack_d->top == MAX_SIZE-1) {
        return false;
    }

    //栈顶指针加1
    stack_d->top++;
    // 将元素e放在栈顶指针处
    stack_d->data[stack_d->top] = e;

    return true;
}

bool Pop_d(SqStack_d *&stack_d, ElemType_d &e) {
    // 栈空
    if (stack_d->top == -1) {
        return false;
    }

    e = stack_d->data[stack_d->top];
    stack_d->top--;

    return true;
}

bool GetTop_d(SqStack_d *stack_d, ElemType_d &e) {
    // 栈空
    if (stack_d->top == -1) {
        return false;
    }

    e = stack_d->data[stack_d->top];

    return true;
}
