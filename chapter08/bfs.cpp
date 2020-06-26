// 图的广度优先遍历算法
#include <stdio.h>
#include "adj_graph.h"
#include "sq_queue.h"

/**
 * 广度优先遍历算法
 * @param G 
 * @param v 
 */
void BFS(AdjGraph *G, int v) {
    ArcNode *p;
    int w;
    
    // 定义环形队列指针
    SqQueue *qu;
    // 初始化环形队列
    InitQueue(qu);
    
    // 定义顶点访问标记数组
    int visited[MAXV];
    // 初始化visited数组
    for (int i = 0; i < G->n; ++i) {
        visited[i] = 0;
    }
    
    // 访问初始顶点并进队
    printf("%2d", v);
    visited[v] = 1;
    enQueue(qu, v);
    
    // 队不空循环
    while (!QueueEmpty(qu)) {
        // 出队一个顶点
        deQueue(qu, w);
        // p指向w的第一个邻接点
        p = G->adjlist[w].firstarc;
        
        // 查找w的所有邻接点
        while (nullptr != p) {
            // 若当前邻接点未被访问
            if (visited[p->adjvex] == 0) {
                // 访问并进队
                printf("%2d", p->adjvex);
                visited[p->adjvex] = 1;
                enQueue(qu, p->adjvex);
            }
            // 找下一个邻接点
            p = p->nextarc;
        }
    }
    printf("\n");
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

    // BFS
    printf("BFS: ");
    BFS(G, 2);

    // 销毁邻接表
    Destroy(G);

    return 0;
}