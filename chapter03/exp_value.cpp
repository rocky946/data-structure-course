// 简单表达式求值
#include <stdio.h>
#include "sq_stack.h"
#include "sq_stack_double.h"

/**
 * 将前缀表达式转换成后缀表达式
 * @param exp 前缀表达式
 * @param postExp 后缀表达式
 */
void Transfer(char *exp, char postExp[]) {
    // 运算符栈
    SqStack *optr = nullptr;
    InitStack(optr);
    // postExp下标
    int i = 0;

    char e;
    // 扫描exp
    while (*exp != '\0') {
        switch (*exp) {
            // 左括号：直接进栈
            case '(':
                Push(optr, *exp);
                exp++;
                break;
            // 右括号：将optr中的元素出栈，将遇到第一个'('之前的元素放到postExp中，然后将'('出栈
            case ')':
                while (!StackEmpty(optr)) {
                    Pop(optr, e);

                    if (e != '(') {
                        postExp[i++] = e;
                    } else {
                        break;
                    }
                }

                exp++;
                break;
            // +或-：出栈运算符并存放到postExp中，直到栈空或栈顶为'('，然后将*exp进栈
            case '+':
            case '-':
                while (!StackEmpty(optr)) {
                    GetTop(optr, e);

                    if (e != '(') {
                        postExp[i++] = e;
                        Pop(optr, e);
                    } else {
                        break;
                    }
                }

                Push(optr, *exp);
                exp++;
                break;
            // *或/：出栈运算符并存放到postExp中，直到栈空或者栈顶为'('/'+'/'-'，然后将*exp进栈
            case '*':
            case '/':
                while (!StackEmpty(optr)) {
                    GetTop(optr, e);

                    if (e == '*' || e == '/') {
                        postExp[i++] = e;
                        Pop(optr, e);
                    } else {
                        break;
                    }
                }

                Push(optr, *exp);
                exp++;
                break;
                // 数字字符：数字直接放到postExp中，并以'#'标识数字串结束
            default:
                // 数字
                while (*exp >= '0' && *exp <= '9') {
                    postExp[i++] = *exp;
                    exp++;
                }
                postExp[i++] = '#';
                break;
        }
    }

    // 扫描完exp，将optr中剩下的元素出栈放到postExp中
    while (!StackEmpty(optr)) {
        Pop(optr, e);
        postExp[i++] = e;
    }
    // 添加结束标识
    postExp[i] = '\0';
    DestroyStack(optr);
}

/**
 * 计算后缀表达式的值
 * @param postExp 后缀表达式
 * @return
 */
double ComputeValue(char *postExp) {
    double a, b, c, d, e;
    // 操作数栈
    SqStack_d *opnd = nullptr;
    InitStack_d(opnd);

    // 扫描postExp
    while (*postExp != '\0') {
        switch (*postExp) {
            case '+':
                Pop_d(opnd, a);
                Pop_d(opnd, b);
                c = b + a;
                // 计算结果进栈
                Push_d(opnd, c);
                break;
            case '-':
                Pop_d(opnd, a);
                Pop_d(opnd, b);
                c = b - a;
                // 计算结果进栈
                Push_d(opnd, c);
                break;
                break;
            case '*':
                Pop_d(opnd, a);
                Pop_d(opnd, b);
                c = b * a;
                // 计算结果进栈
                Push_d(opnd, c);
                break;
                break;
            case '/':
                Pop_d(opnd, a);
                Pop_d(opnd, b);

                if (a != 0) {
                    c = b / a;
                    // 计算结果进栈
                    Push_d(opnd, c);
                } else {
                    printf("除数为0\n");
                }
                break;
            default:
                d = 0;
                // 将连续的数字字符转换成对应的数值
                while (*postExp >= '0' && *postExp <= '9') {
                    d = 10 * d + *postExp - '0';
                    postExp++;
                }

                // 数值进栈
                Push_d(opnd, d);
                break;
        }
        postExp++;
    }

    GetTop_d(opnd, e);
    DestroyStack_d(opnd);
    return e;
}

int main() {
    char exp[] = "(56-20)/(4+2)";
    char postExp[MAX_SIZE];
    Transfer(exp, postExp);
    printf("中缀表达式：%s\n", exp);
    printf("后缀表达式：%s\n", postExp);
    printf("表达式的值：%g\n", ComputeValue(postExp));

    return 0;
}