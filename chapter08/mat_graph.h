// 图的邻接矩阵存储结构
#ifndef CHAPTER08_MAT_GRAPH_H
#define CHAPTER08_MAT_GRAPH_H

// 定义∞
#define INF 32767
// 最大顶点个数
#define MAXV 100
// 顶点的其他信息
typedef char InfoType;

// 顶点类型
typedef struct {
    // 顶点编号
    int no;
    // 顶点其他信息
    InfoType info;
} VertexType;

// 完整的图邻接矩阵类型
typedef struct {
    // 邻接矩阵数组
    int edges[MAXV][MAXV];
    // 顶点数
    int n;
    // 边数
    int e;
    // 存放顶点信息
    VertexType vexs[MAXV];
} MatGraph;

/**
 * 创建图的邻接矩阵
 * @param g
 * @param A 邻接矩阵数组
 * @param n 顶点数
 * @param e 边数
 */
void CreateMat(MatGraph &g, int A[MAXV][MAXV], int n, int e);

/**
 * 输出邻接矩阵
 * @param g
 */
void DispMat(MatGraph g);

#endif //CHAPTER08_MAT_GRAPH_H
