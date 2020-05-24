// 非递归求Fibonacci数列的第n项
#include <stdio.h>

int Fib2(int n) {
    int a = 1, b = 1, s;
    if (n == 1 || n == 2) {
        return 1;
    } else {
        for (int i = 3; i <= n; ++i) {
            s = a + b;
            b = a;
            a = s;
        }
    }

    return s;
}

int main() {
    int n = 10;
    printf("sum: %d\n", Fib2(n));
}