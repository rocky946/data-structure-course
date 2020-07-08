// kruskal(克鲁斯卡尔)算法
#include <stdio.h>
#include "mat_graph.h"

#define MAX_SIZE 100

// 边类型
typedef struct {
    // 边的起始顶点
    int u;
    // 边的终止顶点
    int v;
    // 边的权值
    int w;
} Edge;

/**
 * 插入排序
 * @param edges 边数组
 * @param n 边数
 */
void InsertSort(Edge E[], int n) {
    Edge tmp;

    int i, j;

    for (i = 1; i < n; ++i) {
        tmp = E[i];
        // 从右向左在有序区E[0..i-1]中找E[i]的插入位置
        j = i - 1;
        while (j >= 0 && tmp.w < E[j].w) {
            // 将关键字大于E[i]的记录右移
            E[j + 1] = E[j];
            j--;
        }

        // 在j+1处插入E[i]
        E[j + 1] = tmp;
    }
}

/**
 * Kruskal算法
 * @param g
 */
void KrusKal(MatGraph g) {
    int i, j, u1, v1, sn1, sn2, k;
    // 辅助数组
    int vset[MAXV];

    // 存放图中的所有边
    Edge E[MAX_SIZE];

    // 由g产生边集E，不重复选取同一条边
    k = 0;
    for (i = 0; i < g.n; i++) {
        for (j = 0; j <= i; j++) {
            if (g.edges[i][j] != 0 && g.edges[i][j] != INF) {
                E[k].u = i;
                E[k].v = j;
                E[k].w = g.edges[i][j];
                k++;
            }
        }
    }

    // 采用直接插入排序对E数组按权值递增排序
    InsertSort(E, g.e);

    // 初始化辅助数组
    for (i = 0; i < g.n; i++) {
        vset[i] = i;
    }

    // k表示当前构造生成树的第几条边，初值为1
    k = 1;
    // E中边的下标，初值为0
    j = 0;
    // 生成的边数小于n时循环
    while (k < g.n) {
        // 取一条边的两个顶点
        u1 = E[j].u;
        v1 = E[j].v;
        // 分别得到两个顶点所属的集合编号
        sn1 = vset[u1];
        sn2 = vset[v1];

        // 两个顶点属于不同的集合，该边是最小生成树的一条边
        if (sn1 != sn2) {
            // 输出最小生成树的一条边
            printf(" (%d, %d): %d\n", u1, v1, E[j].w);
            // 生成边数增1
            k++;

            // 两个集合统一编号
            for (i = 0; i < g.n; i++) {
                // 集合编号为sn2的改为sn1
                if (vset[i] == sn2) {
                    vset[i] = sn1;
                }
            }
        }

        // 扫描下一条边
        j++;
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
    printf("\nKruskal算法结果\n");
    KrusKal(g);

    return 0;
}