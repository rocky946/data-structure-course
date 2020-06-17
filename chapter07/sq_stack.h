#ifndef CHAPTER03_SQ_STACK_H
#define CHAPTER03_SQ_STACK_H

#include "b_tree.h"

#define ST_MAX_SIZE 50

typedef BTNode *St_ElemType;

// 顺序栈类型
typedef struct {
    // 存放栈中的数据元素
    St_ElemType data[ST_MAX_SIZE];
    // 栈顶指针，即存放栈顶元素在data数组中的下标
    int top;
} SqStack;

/**
 * 初始化栈，构造一个空栈
 * @param stack
 */
void InitStack(SqStack *&stack);

/**
 * 销毁栈，释放栈占用的存储空间
 * @param stack
 */
void DestroyStack(SqStack *&stack);

/**
 * 判断栈是否为空，若空返回true
 * @param stack
 * @return
 */
bool StackEmpty(SqStack *stack);

/**
 * 进栈，将元素e插入到栈中
 * @param stack
 * @param e
 * @return
 */
bool Push(SqStack *&stack, St_ElemType e);

/**
 * 出栈，从栈中删除栈顶元素，并将其赋值给e
 * @param stack
 * @param e
 * @return
 */
bool Pop(SqStack *&stack, St_ElemType &e);

/**
 * 取栈顶元素，返回当前栈的栈顶元素，并将其赋值给e
 * @param stack
 * @param e
 * @return
 */
bool GetTop(SqStack *stack, St_ElemType &e);

#endif //CHAPTER03_SQ_STACK_H
