#include <stdio.h>
#include "adj_graph.h"

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
    // 销毁邻接表
    Destroy(G);


    return 0;
}