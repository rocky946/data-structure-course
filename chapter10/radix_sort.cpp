// 基数排序算法
#include <stdio.h>
#include "seq_list.h"
#include <string.h>
#include <malloc.h>

// 线性表中最多元素个数
#define MAXE 20
// 基数的最大取值
#define MAXR 10
// 关键字位数的最大取值
#define MAXD 8

// 基数排序数据的结点类型
typedef struct node {
    // 记录的关键字定义的字符串
    // data[0..MAXD-1]依次存放关键字的低位到高位的各数字字符
    char data[MAXD];
    // 指向下一个结点
    struct node *next;
} NodeType;

/**
 * 采用后插法创建链表
 * @param p
 * @param a
 * @param n
 */
void CreateList(NodeType *&p, char a[MAXE][MAXD], int n) {
    int i;
    NodeType *s = nullptr, *t = nullptr;
    for (i = 0; i < n; i++) {
        s = (NodeType *) malloc(sizeof(NodeType));
        strcpy(s->data, a[i]);
        if (i == 0) {
            p = s;
            t = s;
        } else {
            t->next = s;
            t = s;
        }
    }
    if (nullptr != t)
        t->next = nullptr;
}

/**
 * 输出链表
 * @param p
 */
void DispList(NodeType *p) {
    while (nullptr != p) {
        printf("%c%c ", p->data[1], p->data[0]);
        p = p->next;
    }
    printf("\n");
}

/**
 * 基数排序
 * @param p 待排序序列的单列表首结点指针
 * @param r 基数
 * @param d 实际关键字位数
 */
void RadixSort(NodeType *&p, int r, int d) {
    // 定义各链队的首尾指针
    NodeType *head[MAXR], *tail[MAXR], *t;
    int i, j, k;
    // 从低位到高位循环
    for (i = 0; i <= d - 1; i++) {
        // 初始化各链队的首、尾指针
        for (j = 0; j < r; j++) {
            head[j] = tail[j] = nullptr;
        }

        // 分配：对于原链表中的每个结点循环
        while (nullptr != p) {
            // 找第k个链队
            k = p->data[i] - '0';
            // 第k个链队空时，队头、队尾均指向结点p
            if (nullptr == head[k]) {
                head[k] = p;
                tail[k] = p;
            }
            // 第k个链队非空时结点p进队
            else {
                tail[k]->next = p;
                tail[k] = p;
            }
            // 取下一个待排序的元素
            p = p->next;
        }

        // 重新用p来收集所有结点
        p = t = nullptr;

        // 收集：对于每一个链队循环
        for (j = 0; j < r; j++) {
            if (nullptr != head[j]) {
                // 若第j个链队是第一个非空链队
                if (nullptr == p) {
                    p = head[j];
                    t = tail[j];
                }
                // 若第j个链队是其他非空链队
                else {
                    t->next = head[j];
                    t = tail[j];
                }
            }
        }
        // 最后一个结点的next域置null
        if(nullptr != t)
            t->next = nullptr;
    }
}

int main() {
    int n = 10, r = 10, d = 2;
    int i, j, k;
    NodeType *p;
    char a[MAXE][MAXD];
    int b[] = {75, 23, 98, 44, 57, 12, 29, 64, 38, 82};

    // 将b[i]转换成字符串
    for (i = 0; i < n; i++) {
        k = b[i];
        for (j = 0; j < d; j++) {
            a[i][j] = k % 10 + '0';
            k = k / 10;
        }
        a[i][j] = '\0';
    }

    CreateList(p, a, n);
    printf("\n");
    printf("  初始关键字\t");
    // 输出初始关键字序列
    DispList(p);
    RadixSort(p, 10, 2);
    printf("  最终结果\t");
    // 输出最终结果
    DispList(p);
    printf("\n");

    return 0;
}