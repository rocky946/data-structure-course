#include <stdio.h>
#include "hash_open.h"

void InsertHT(HashTable ha[], int &n, int m, int p, KeyType k) {
    int i, adr;
    // 计算哈希函数值
    adr = k % p;
    // K可以直接放在哈希表中
    if (ha[adr].key == NULLKEY || ha[adr].key == DELETKEY) {
        ha[adr].key = k;
        ha[adr].count = 1;
    } else {
        // i记录k发生冲突的次数
        i = 1;
        // 线性探测
        do {
            adr = (adr + 1) % m;
            i++;
        } while (ha[adr].key != NULLKEY && ha[adr].key != DELETKEY);
        // 在adr处放置k
        ha[adr].key = k;
        ha[adr].count = i;
    }
    // 哈希表中总元素个数增1
    n++;
}

void CreateHT(HashTable ha[], int &n, int m, int p, KeyType keys[], int n1) {
    int i;
    // 哈希表置空的初始值
    for (i = 0; i < m; i++) {
        ha[i].key = NULLKEY;
        ha[i].count = 0;
    }
    // 哈希表中总元素个数从0开始递增
    n = 0;
    for (i = 0; i < n1; i++) {
        InsertHT(ha, n, m, p, keys[i]);
    }
}

bool DeleteHT(HashTable ha[], int &n, int m, int p, KeyType k) {
    int adr = k % p;
    // 线性探测
    while (ha[adr].key != NULLKEY && ha[adr].key != k) {
        adr = (adr + 1) % m;
    }

    // 查找成功，删除关键字k
    if (ha[adr].key == k) {
        ha[adr].key = DELETKEY;
        return true;
    } else {
        return false;
    }
}

void SearchHT(HashTable ha[], int m, int p, KeyType k) {
    int i = 1;
    int adr = k % p;
    // 线性探测
    while (ha[adr].key != NULLKEY && ha[adr].key != k) {
        // 累计关键字比较次数
        i++;
        adr = (adr + 1) % m;
    }

    // 查找成功，删除关键字k
    if (ha[adr].key == k) {
        printf("成功：关键字%d，比较%d次\n", k, i);
    } else {
        printf("失败：关键字%d，比较%d次\n", k, i);
    }
}

void ASL(HashTable ha[], int n, int m, int p) {
    int i, j;
    int succ = 0, unsucc = 0, s;
    for (i = 0; i < m; i++) {
        if (ha[i].key != NULLKEY && ha[i].key != DELETKEY) {
            // 累计成功时的总关键字比较次数
            succ += ha[i].count;
        }
    }
    printf("成功情况下ASL(%d) = %g\n", n, succ * 1.0 / n);

    for (i = 0; i < p; i++) {
        s = 1;
        j = i;
        while (ha[j].key != NULLKEY) {
            s++;
            j = (j + 1) % m;
        }
        // 累计不成功时的总关键字比较次数
        unsucc += s;
    }
    printf("不成功情况下ASL(%d) = %g\n", n, unsucc * 1.0 / p);
}

void DispHT(HashTable ha[], int n, int m, int p) {
    int i;

    printf("哈希表:\n");
    printf(" 地址:\t");
    for (i = 0; i < m; i++) {
        printf(" %3d", i);
    }
    printf(" \n");

    printf(" 关键字:\t");
    for (i = 0; i < m; i++) {
        if (ha[i].key == NULLKEY)
            // 输出3个空格
            printf("    ");
        else
            printf(" %3d", ha[i].key);
    }
    printf(" \n");

    printf(" 探测:\t");
    for (i = 0; i < m; i++) {
        if (ha[i].key == NULLKEY)
            // 输出3个空格
            printf("    ");
        else
            printf(" %3d", ha[i].count);
    }
    printf(" \n");
    ASL(ha, n, m, p);
}