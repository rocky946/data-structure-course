// 递归求Fibonacci数列的第n项
#include <stdio.h>

int Fib1(int n) {
    if (n == 1 || n == 2) {
        return 1;
    } else {
        return Fib1(n - 1) + Fib1(n - 2);
    }
}

int main() {
    int n = 10;
    printf("sum: %d\n", Fib1(n));
}