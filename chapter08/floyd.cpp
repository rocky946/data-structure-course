// Floyd算法
#include <stdio.h>
#include "mat_graph.h"

/**
 * 输出多源最短路径
 * @param g
 * @param A
 * @param path
 */
void Dispath(MatGraph g, int A[][MAXV], int path[][MAXV]) {
    int i, j, k, s;
    // 存放一条最短路径中间顶点(反向)及其顶点个数
    int apath[MAXV], d;

    for (i = 0; i < g.n; i++) {
        for (j = 0; j < g.n; j++) {
            // 若顶点i和j之间存在路径
            if (A[i][j] != INF && i != j) {
                printf("从%d到%d的路径为: ", i, j);
                k = path[i][j];
                // 路径上添加终点
                d = 0;
                apath[d] = j;
                // 路径上添加中间点
                while (k != -1 && k != i) {
                    d++;
                    apath[d] = k;
                    k = path[i][k];
                }
                // 路径上添加起点
                d++;
                apath[d] = i;

                // 输出起点
                printf("%d", apath[d]);
                // 输出路径上的中间顶点
                for (s = d - 1; s >= 0; s--) {
                    printf(",%d", apath[s]);
                }

                printf("\t路径长度为:%d\n", A[i][j]);
            }
        }
    }
}

/**
 * Floyd算法那
 */
void Floyd(MatGraph g) {
    int A[MAXV][MAXV], path[MAXV][MAXV];
    int i, j, k;

    for (i = 0; i < g.n; i++) {
        for (j = 0; j < g.n; j++) {
            A[i][j] = g.edges[i][j];

            // 顶点i到j有边时
            if (i != j && g.edges[i][j] < INF) {
                path[i][j] = i;
            }
            // 顶点i到j没有边时
            else {
                path[i][j] = -1;
            }
        }
    }

    // 依次考察所有顶点
    for (k = 0; k < g.n; k++) {
        for (i = 0; i < g.n; i++) {
            for (j = 0; j < g.n; j++) {
                if (A[i][k] + A[k][j] < A[i][j]) {
                    // 修改最短路径长度
                    A[i][j] = A[i][k] + A[k][j];
                    // 修改最短路径
                    path[i][j] = path[k][j];
                }
            }
        }
    }

    // 输出最短路径
    Dispath(g, A, path);
}

int main() {
    MatGraph g;
    int A[MAXV][MAXV] = {
            {0,   6, INF, INF, 2},
            {INF, 0, INF, INF, INF},
            {INF, 1, 0,   3,   INF},
            {2, INF, INF, 0,   INF},
            {INF, 3, 1,   3,   0}
    };

    int n = 5, e = 8;

    // 建立图的邻接矩阵
    CreateMat(g, A, n, e);
    printf("图G的邻接矩阵:\n");
    // 输出邻接矩阵
    DispMat(g);

    printf("各顶点对的最短路径:\n");
    Floyd(g);

    return 0;
}