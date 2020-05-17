#include <stdio.h>
#include <malloc.h>
#include "linked_string.h"

void Rep1(LinkStrNode *&s) {
    LinkStrNode *p = s->next, *q;

    bool find = false;
    // 查找'ab'子串
    while (nullptr != p && nullptr != p->next && !find) {
        // 找到子串'ab'
        if (p->data == 'a' && p->next->data == 'b') {
            // 替换
            p->data = 'x';
            p->next->data = 'z';

            // p和p.next中间插入'y'
            q = (LinkStrNode *) malloc(sizeof(LinkStrNode));
            q->data = 'y';
            q->next = p->next;
            p->next = q;
            find = true;
        }
        // 尚未找到时继续查找
        else {
            p = p->next;
        }
    }
}

int main() {
    char cstr[] = {'a', 'b', 'c', 'd', 'e', 'f', '\0'};

    LinkStrNode *str;
    StrAssign(str, cstr);
    printf("init str len: %d\n", StrLength(str));
    printf("init str disp:");
    DispStr(str);

    Rep1(str);
    printf("rep1 str len: %d\n", StrLength(str));
    printf("rep1 str disp:");
    DispStr(str);

    return 0;
}