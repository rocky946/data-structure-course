#include <stdio.h>
#include <malloc.h>
#include <cstring>
#include "bst.h"

bool InsertBST(BSTNode *&bt, KeyType k) {
    // 原树为空，新插入的结点为根结点
    if (nullptr == bt) {
        bt = (BSTNode *) malloc(sizeof(BSTNode));
        bt->key = k;
        bt->lchild = bt->rchild = nullptr;
        return true;
    }
    // 树中存在相同关键字的结点，返回假
    else if (k == bt->key) {
        return false;
    }
    // 插入到左子树中
    else if (k < bt->key) {
        return InsertBST(bt->lchild, k);
    }
    // 插入到右子树中
    else {
        return InsertBST(bt->rchild, k);
    }
}

BSTNode *CreateBST(KeyType a[], int n) {
    // 返回BST树根结点指针,初始时bt为空树
    BSTNode *bt = nullptr;

    int i = 0;
    while (i < n) {
        InsertBST(bt, a[i]);
        i++;
    }
    return bt;
}

void DispBST(BSTNode *bt) {
    if (nullptr != bt) {
        printf("%d", bt->key);
        if (nullptr != bt->lchild || nullptr != bt->rchild) {
            // 有孩子结点时输出(
            printf("(");
            // 递归处理左子树
            DispBST(bt->lchild);
            // 有右孩子结点时才输出,
            if (nullptr != bt->rchild) {
                printf(",");
            }
            // 递归处理右子树
            DispBST(bt->rchild);
            // 有孩子结点时才输出)
            printf(")");
        }
    }
}

BSTNode *SearchBST(BSTNode *bt, KeyType k) {
    // 递归终止条件
    if (nullptr == bt || bt->key == k) {
        return bt;
    }

    // 在左子树中递归查找
    if (k < bt->key) {
        return SearchBST(bt->lchild, k);
    } else {
        return SearchBST(bt->rchild, k);
    }
}

BSTNode *SearchBST1(BSTNode *bt, KeyType k, BSTNode *f1, BSTNode *&f) {
    if (nullptr == bt) {
        f = nullptr;
        return nullptr;
    } else if (k == bt->key) {
        f = f1;
        return bt;
    } else if (k < bt->key) {
        // 在左子树中递归查找
        return SearchBST1(bt->lchild, k, bt, f);
    } else {
        // 在右子树中递归查找
        return SearchBST1(bt->rchild, k, bt, f);
    }
}

bool DeleteBST(BSTNode *&bt, KeyType k) {
    // 空树删除失败，返回false
    if (nullptr == bt) {
        return false;
    } else {
        // 递归在左子树中删除关键字为k的结点
        if (k < bt->key) {
            return DeleteBST(bt->lchild, k);
        }
        // 递归在右子树中删除关键字为k的结点
        else if (k > bt->key) {
            return DeleteBST(bt->rchild, k);
        }
        // 调用Delete(bt)函数删除结点bt
        else {
            Delete(bt);
            return true;
        }
    }
}

void Delete(BSTNode *&p) {
    BSTNode *q = nullptr;
    // 结点p没有右子树
    if (nullptr == p->rchild) {
        q = p;
        // 用结点p的左孩子替代它
        p = p->lchild;
        free(q);
    }
    // 结点p没有左子树
    else if (nullptr == p->lchild) {
        q = p;
        // 用结点p的右孩子替代它
        p = p->rchild;
        free(q);
    }
    // 结点p既有左子树又有右子树的情况
    else {
        Delete1(p, p->lchild);
    }
}

void Delete1(BSTNode *p, BSTNode *&r) {
    BSTNode *q = nullptr;
    // 递归查找结点r的最右下结点
    if (nullptr != r->rchild) {
        Delete1(p, r->rchild);
    }
    // 找到了最右下结点(没有右子树)
    else {
        // 将结点r的值存放到结点p中
        p->key = r->key;
        strcpy(p->data, r->data);
        // 删除结点r
        q = r;
        // 用结点r的左孩子替代它
        r = r->lchild;
        free(q);
    }
}

void DestroyBST(BSTNode *&bt) {
    if (nullptr != bt) {
        DestroyBST(bt->lchild);
        DestroyBST(bt->rchild);
        free(bt);
    }
}
