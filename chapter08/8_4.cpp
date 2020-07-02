// 判断图G中从顶点u到v中是否存在简单路径
#include <stdio.h>
#include "adj_graph.h"

// 全局visited数组
int visited[MAXV] = {0};

/**
 * 判断图G中从顶点u到v中是否存在简单路径
 * @param G
 * @param u
 * @param v
 * @param has u到v是否有路径，初值为false
 */
void ExistPath(AdjGraph *G, int u, int v, bool &has) {
    // has为false才去找
    if (!has) {
        // 置已访问标记
        visited[u] = 1;

        // 找到了一条路径,置has为true并返回
        if (u == v) {
            has = true;
            return;
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
                ExistPath(G, w, v, has);
            }
            // p指向顶点u的下一个邻接点
            p = p->nextarc;
        }
    }
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

    bool has = false;
    ExistPath(G, 1, 3, has);
    printf("has : %d\n", has);

    printf("visited: \n");
    for (int i = 0; i < 5; ++i) {
        printf("%d\n", visited[i]);
    }

    // 销毁邻接表
    Destroy(G);

    return 0;
}