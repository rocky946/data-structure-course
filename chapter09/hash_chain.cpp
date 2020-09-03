#include "hash_chain.h"
#include <stdio.h>
#include <malloc.h>

void InsertHT(HashTable ha[], int &n, int p, KeyType k) {
    // 计算哈希函数值
    int adr = k % p;
    // 创建结点q,存放关键字k
    NodeType *q = nullptr;
    q = (NodeType *) malloc(sizeof(NodeType));
    q->key = k;
    q->next = nullptr;
    // 采用头插法插入到ha[adr]的单链表中
    q->next = ha[adr].first;
    ha[adr].first = q;
    // 哈希表结点总数加1
    n++;
}

void CreateHT(HashTable ha[], int &n, int m, int p, KeyType keys[], int n1) {
    int i;
    // 哈希表置初值
    for (i = 0; i < m; i++) {
        ha[i].first = nullptr;
    }
    n = 0;
    for (i = 0; i < n1; i++) {
        // 插入n1个关键字
        InsertHT(ha, n, p, keys[i]);
    }
}

bool DeleteHT(HashTable ha[], int &n, int p, KeyType k) {
    int adr = k % p;
    NodeType *pre, *q;
    // p指向对应单链表的首结点
    q = ha[adr].first;
    // 对应单链表为空
    if (nullptr == q) {
        return false;
    }

    // 首结点为k
    if (q->key == k) {
        ha[adr].first = q->next;
        free(q);
        n--;
        return true;
    }

    // 首结点不为k时
    pre = q;
    q = q->next;
    while (nullptr != q) {
        // 查找成功
        if (q->key == k) {
            break;
        }
        pre = q;
        q = q->next;
    }
    // 查找成功
    if (nullptr != q) {
        // 删除结点q
        pre->next = q->next;
        free(q);
        n--;
        return true;
    }
    // 未找到k,返回假
    else {
        return false;
    }
}

void SearchHT(HashTable ha[], int p, KeyType k) {
    int i = 0;
    int adr = k % p;
    // q指向对应单链表的首结点
    NodeType *q = ha[adr].first;
    // 扫描单链表adr的所有结点
    while (nullptr != q) {
        i++;
        // 查找成功
        if (q->key == k) {
            break;
        }
        q = q->next;
    }

    // 查找成功
    if (nullptr != q) {
        printf("成功：关键字%d，比较%d次\n", k, i);
    } else {
        printf("失败：关键字%d，比较%d次\n", k, i);
    }
}

void ASL(HashTable ha[], int n, int m) {
    int succ = 0, unsucc = 0, s;
    NodeType *q = nullptr;
    // 扫描所有哈希表地址空间
    for (int i = 0; i < m; i++) {
        s = 0;
        // q指向单链表i的首结点
        q = ha[i].first;
        // 扫描单链表i的所有结点
        while (nullptr != q) {
            q = q->next;
            // s记录当前结点是对应单链表的第几个结点
            s++;
            // 累计成功的总比较次数
            succ += s;
        }
        // 累计不成功的总比较次数
        unsucc += s;
    }

    printf(" 成功情况下ASL(%d) = %g\n", n, succ * 1.0 / n);
    printf(" 不成功情况下ASL(%d) = %g\n", n, succ * 1.0 / m);
}

void DispHT(HashTable ha[], int n, int m, int p) {
    NodeType *q = nullptr;
    // 扫描所有哈希表地址空间
    for (int i = 0; i < m; i++) {
        printf(" %3d:\t", i);
        // q指向单链表i的首结点
        q = ha[i].first;
        // 扫描单链表i的所有结点
        while (nullptr != q) {
            printf("%4d",q->key);
            q = q->next;
        }
        printf("\n");
    }
    printf("\n");
    ASL(ha, n, m);
}

void DestroyHT(HashTable ha[], int m) {
    NodeType *q, *pre;
    for (int i = 0; i < m; i++) {
        // q指向单链表i的首结点
        q = ha[i].first;
        // 扫描单链表i的所有结点
        while (nullptr != q) {
            pre = q;
            q = q->next;
            free(pre);
        }
    }
}
