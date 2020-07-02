// 输出图G中从顶点u到v的长度为l的所有简单路径
#include <stdio.h>
#include "adj_graph.h"

// 全局visited数组
int visited[MAXV] = {0};

/**
 *  输出图G中从顶点u到v的所有简单路径
 * @param G
 * @param u
 * @param v
 * @param l
 * @param path
 * @param d 路径path中的路径长度，初始为-1
 */
void PathlenAll(AdjGraph *G, int u, int v, int l, int path[], int d) {
    // 置已访问标记
    visited[u] = 1;
    // 路径长度加1，顶点u加入到路径中
    d++;
    path[d] = u;

    // 找到一条路径后输出
    if (u == v && d == l) {
        for (int i = 0; i <= d; ++i) {
            printf("%d ", path[i]);
        }
        printf("\n");
    }

    ArcNode *p;
    int w;
    // p指向顶点u的第一个邻接点
    p = G->adjlist[u].firstarc;
    while (nullptr != p) {
        // w为顶点u的邻接点
        w = p->adjvex;
        // 若w顶点未访问，递归访问它
        if (visited[w] == 0) {
            PathlenAll(G, w, v, l, path, d);
        }
        // p指向顶点u的下一个邻接点
        p = p->nextarc;
    }

    // 恢复环境，使该顶点可重新使用
    visited[u] = 0;
}

int main() {
    int A[MAXV][MAXV] = {{0, 1, 0, 1, 1},
                         {1, 0, 1, 1, 0},
                         {0, 1, 0, 1, 1},
                         {1, 1, 1, 0, 1},
                         {1, 0, 1, 1, 0}};
    int n = 5, e = 8;

    AdjGraph *G;

    // 创建邻接表
    CreateAdj(G, A, n, e);
    // 输出邻接表
    DispAdj(G);

    int path[MAXV];
    printf("\nall path: \n");
    PathlenAll(G, 1, 4, 3, path, -1);

    printf("\nvisited: \n");
    for (int i = 0; i < 5; ++i) {
        printf("%d\n", visited[i]);
    }

    // 销毁邻接表
    Destroy(G);

    return 0;
}