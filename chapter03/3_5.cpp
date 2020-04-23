// 设计一个算法判断输入的表达式中括号是否配对（假设只含有左、右圆括号）
#include <stdio.h>
#include "linked_stack.h"

/**
 * 匹配括号
 * @param exp 表达式 数组
 * @param n 表达式数组长度
 * @return
 */
bool Match(char exp[], int n) {
    bool match = true;

    int i =0;
    ElemType e;

    LinkStNode *stack = nullptr;
    InitStack(stack);

    // 扫描exp中的所有字符
    while (i < n && match) {
        // 当前字符为左括号，进栈
        if (exp[i] == '(') {
            Push(stack, exp[i]);
        }
        // 当前字符为右括号,此时判断是否为右括号便于以后扩展，如匹配其他类型括号
        else if (exp[i] == ')') {
            // 取栈顶元素
            if (GetTop(stack, e)) {
                // 栈顶元素不为'('，匹配失败
                if ('(' != e) {
                    match = false;
                }
                // 栈顶元素为'('，出栈
                else {
                    Pop(stack, e);
                }
            }
            // 取栈顶元素失败
            else {
                match = false;
            }
        }
        // 继续处理其他字符
        i++;
    }

    // 最终栈空表示匹配成功
    if (!StackEmpty(stack)) {
        match = false;
    }

    DestroyStack(stack);
    return match;
}

int main() {

    char exp[] = {'(', '(', ')', ')', '(', ')'};

    int n = sizeof(exp) / sizeof(exp[0]);
    printf("match: %d\n", Match(exp, n));

    return 0;
}