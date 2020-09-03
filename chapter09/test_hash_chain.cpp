#include "hash_chain.h"
#include <stdio.h>

int main() {
    int keys[] = {16, 74, 60, 43, 54, 90, 46, 31, 29, 88, 77};
    int n, m = 13, p = 13, k = 29;
    HashTable ha[MAX_SIZE];

    printf("(1)创建哈希表\n");
    CreateHT(ha, n, m, p, keys, 11);

    printf("(2)显示哈希表:\n");
    DispHT(ha, n, m, p);

    printf("(3)查找");
    SearchHT(ha, p, k);

    k = 77;
    printf("(4)删除：关键字%d\n", k);
    DeleteHT(ha, n, p, k);

    printf("(5)显示哈希表:\n");
    DispHT(ha, n, m, p);;

    printf("(6)查找");
    SearchHT(ha, p, k);

    printf("(7)插入：关键字%d\n", k);
    InsertHT(ha, n, p, k);

    printf("(8)显示哈希表:\n");
    DispHT(ha, n, m, p);;
    printf("\n");

    //销毁哈希表

    DestroyHT(ha, m);
    return 0;
}