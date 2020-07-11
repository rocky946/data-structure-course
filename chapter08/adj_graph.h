// 图的邻接表存储结构
#ifndef CHAPTER08_ADJ_GRAPH_H
#define CHAPTER08_ADJ_GRAPH_H

// 定义∞
#define INF 32767
// 最大顶点个数
#define MAXV 100
// 顶点的其他信息
typedef char InfoType;

// 边结点类型
typedef struct ANode {
    // 该边的邻接点编号
    int adjvex;
    // 指向下一条边的指针
    struct ANode *nextarc;
    // 该边的其他信息，如权值(这里用整型表示)
    int weight;
} ArcNode;

// 邻接表的头结点类型
typedef struct Vnode {
    // 顶点信息
    InfoType info;

    // 数据域：存放顶点入度
    int count;

    // 指向第一个边结点
    ArcNode *firstarc;
} VNode;

// 完整的图邻接表类型
typedef struct {
    // 邻接表的头结点数组
    VNode adjlist[MAXV];
    // 顶点数
    int n;
    // 边数
    int e;
} AdjGraph;

/**
 * 创建图的邻接表
 * @param G 图
 * @param A 邻接矩阵数组
 * @param n 顶点数
 * @param e 边数
 */
void CreateAdj(AdjGraph *&G, int A[MAXV][MAXV], int n, int e);

/**
 * 输出邻接表G
 */
void DispAdj(AdjGraph *G);

/**
 * 销毁图
 */
void Destroy(AdjGraph *&G);

#endif //CHAPTER08_ADJ_GRAPH_H
