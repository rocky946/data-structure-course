#ifndef CHAPTER06_TUPLES_H
#define CHAPTER06_TUPLES_H

#define M 6
#define N 7
// 稀疏举证中非零元素最多的个数
#define MAX_SIZE 50

typedef int ElemType;

// 三元组类型
typedef struct {
    // 行号
    int r;
    // 列号
    int c;
    // 元素值
    ElemType d;
} TupNode;

// 三元组顺序表类型
typedef struct {
    // 行数
    int rows;
    // 列数
    int cols;
    // 非零元素个数
    int nums;
    TupNode data[MAX_SIZE];
} TSMatrix;

/**
 * 从一个二维稀疏矩阵创建其三元组表示
 * @param t 
 * @param A 
 */
void CreateMat(TSMatrix &t, ElemType A[M][N]);

/**
 * 三元组元素的赋值
 * @param t 
 * @param x 
 * @param i 
 * @param j 
 * @return 
 */
bool Value(TSMatrix &t, ElemType x, int i, int j);

/**
 * 将指定位置的元素值赋值给变量
 * @param t 
 * @param x 
 * @param i 
 * @param j 
 * @return 
 */
bool Assign(TSMatrix t, ElemType &x, int i, int j);

/**
 * 输出三元组
 * @param t 
 */
void DispMat(TSMatrix t);

/**
 * 稀疏矩阵转置
 * @param t 
 * @param tb 
 */
void TranTat(TSMatrix t, TSMatrix &tb);

#endif //CHAPTER06_TUPLES_H
