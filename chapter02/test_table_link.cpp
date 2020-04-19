#include <stdio.h>
#include "table_link.h"

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);

    HList *h1, *h2, *h;

    printf("创建表1：\n");
    CreateTable(h1);
    printf("disp_h1:\n");
    DispTable(h1);

    printf("创建表2：\n");
    CreateTable(h2);
    printf("disp_h2:\n");
    DispTable(h2);

    // 连接表
    LinkTable(h1, h2, h);
    printf("disp_h:\n");
    DispTable(h);

    DestroyTable(h1);
    DestroyTable(h2);
    DestroyTable(h);

    return 0;
}