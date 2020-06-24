#include <stdio.h>
#include <malloc.h>
#include "adj_graph.h"

void CreateAdj(AdjGraph *&G, int A[MAXV][MAXV], int n, int e) {
    int i, j;
    ArcNode *p;
    G = (AdjGraph *) malloc(sizeof(AdjGraph));
    // 初始化邻接表中所有头结点的指针域为null
    for (i = 0; i < n; i++) {
        G->adjlist[i].firstarc = nullptr;
    }

    for (i = 0; i < n; i++) {
        for (j = n - 1; j >= 0; j--) {
            // 存在一条边
            if (A[i][j] != 0 && A[i][j] != INF) {
                // 创建一个结点p
                p = (ArcNode *) malloc(sizeof(ArcNode));
                // 存放邻接点编号
                p->adjvex = j;
                // 存放权
                p->weight = A[i][j];
                // 采用头插法插入结点p
                p->nextarc = G->adjlist[i].firstarc;
                G->adjlist[i].firstarc = p;
            }
        }
    }

    G->n = n;
    G->e = e;
}

void DispAdj(AdjGraph *G) {
    ArcNode *p;

    for (int i = 0; i < G->n; ++i) {
        p = G->adjlist[i].firstarc;
        printf("%3d: ", i);

        while (nullptr != p) {
            printf("%3d[%d]->", p->adjvex, p->weight);
            p = p->nextarc;
        }
        printf("^\n");
    }
}

void Destroy(AdjGraph *&G) {
    int i;
    ArcNode *pre, *p;

    for (i = 0; i < G->n; i++) {
        // pre指向第i个单链表的首结点
        pre = G->adjlist[i].firstarc;

        if (nullptr != pre) {
            p = pre->nextarc;
            // 释放第i个单链表的所有边结点
            while (nullptr != p) {
                free(pre);
                pre = p;
                p = p->nextarc;
            }
            free(pre);
        }
    }

    // 释放G
    free(G);
}
