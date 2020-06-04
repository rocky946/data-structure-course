#include <stdio.h>
#include <malloc.h>
#include "g_list.h"


int GLLength(GLNode *g) {
    int n = 0;
    // g1指向广义表的第一个元素
    GLNode *g1 = g->val.sublist;;

    // 扫描所有元素结点
    while (nullptr != g1) {
        n++;
        g1 = g1->link;
    }

    return n;
}

int GLDepth(GLNode *g) {
    int maxd = 0;
    int dep;

    // g为原子时返回0
    if (g->tag == 0) {
        return 0;
    }

    // g1指向广义表的第一个元素
    GLNode *g1 = g->val.sublist;
    //为空表时返回1
    if (nullptr == g1) {
        return 1;
    }

    // 遍历表中的每一个元素
    while (nullptr != g1) {
        // 元素若为子表，递归求出子表的深度
        if (g1->tag == 1) {
            dep = GLDepth(g1);
            // maxd为同一层的子表中深度的最大值
            if (dep > maxd) {
                maxd = dep;
            }
        }

        // g1指向下一个元素
        g1 = g1->link;
    }

    return maxd + 1;
}

void DispGL(GLNode *g) {
    if (nullptr != g) {
        // g为原子，输出原子值
        if (g->tag == 0) {
            printf("%c", g->val.data);
        }
        // g为子表
        else {
            printf("(");
            // 空表输出#
            if (nullptr == g->val.sublist) {
                printf("#");
            }
            // 非空子表
            else {
                // 递归输出子表
                DispGL(g->val.sublist);
            }
            printf(")");
        }

        if (nullptr != g->link) {
            printf(",");
            // 递归输出g的兄弟
            DispGL(g->link);
        }
    }
}

GLNode *CreateGL(char *s) {
    GLNode *g;

    char ch = *s++;

    if (ch != '\0') {
        g = (GLNode *) malloc(sizeof(GLNode));

        // 当前字符为左括号时
        if (ch == '(') {
            // 新结点作为表/表头结点
            g->tag = 1;
            // 递归构造子表并链接到表头结点
            g->val.sublist = CreateGL(s);
        }
        // 遇到'#'字符，表示空表
        else if (ch == '#') {
            g = nullptr;
        }
        // 为原子字符
        else {
            // 新结点作为原子结点
            g->tag = 0;
            g->val.data = ch;
        }
    }
    // 若s扫描完,g值为空
    else {
        g = nullptr;
    }

    // 取下一个字符
    ch = *s++;
    // s未扫描完，继续构造兄弟结点
    if (nullptr != g) {
        // 当前字符为','
        if (ch == ',') {
            // 递归构造兄弟结点
            g->link = CreateGL(s);
        } else {
            g->link = nullptr;
        }
    }

    return g;
}

void DestroyGL(GLNode *&g) {
    GLNode *g1, *g2;
    // g1指向广义表的第一个元素
    g1 = g->val.sublist;

    // 遍历所有元素
    while (nullptr != g1) {
        // 备份g1兄弟结点
        g2 = g1->link;
        // 若为原子结点
        if (g1->tag == 0) {
            // 释放g1所指的原子结点
            free(g1);
        }
        // 若为子表
        else {
            // 递归释放g1所指子表的空间
            DestroyGL(g1);
        }

        // g1继续指向后继兄弟结点
        g1 = g2;
    }

    // 最后释放头结点空间
    free(g);
}
