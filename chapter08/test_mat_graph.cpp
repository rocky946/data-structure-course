#include <stdio.h>
#include "mat_graph.h"


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
    DispMat(g);

    return 0;
}
