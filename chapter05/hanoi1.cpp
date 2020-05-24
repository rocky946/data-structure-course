// 递归求解汉诺塔问题
#include <stdio.h>

/**
 *
 * @param n 盘片数量
 * @param X 原始塔
 * @param Y 中间塔
 * @param Z 目标塔
 */
void Hanoi1(int n, char X, char Y, char Z) {
    if (n == 1) {
        printf("\t将第%d个盘片从%c移动到%c\n", n, X, Z);
    } else {
        Hanoi1(n - 1, X, Z, Y);
        printf("\t将第%d个盘片从%c移动到%c\n", n, X, Z);
        Hanoi1(n - 1, Y, X, Z);
    }
}

int main() {
    int n = 3;

    Hanoi1(n, 'X', 'Y', 'Z');

    return 0;
}