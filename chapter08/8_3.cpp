// 判断无向图是否连通
#include <stdio.h>
#include "dfs.cpp"

/**
 * 判断无向图G的连通性
 * @param G
 * @return
 */
bool Connect(AdjGraph *G) {
    bool flag = true;

    // 从顶点0开始深度优先遍历
    DFS(G, 0);

    // 若有顶点没有被访问到，说明是不连通的
    for (int i = 0; i < G->n; ++i) {
        if (visited[i] == 0) {
            flag = false;
            break;
        }
    }

    return flag;
}


int main() {
    int A[MAXV][MAXV] = {{0, 1, 0, 1, 1, 0},
                         {1, 0, 1, 1, 0, 0},
                         {0, 1, 0, 1, 1, 0},
                         {1, 1, 1, 0, 1, 0},
                         {1, 0, 1, 1, 0, 0}};
    int n = 6, e = 8;

    AdjGraph *G;

    // 创建邻接表
    CreateAdj(G, A, n, e);
    // 输出邻接表
    DispAdj(G);

    bool flag = Connect(G);
    printf("\nflag: %d\n", flag);

    // 销毁邻接表
    Destroy(G);

    return 0;
}
