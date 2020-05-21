// BF算法统计子串的个数
#include <stdio.h>
#include "sq_string.h"

int BF(SqString s, SqString t) {
    int count = 0, i = 0, j = 0;

    // 两个串都没有扫描完时循环
    while (i < s.length) {
        // 当前比较的两个字符相同，比较后续字符
        if (s.data[i] == t.data[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }

        if (j == t.length) {
            count++;
            j = 0;
        }
    }

    return count;
}

int main() {
    SqString s, t;
    char c1[] = {'a', 'b', 'a', 'b', 'c', '\0'};
    char c2[] = {'a', 'b', '\0'};
    StrAssign(s, c1);
    StrAssign(t, c2);
    printf("s:");
    DispStr(s);
    printf("t:");
    DispStr(t);
    printf("个数:%d\n", BF(s, t));
    return 0;
}