#include "bst.h"
#include <stdio.h>

int main() {
    BSTNode *bt, *p, *f;
    int n = 12, x = 46;

    KeyType a[] = {25, 18, 46, 2, 53, 39, 32, 4, 74, 67, 60, 11};
    bt = CreateBST(a, n);
    printf("BST:");
    DispBST(bt);
    printf("\n");

    printf("删除%d结点\n", x);
    if (SearchBST(bt, x) != nullptr) {
        DeleteBST(bt, x);
        printf("BST:");
        DispBST(bt);
        printf("\n");
    }
    x = 18;
    p = SearchBST1(bt, x, nullptr, f);
    if (f != nullptr)
        printf("%d的双亲是%d\n", x, f->key);
    DestroyBST(bt);

    return 0;
}