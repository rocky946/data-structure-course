// 并查集算法
#include <stdio.h>

#define MAX_SIZE 100
// 问题涉及的人数，人的编号从1到N
#define N 10
// 亲戚关系个数
#define M 7
// 询问个数
#define Q 3

// 并查集树结点类型
typedef struct node {
    // 结点对应人的编号
    int data;
    // 结点对应秩
    int rank;
    // 结点对应双亲下标
    int parent;
} UFSTree;

/**
 * 初始化并查集树
 * @param t
 * @param n
 */
void MakeSet(UFSTree t[], int n) {
    for (int i = 1; i <= n; ++i) {
        // 数据为该人的编号
        t[i].data = i;
        // 秩初始化为0
        t[i].rank = 0;
        // 双亲初始化指向自己
        t[i].parent = i;
    }
}

/**
 * 查找一个元素所属的集合
 * @param t
 * @param x
 * @return
 */
int FindSet(UFSTree t[], int x) {
    // 双亲不是自己
    if (x != t[x].parent) {
        // 递归在双亲中查找x
        return (FindSet(t, t[x].parent));
    }
        // 双亲是自己，返回x
    else {
        return x;
    }
}

/**
 * 两个元素各自所属的集合的合并
 * @param t
 * @param x
 * @param y
 */
void Union(UFSTree t[], int x, int y) {
    // 查找x所在分离集合树的编号
    x = FindSet(t, x);
    // 查找y所在分离集合树的编号
    y = FindSet(t, y);

    // y的秩小于x的秩
    if (t[x].rank > t[y].rank) {
        // 将y连到x结点上，x作为y的双亲结点
        t[y].parent = x;
    }
    // y的秩大于等于x的秩
    else {
        // 将x连到y结点上，y作为x的双亲结点
        t[x].parent = y;
        // x,y的秩相同
        if (t[x].rank == t[y].rank) {
            // y结点的秩增1
            t[y].rank++;
        }
    }
}

int main() {
    int i, x, y;
    UFSTree t[MAX_SIZE];

    int rel[M][2] = {{2, 4},
                     {5, 7},
                     {1, 3},
                     {8, 9},
                     {1, 2},
                     {5, 6},
                     {2, 3}};

    int ans[Q][2] = {{3, 4},
                     {7, 10},
                     {8, 9}};

    // 初始化并查集树t
    MakeSet(t, N);
    // 根据关系进行合并操作
    for (i = 0; i < M; i++)
        Union(t, rel[i][0], rel[i][1]);

    // 输出并查集树t
    printf("data  rank  parent\n");
    for (i = 1; i <= N; i++)
        printf("%4d%5d%6d\n", t[i].data, t[i].rank, t[i].parent);
    printf("\n");

    // 输出求解结果
    printf("各询问的结果:\n");
    for (i = 0; i < Q; i++) {
        x = FindSet(t, ans[i][0]);
        y = FindSet(t, ans[i][1]);
        if (x == y)
            printf("  (%d,%d):Yes\n", ans[i][0], ans[i][1]);
        else
            printf("  (%d,%d):No\n", ans[i][0], ans[i][1]);
    }

    return 0;
}