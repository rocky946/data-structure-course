// 构造哈夫曼树和哈夫曼编码
#include <stdio.h>

// 叶子结点数
#define N 50
// 树中结点总数
#define M 2 * N - 1

// 哈夫曼树结点类型
typedef struct {
    // 结点值
    char data;
    // 权重
    double weight;
    // 双亲结点
    int parent;
    // 左孩子结点
    int lchild;
    // 右孩子结点
    int rchild;
} HTNode;

// 每个结点哈夫曼编码类型
typedef struct {
    // 存放当前结点的哈夫曼码
    char cd[N];
    // 表示cd[start..n0]部分是哈夫曼码
    int start;
} HCode;

/**
 * 构造哈夫曼树
 * @param ht
 * @param n0
 */
void CreateHT(HTNode ht[], int n0) {
    // lnode,rnode为最小权重的两个结点位置
    int i, k, lnode, rnode;
    // 两个最小权重
    double min1, min2;

    // 所有结点的相关域初始为-1
    for (i = 0; i < 2 * n0 - 1; i++) {
        ht[i].parent = ht[i].lchild = ht[i].rchild = -1;
    }

    // 构造哈夫曼树的n0-1个结点
    for (i = n0; i < 2 * n0 - 1; i++) {
        min1 = min2 = 32767;
        lnode = rnode = -1;

        // 在ht[0..i-1]中找权值最小的两个结点
        for (k = 0; k < i; k++) {
            // 只在尚未构造二叉树的结点中查找
            if (ht[k].parent == -1) {
                if (ht[k].weight < min1) {
                    min2 = min1;
                    rnode = lnode;
                    min1 = ht[k].weight;
                    lnode = k;
                } else if (ht[k].weight < min2) {
                    min2 = ht[k].weight;
                    rnode = k;
                }
            }
        }

        // ht[i]作为双亲结点
        ht[i].weight = ht[lnode].weight + ht[rnode].weight;
        ht[i].lchild = lnode;
        ht[i].rchild = rnode;
        ht[lnode].parent = i;
        ht[rnode].parent = i;
    }
}

/**
 * 根据哈夫曼树求对应的哈夫曼编码
 * @param ht
 * @param hcd
 * @param n0
 */
void CreateHCode(HTNode ht[], HCode hcd[], int n0) {
    int f, c;
    HCode hc;

    for (int i = 0; i < n0; ++i) {
        hc.start = n0;
        c = i;
        f = ht[i].parent;

        // 循环直到根结点
        while (f != -1) {
            // 当前结点是双亲结点的左孩子
            if (ht[f].lchild == c) {
                hc.cd[hc.start--] = '0';
            }
            // 当前结点是双亲结点的右孩子
            else {
                hc.cd[hc.start--] = '1';
            }

            // 再对双亲结点进行同样的操作
            c = f;
            f = ht[f].parent;
        }

        // start指向哈夫曼编码最开始的字符
        hc.start++;
        hcd[i] = hc;
    }
}

/**
 * 输出哈夫曼树编码
 * @param ht
 * @param hcd
 * @param n0
 */
void DispHCode(HTNode ht[], HCode hcd[], int n0) {
    int i, k;
    double sum = 0, m = 0;
    int j;
    printf("  输出哈夫曼编码:\n");

    for (i = 0; i < n0; i++) {
        j = 0;
        printf("      %c:\t", ht[i].data);
        for (k = hcd[i].start; k <= n0; k++) {
            printf("%c", hcd[i].cd[k]);
            j++;
        }
        m += ht[i].weight;
        sum += ht[i].weight * j;
        printf("\n");
    }
    printf("\n  平均长度=%g\n", 1.0 * sum / m);
}

int main() {
    // n表示初始字符串的个数
    int n = 8, i;
    char str[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    double fnum[] = {0.07, 0.19, 0.02, 0.06, 0.32, 0.03, 0.21, 0.1};
    HTNode ht[M];
    HCode hcd[N];

    for (i = 0; i < n; i++) {
        ht[i].data = str[i];
        ht[i].weight = fnum[i];
    }
    printf("\n");

    CreateHT(ht, n);
    CreateHCode(ht, hcd, n);
    DispHCode(ht, hcd, n);
    printf("\n");

    return 0;
}

