#include <stdio.h>
#include <malloc.h>
#include "table_link.h"

void CreateTable(HList *&h) {
    // 指向尾结点
    DList *r = nullptr;
    // 指向新创建结点
    DList *p = nullptr;

    // 创建头结点
    h = (HList *) malloc(sizeof(HList));
    h->next = nullptr;

    printf("请输入表的行数，列数：");
    scanf("%d %d", &h->row, &h->col);

    for (int i = 0; i < h->row; ++i) {
        printf("\t请输入%d行数据：", i + 1);
        // 创建数据结点
        p = (DList *) malloc(sizeof(DList));
        for (int j = 0; j < h->col; ++j) {
            scanf("%d", &p->data[j]);
        }

        // 插入第一个数据结点
        if (nullptr == h->next) {
            h->next = p;
        } else {
            r->next = p;
        }

        // r始终指向尾结点
        r = p;
    }
    // 尾插法建立单链表最终r next置为空
    r->next = nullptr;
}

void DestroyTable(HList *&h) {
    DList *pre = h->next;
    DList *p = pre->next;

    while (nullptr != p) {
        free(pre);
        pre = p;
        p = p->next;
    }

    free(pre);
    free(h);
}

void DispTable(HList *h) {
    DList *p = h->next;

    while (nullptr != p) {
        for (int i = 0; i < h->col; ++i) {
            printf("%4d", p->data[i]);
        }
        printf("\n");
        p = p->next;
    }
    printf("\n");
}

void LinkTable(HList *h1, HList *h2, HList *&h) {
    int i, j;
    printf("请输入连接字段：第一个表序号，第2个表序号：");
    scanf("%d %d", &i, &j);

    // 创建结果表头结点
    h = (HList *) malloc(sizeof(HList));
    // 列数尾h1和h2的列数之和
    h->col = h1->col + h2->col;
    // 行数
    h->row = 0;
    h->next = nullptr;

    // 指向h1第一个数据结点
    DList *p = h1->next;
    // 指向h2数据结点
    DList *q = nullptr;

    // 指向新建结点
    DList *s = nullptr;
    // 指向尾结点
    DList *r = nullptr;

    int k = 0;
    // 遍历表1
    while (nullptr != p) {
        q = h2->next;

        // 遍历表2
        while (nullptr != q) {
            // 满足连接条件
            if (p->data[i - 1] == q->data[j - 1]) {
                // 创建新结点
                s = (DList *) malloc(sizeof(DList));

                // 将表1数据复制到新表
                for (k = 0; k < h1->col; ++k) {
                    s->data[k] = p->data[k];
                }
                // 将表2数据复制到新表
                for (k = 0; k < h2->col; ++k) {
                    s->data[h1->col + k] = q->data[k];
                }

                // 第一个数据结点
                if (nullptr == h->next) {
                    h->next = s;
                } else {
                    r->next = s;
                }

                // r指向尾结点
                r = s;
                h->row++;
            }
            q = q->next;
        }
        p = p->next;
    }

    // 尾结点next置为空
    if (nullptr != r)
        r->next = nullptr;
}
