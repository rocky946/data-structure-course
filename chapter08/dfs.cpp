// 图的深度优先遍历算法
#include <stdio.h>
#include "adj_graph.h"

// 全局visited数组
int visited[MAXV] = {0};

/**
 * 深度优先遍历算法
 * @param G
 * @param v 初始顶点编号
 */
void DFS(AdjGraph *G, int v) {
    ArcNode *p;

    // 访问起点，置已访问标记
    visited[v] = 1;
    printf("%d ", v);

    // p指向顶点v的第一个邻接点
    p = G->adjlist[v].firstarc;
    while (nullptr != p) {
        // 若p->adjvex顶点未被访问，递归访问它
        if (visited[p->adjvex] == 0) {
            DFS(G, p->adjvex);
        }

        // p指向顶点v的下一个邻接点
        p = p->nextarc;
    }
}

int main1() {
    int A[MAXV][MAXV] = {{0, 1, 0, 1, 1},
                         {1, 0, 1, 1, 0},
                         {0, 1, 0, 1, 1},
                         {1, 1, 1, 0, 1},
                         {1, 0, 1, 1, 0}};
    int n = 6, e = 8;

    AdjGraph *G;

    // 创建邻接表
    CreateAdj(G, A, n, e);
    // 输出邻接表
    DispAdj(G);

    // DFS
    printf("DFS: ");
    DFS(G, 2);

    // 销毁邻接表
    Destroy(G);

    return 0;
}