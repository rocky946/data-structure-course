#ifndef CHAPTER09_BST_H
#define CHAPTER09_BST_H

// 定义关键字类型为int
typedef int KeyType;
// 定义其他数据项类型为char[]
typedef char InfoType[10];

// 二叉排序树结点类型
typedef struct node {
    // 关键字项
    KeyType key;
    // 其他数据域
    InfoType data;
    // 左右孩子指针
    struct node *lchild, *rchild;
} BSTNode;

/**
 * 在二叉排序树中插入一个关键字为k的结点，若插入成功返回真，否则返回假
 * @param bt
 * @param k
 * @return
 */
bool InsertBST(BSTNode *&bt, KeyType k);

/**
 * 根据指定数组创建二叉排序树
 * @param a
 * @param n
 * @return
 */
BSTNode *CreateBST(KeyType a[], int n);

/**
 * 输出一颗二叉排序树
 * @param bt
 */
void DispBST(BSTNode *bt);

/**
 * 查找二叉排序树
 * @param bt
 * @param k
 * @return
 */
BSTNode *SearchBST(BSTNode *bt, KeyType k);

/**
 * 查找二叉排序树并返回其双亲节点
 * @param bt
 * @param k
 * @param f1
 * @param f
 * @return
 */
BSTNode *SearchBST1(BSTNode *bt, KeyType k, BSTNode *f1, BSTNode *&f);

/**
 * 删除二叉排序树中关键字为k的结点
 * @param bt
 * @param k
 * @return
 */
bool DeleteBST(BSTNode *&bt, KeyType k);

/**
 * 从二叉排序树中删除结点p
 * @param p
 */
void Delete(BSTNode *&p);

/**
 * 删除二叉排序树结点p,p既有左子树又有右子树，r指向其左孩子
 * @param p
 * @param r
 */
void Delete1(BSTNode *p, BSTNode *&r);

/**
 * 销毁二叉排序树bt
 * @param bt
 */
void DestroyBST(BSTNode *&bt);

#endif //CHAPTER09_BST_H
