#include <stdio.h>
#include "mat_graph.h"

void CreateMat(MatGraph &g, int A[MAXV][MAXV], int n, int e) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            g.edges[i][j] = A[i][j];
        }
    }

    g.n = n;
    g.e = e;
}

void DispMat(MatGraph g) {
    for (int i = 0; i < g.n; ++i) {
        for (int j = 0; j < g.n; ++j) {
            if (g.edges[i][j] != INF)
                printf("%4d", g.edges[i][j]);
            else
                printf("%4s", "∞");
        }
        printf("\n");
    }
}


