// Dijkstra算法
#include <stdio.h>
#include "mat_graph.h"

/**
 * 输出从顶点v出发的所有最短路径
 * @param g
 * @param dist
 * @param path
 * @param S
 * @param v
 */
void Dispath(MatGraph g, int dist[], int path[], int S[], int v) {
    int i, j, k;
    // 存放一条最短路径(逆向)及其顶点个数
    int apath[MAXV], d;

    // 循环输出从顶点v到i的路径
    for (i = 0; i < g.n; i++) {
        if (S[i] == 1 && i != v) {
            printf(" 从顶点%d到顶点%d的路径长度为:%d\t路径为：", v, i, dist[i]);

            // 添加路径上的终点
            d = 0;
            apath[d] = i;
            k = path[i];

            // 没有路径的情况
            if (k == -1) {
                printf("无路径\n");
            }
            // 存在路径时输出该路径
            else {
                while (k != v) {
                    d++;
                    apath[d] = k;
                    k = path[k];
                }

                // 添加路径上的起点
                d++;
                apath[d] = v;
                // 先输出起点
                printf("%d", apath[d]);
                // 再输出其他顶点
                for (j = d - 1; j >= 0; j--) {
                    printf(",%d", apath[j]);
                }
                printf("\n");
            }
        }
    }
}

/**
 * Dijkstra算法
 */
void Dijkstra(MatGraph g, int v) {
    int dist[MAXV], path[MAXV];
    // S[i]=1表示顶点i在S中，S[i]=0表示顶点i在U中
    int S[MAXV];
    int MINdis, i, j, u = 0;

    for (i = 0; i < g.n; i++) {
        // 距离初始化
        dist[i] = g.edges[v][i];
        // S[]置空
        S[i] = 0;
        // 路径初始化
        if (g.edges[v][i] < INF) {
            // 顶点v到顶点i有边时，置顶点i的前一个顶点为v
            path[i] = v;
        }
        // 顶点v到顶点i没边时，置顶点i的前一个顶点未-1
        else {
            path[i] = -1;
        }
    }

    // 源点编号v放入S中
    S[v] = 1;
    path[v] = 0;

    // 循环直到所有顶点的最短路径都求出
    for (i = 0; i < g.n - 1; i++) {
        // MINdis置最大长度初值
        MINdis = INF;
        // 选取不在S中(即U中)且具有最小最短路径长度的顶点u
        for (j = 0; j < g.n; j++) {
            if (S[j] == 0 && dist[j] < MINdis) {
                u = j;
                MINdis = dist[j];
            }
        }

        // 顶点u加入S中
        S[u] = 1;

        // 修改不在S中(即U中)的顶点的最短路径
        for (j = 0; j < g.n; j++) {
            if (S[j] == 0) {
                if (g.edges[u][j] < INF && dist[u] + g.edges[u][j] < dist[j]) {
                    dist[j] = dist[u] + g.edges[u][j];
                    path[j] = u;
                }
            }
        }
    }

    // 输出最短路径
    Dispath(g, dist, path, S, v);
}


int main() {
    MatGraph g;
    int A[MAXV][MAXV] = {
            {0,   4,   6, 6,     INF, INF, INF},
            {INF, 0,   1,   INF, 7,   INF, INF},
            {INF, INF, 0,   INF, 6,   4,   INF},
            {INF, INF, 2, 0,     INF, 5,   INF},
            {INF, INF, INF, INF, 0,   INF, 6},
            {INF, INF, INF, INF, 1,   0,   8},
            {INF, INF, INF, INF, INF, INF, 0}};
    int n = 7, e = 12;
    // 建立《教程》中图8.35的邻接矩阵
    CreateMat(g, A, n, e);

    printf("图G的邻接矩阵:\n");
    // 输出邻接矩阵
    DispMat(g);

    int v = 0;
    printf("从%d顶点出发的最短路径如下:\n", v);
    Dijkstra(g, v);

    return 0;
}
