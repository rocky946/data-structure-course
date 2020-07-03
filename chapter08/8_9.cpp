// 求不带权无向连通图G中从顶点u到顶点v的一条最短路径
#include <stdio.h>
#include "adj_graph.h"

// 非环形队列类型
typedef struct {
    // 顶点编号
    int data;
    // 前一个顶点的位置
    int parent;
} QuElem;

/**
 * 输出从顶点u到顶点v的最短逆路径
 * @param G
 * @param u
 * @param v
 */
void ShortPath(AdjGraph *G, int u, int v) {
    // 非环形队列
    QuElem qu[MAXV];
    // 初始化队头、队尾指针
    int front = -1;
    int rear = -1;

    // 定义顶点访问标记数组
    int visited[MAXV];
    // 初始化visited数组
    for (int i = 0; i < G->n; ++i) {
        visited[i] = 0;
    }

    // 访问初始顶点u并进队
    visited[u] = 1;
    rear++;
    qu[rear].data = u;
    qu[rear].parent = -1;

    int w, i;
    ArcNode *p;
    // 队不空循环
    while (front != rear) {
        // 出队顶点w
        front++;
        w = qu[front].data;

        // 找到v时输出路径之逆并退出
        if (w == v) {
            // 通过队列输出逆路径
            i = front;
            while (qu[i].parent != -1) {
                printf("%2d", qu[i].data);
                i = qu[i].parent;
            }

            printf("%2d\n", qu[i].data);
            return;
        }

        // 找w的第一个邻接点
        p = G->adjlist[w].firstarc;
        while (nullptr != p) {
            if (visited[p->adjvex] == 0) {
                visited[p->adjvex] = 1;
                // 将w的未访问过的邻接点进队
                rear++;
                qu[rear].data = p->adjvex;
                qu[rear].parent = front;
            }

            // 找w的下一个邻接点
            p = p->nextarc;
        }
    }
}

int main() {
    int A[MAXV][MAXV] = {{0, 1, 1, 0, 0},
                         {0, 0, 1, 0, 0},
                         {0, 0, 0, 1, 1},
                         {0, 0, 0, 0, 1},
                         {1, 0, 0, 0, 0}};
    int n = 5, e = 7;

    AdjGraph *G;

    // 创建邻接表
    CreateAdj(G, A, n, e);
    // 输出邻接表
    DispAdj(G);

    ShortPath(G, 0, 4);

    // 销毁邻接表
    Destroy(G);

    return 0;
}