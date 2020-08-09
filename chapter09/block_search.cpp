// 分块查找算法
#include <stdio.h>
#include "seq_list.h"

// 索引表的最大长度
#define MAXI 20

// 索引表元素的类型
typedef struct {
    // 关键字类型
    KeyType  key;
    // 指向对应块的起始下标
    int link;
} IdxType;

/**
 * 分块查找
 * @param I 索引表
 * @param b 块数
 * @param R 顺序查找包
 * @param n 元素个数
 * @param k 关键字
 * @return
 */
int IdxSearch(IdxType I[], int b, RecType R[], int n, KeyType k) {
    // s为每块的元素个数，应为n/b的向上取整
    int s = (n + b - 1) /b;

    int low = 0, high = b - 1, mid, i;
    // 在索引表中进行折半查找，找到的位置为high + 1
    while (low <= high) {
        mid = (low + high) / 2;
        if (k <= I[mid].key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    // 应先在索引表中的high+1块中查找，再在主数据表中进行顺序查找
    i = I[high + 1].link;
    while (i <= I[high + 1].link + s - 1 && R[i].key != k) {
        i++;
    }

    // 查找成功，返回该元素的逻辑序号
    if (i <= I[high + 1].link + s - 1) {
        return i + 1;
    }
    // 查找失败，返回0
    else {
        return 0;
    }
}


int main() {
    int n = 25, b = 5, j;
    RecType R[MAXL];
    IdxType I[MAXI] = {{14,  0},
                       {34,  5},
                       {66,  10},
                       {85,  15},
                       {100, 20}};
    KeyType a[] = {8, 14, 6, 9, 10, 22, 34, 18, 19, 31, 40, 38, 54, 66, 46, 71, 78, 68, 80, 85, 100, 94, 88, 96, 87};
    KeyType k = 85;
    
    CreateList(R, a, n);
    printf("查找表：");
    DispList(R, n);
    
    j = IdxSearch(I, b, R, n, k);
    if (j != -1)
        printf("R[%d]=%d\n", j, k);
    else
        printf("未找到%d\n", k);\
        
    return 0;
}