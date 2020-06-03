#include <stdio.h>
#include "tuples.h"

void CreateMat(TSMatrix &t, ElemType A[M][N]) {
    t.rows = M;
    t.cols = N;
    t.nums = 0;

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            // 非零元素
            if (A[i][j] != 0) {
                t.data[t.nums].r = i;
                t.data[t.nums].c = j;
                t.data[t.nums].d = A[i][j];
                t.nums++;
            }
        }
    }
}

bool Value(TSMatrix &t, ElemType x, int i, int j) {
    int k = 0, k1;
    // i,j超界
    if (i >= t.rows || j >= t.cols) {
        return false;
    }

    // 查找到第i行的第一个非0元素
    while (k < t.nums && i > t.data[k].r) {
        k++;
    }
    // 在第i行查找非0元素
    while (k < t.nums && i == t.data[k].r && j > t.data[k].c) {
        k++;
    }

    // 若存在这样的非0元素
    if (t.data[k].r == i && t.data[k].c == j) {
        t.data[k].d = x;
    }
    // 若不存在这样的非0元素，则插入x
    else {
        // 元素后移一个位置
        for (k1 = t.nums - 1; k1 >= k; k1--) {
            t.data[k1 + 1].r = t.data[k1].r;
            t.data[k1 + 1].c = t.data[k1].c;
            t.data[k1 + 1].d = t.data[k1].d;
        }
        t.data[k].r = i;
        t.data[k].c = j;
        t.data[k].d = x;
        t.nums++;
    }
    return true;
}

bool Assign(TSMatrix t, ElemType &x, int i, int j) {
    int k = 0;
    // i,j超界
    if (i >= t.rows || j >= t.cols) {
        return false;
    }

    // 查找到第i行的第一个非0元素
    while (k < t.nums && i > t.data[k].r) {
        k++;
    }
    // 在第i行查找非0元素
    while (k < t.nums && i == t.data[k].r && j > t.data[k].c) {
        k++;
    }

    // 若存在这样的非0元素,则提取元素值
    if (t.data[k].r == i && t.data[k].c == j) {
        x = t.data[k].d;
    }
    // 若不存在这样的非0元素，则x为0
    else {
        x = 0;
    }
    return true;
}

void DispMat(TSMatrix t) {
    // 无非零元素时直接返回
    if (t.nums <= 0) {
        return;
    }

    printf("\t%d\t%d\t%d\n", t.rows, t.cols, t.nums);

    for (int i = 0; i < t.nums; ++i) {
        printf("\t%d\t%d\t%d\n", t.data[i].r, t.data[i].c, t.data[i].d);
    }
}

void TranTat(TSMatrix t, TSMatrix &tb) {
    // k1记录tb中的元素个数
    int k, k1 = 0, v;
    tb.rows = t.cols;
    tb.cols = t.rows;
    tb.nums = t.nums;

    // 当存在非0元素时执行转置
    if (t.nums != 0) {
        for (v = 0; v < t.cols; v++) {
            for (k = 0; k < t.nums; k++) {
                // 找到列号为v的元素，将行、列交换后添加到tb中
                if (t.data[k].c == v) {
                    tb.data[k1].r = t.data[k].c;
                    tb.data[k1].c = t.data[k].r;
                    tb.data[k1].d = t.data[k].d;
                    k1++;
                }
            }
        }
    }

}
