// 拓扑排序算法
#include <stdio.h>
#include "adj_graph.h"

/**
 * 拓扑排序
 * @param G
 */
void TopSort(AdjGraph *G) {
    int i, j;
    // 栈St的指针为top
    int St[MAXV], top = -1;

    ArcNode *p;
    // 入度置初值0
    for (i = 0; i < G->n; i++) {
        G->adjlist[i].count = 0;
    }

    // 求所有顶点的入度
    for (i = 0; i < G->n; i++) {
        p = G->adjlist[i].firstarc;
        while (nullptr != p) {
            G->adjlist[p->adjvex].count++;
            p = p->nextarc;
        }
    }

    // 将入度为0的顶点进栈
    for (i = 0; i < G->n; i++) {
        if (G->adjlist[i].count == 0) {
            top++;
            St[top] = i;
        }
    }

    // 栈不空循环
    while (top > -1) {
        // 出栈一个顶点i
        i = St[top];
        top--;
        // 输出该顶点
        printf("%d", i);

        // 找第一个邻接点
        p = G->adjlist[i].firstarc;
        // 将顶点i的出边邻接点的入度减1
        while (nullptr != p) {
            j = p->adjvex;
            G->adjlist[j].count--;

            // 将入度为0的邻接点进栈
            if (G->adjlist[j].count == 0) {
                top++;
                St[top] = j;
            }

            // 找下一个邻接点
            p = p->nextarc;
        }
    }
}

int main() {
    AdjGraph *G;
    int A[MAXV][MAXV] =
            {{0,   1,   INF, INF, INF, INF},
             {INF, 0,   1,   INF, INF, INF},
             {INF, INF, 0,   1,   INF, INF},
             {INF, INF, INF, 0,   INF, INF},
             {INF, 1,   INF, INF, 0,   1},
             {INF, INF, INF, 1,   INF, 0}};
    int n = 6, e = 6;

    // 建立《教程》中图8.44的邻接表
    CreateAdj(G, A, n, e);
    printf("图G的邻接表:\n");
    // 输出邻接表G
    DispAdj(G);

    printf("拓扑序列:");
    TopSort(G);
    printf("\n");

    // 销毁邻接表
    Destroy(G);

    return 0;
}