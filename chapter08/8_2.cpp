// 邻接矩阵和邻接表的相互转换
#include <stdio.h>
#include <malloc.h>
#include "mat_graph.h"
#include "adj_graph.h"

/**
 * 将邻接矩阵g转换成邻接表G
 * @param g 
 * @param G 
 */
void MatToList(MatGraph g, AdjGraph *&G) {
    int i, j;
    ArcNode *p;
    G = (AdjGraph *) malloc(sizeof(AdjGraph));
    // 初始化邻接表中所有头结点的指针域为null
    for (i = 0; i < g.n; i++) {
        G->adjlist[i].firstarc = nullptr;
    }

    for (i = 0; i < g.n; i++) {
        for (j = g.n - 1; j >= 0; j--) {
            // 存在一条边
            if (g.edges[i][j] != 0 && g.edges[i][j] != INF) {
                // 创建一个结点p
                p = (ArcNode *) malloc(sizeof(ArcNode));
                // 存放邻接点编号
                p->adjvex = j;
                // 存放权
                p->weight = g.edges[i][j];
                // 采用头插法插入结点p
                p->nextarc = G->adjlist[i].firstarc;
                G->adjlist[i].firstarc = p;
            }
        }
    }

    G->n = g.n;
    G->e = g.e;
}

/**
 * 将邻接表G转换成邻接矩阵g
 * @param G
 * @param g
 */
void ListToMat(AdjGraph *G, MatGraph &g) {
    int i;
    ArcNode *p;

    // 扫描所有的单链表
    for (i = 0; i < G->n; i++) {
        // p指向第i个单链表的首结点
        p = G->adjlist[i].firstarc;

        // 扫描第i个单链表
        while (nullptr != p) {
            g.edges[i][p->adjvex] = p->weight;
            p = p->nextarc;
        }
    }

    g.n = G->n;
    g.e = G->e;
}

int main() {
    int A[MAXV][MAXV] = {{0, 1, 0, 1, 1},
                         {1, 0, 1, 1, 0},
                         {0, 1, 0, 1, 1},
                         {1, 1, 1, 0, 1},
                         {1, 0, 1, 1, 0}};
    int n = 5, e = 8;

    MatGraph g;
    // 创建邻接矩阵
    CreateMat(g, A, n, e);
    // 输出邻接矩阵
    printf("g: \n");
    DispMat(g);

    AdjGraph *G = nullptr;
    // g->G
    MatToList(g, G);
    // 输出邻接表G
    printf("to G: \n");
    DispAdj(G);

    // 创建邻接表G
    CreateAdj(G, A, n, e);
    // 输出邻接表G
    printf("G: \n");
    DispAdj(G);

    // G->g
    ListToMat(G, g);
    // 输出邻接矩阵
    printf("to g: \n");
    DispMat(g);

    // 销毁邻接表G
    Destroy(G);

    return 0;
}