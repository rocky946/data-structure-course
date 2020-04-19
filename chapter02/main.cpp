#include <stdio.h>
#include "array_list.h"

int main() {
    int a[5] = {1, 3, 1, 4, 2};
    int length = sizeof(a) / sizeof(a[0]);

    SqList *list = NULL;

    CreateList(list, a, length);
    printf("ListLength: %d\n", ListLength(list));
    printf("ListEmpty: %d\n", ListEmpty(list));

    DispList(list);

    ElemType e;
    int ret = GetElem(list, 4, e);
    if (ret) {
        printf("e: %d\n", e);
    }

    e = 3;
    ret = LocateElem(list, e);
    if (ret) {
        printf("找到e: %d，序号: %d\n", e, ret);
    } else {
        printf("未找到e: %d\n", e);
    }

    int index = 4;
    e = 9;
    ret = ListInsert(list, index, e);
    if (ret) {
        printf("在第%d个位置上插入e：%d成功\n", index, e);
    }
    DispList(list);

    index = 1;
    ret = ListDelete(list, index, e);
    if (ret) {
        printf("删除第%d个元素成功，e：%d成功\n", index, e);
    }
    DispList(list);

    printf("---------------\n");
    printf("ListLength: %d\n", ListLength(list));
    printf("ListEmpty: %d\n", ListEmpty(list));

    DestroyList(list);

    printf("---------------\n");
    printf("ListLength: %d\n", ListLength(list));
    printf("ListEmpty: %d\n", ListEmpty(list));
    return 0;
}