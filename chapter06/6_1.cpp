// 利用数组求解约瑟夫问题
#include <stdio.h>

#define MAX_SIZE 50

void josephus(int n, int m) {
    int p[MAX_SIZE];

    int i, j , t;
    // 构建初始序列
    for (i = 0; i < n; i++) {
        p[i] = i + 1;
    }

    // 首次报数的起始位置
    t = 0;
    printf("出列顺序：");
    // i为数组p中当前的人数，出列一次，人数减1
    for (i = n; i >= 1; i--) {
        // t为出列者的编号
        t = (t + m - 1) % i;
        // 编号为t的元素出列
        printf("%d ", p[t]);
        // 后面的元素前移一个位置
        for (j = t + 1; j <= i - 1; j++) {
            p[j - 1] = p[j];
        }

    }
    printf("\n");
}

int main() {
    josephus(8, 4);

    return 0;
}