// Prim(普里姆)算法
#include <stdio.h>
#include "mat_graph.h"

/**
 * Prim算法
 * @param g 邻接矩阵
 * @param v 起点
 */
void Prim(MatGraph g, int v) {
    int lowcost[MAXV];
    int MIN;
    int closest[MAXV];
    int i, j;
    int k = 0;

    // 给lowcost[]和closest[]置初值
    for (i = 0; i < g.n; i++) {
        lowcost[i] = g.edges[v][i];
        closest[i] = v;
    }

    // 找出(n-1)个顶点
    for (i = 1; i < g.n; i++) {
        MIN = INF;
        // 在(V-U)中找出离U最近的顶点k
        for (j = 0; j < g.n; j++) {
            if (lowcost[j] != 0 && lowcost[j] < MIN) {
                MIN = lowcost[j];
                // k记录最近顶点的编号
                k = j;
            }
        }

        // 输出最小生成树的一条边
        printf("边(%d, %d)权为：%d\n", closest[k], k, MIN);
        // 标记k已经加入U
        lowcost[k] = 0;

        // 对(V-U)中的顶点j进行调整
        for (j = 0; j < g.n; j++) {
            if (lowcost[j] != 0 && g.edges[k][j] < lowcost[j]) {
                lowcost[j] = g.edges[k][j];
                // 修改数组lowcost和closest
                closest[j] = k;
            }
        }
    }
}

int main() {
    int A[MAXV][MAXV] = {
            {0,   28,  INF, INF, INF, 10,  INF},
            {28,  0,   16,  INF, INF, INF, 14},
            {INF, 16,  0,   12,  INF, INF, INF},
            {INF, INF, 12,  0,   22,  INF, 18},
            {INF, INF, INF, 22,  0,   25,  24},
            {10,  INF, INF, INF, 25,  0,   INF},
            {INF, 14,  INF, 18,  24,  INF, 0}};
    int n=7, e=9;

    MatGraph g;

    // 创建邻接矩阵
    CreateMat(g, A, n, e);
    // 输出邻接矩阵
    DispMat(g);

    int v = 0;
    printf("\nPrim算法结果(起始点为%d)\n", v);
    Prim(g, v);

    return 0;
}