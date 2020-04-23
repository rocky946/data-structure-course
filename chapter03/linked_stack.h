#ifndef CHAPTER03_LINKED_STACK_H
#define CHAPTER03_LINKED_STACK_H

typedef char ElemType;

typedef struct LNode {
    // 数据域
    ElemType data;
    // 指针域
    struct LNode *next;
} LinkStNode;

/**
 * 初始化栈
 * @param stack
 */
void InitStack(LinkStNode *&stack);

/**
 * 销毁栈
 * @param stack
 */
void DestroyStack(LinkStNode *&stack);

/**
 * 判断栈是否为空
 * @param stack
 * @return
 */
bool StackEmpty(LinkStNode *stack);

/**
 * 进栈
 * @param stack
 * @param e
 */
void Push(LinkStNode *&stack, ElemType e);

/**
 * 出栈
 * @param stack
 * @param e
 * @return
 */
bool Pop(LinkStNode *&stack, ElemType &e);

/**
 * 取栈顶元素
 * @param stack
 * @param e
 * @return
 */
bool GetTop(LinkStNode *stack, ElemType &e);

#endif //CHAPTER03_LINKED_STACK_H
