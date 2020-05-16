#include <stdio.h>
#include "sq_string.h"

void LongestString(SqString s, int &index, int &maxLen) {
    int length, i = 1, start;
    // index: 最长平台在s中的开始位置; maxLen: 最长平台长度
    index = 0, maxLen = 1;

    while (i < s.length) {
        // 查找局部重复子串
        start = i - 1;
        length = 1;

        while (i < s.length && s.data[i] == s.data[i - 1]) {
            i++;
            length++;
        }

        if (maxLen < length) {
            maxLen = length;
            index = start;
        }
        i++;
    }
}

int main() {
    char s[] = {'a', 'd', 'd', 'd', '\0'};

    SqString str;
    StrAssign(str, s);
    int index;
    int maxLen;

    LongestString(str, index, maxLen);
    printf("index: %d\n", index);
    printf("maxLen: %d\n", maxLen);
}