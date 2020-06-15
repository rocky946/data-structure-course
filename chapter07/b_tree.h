#ifndef CHAPTER07_B_TREE_H
#define CHAPTER07_B_TREE_H

#define MAX_SIZE 100

typedef char ElemType;

// 二叉链结点类型
typedef struct node {
    // 数据元素
    ElemType data;
    // 指向左孩子结点
    struct node *lchild;
    // 指向右孩子结点
    struct node *rchild;
} BTNode;

/**
 * 创建二叉树
 * @param b
 * @param str
 */
void CreateBTree(BTNode *&b, char *str);

/**
 * 销毁二叉树
 * @param b
 */
void DestroyBTree(BTNode *&b);

/**
 * 查找结点
 * @param b
 * @param x
 * @return
 */
BTNode *FindNode(BTNode *b, ElemType x);

/**
 * 查找左孩子
 * @param p
 * @return
 */
BTNode *LchildNode(BTNode *p);

/**
 * 查找右孩子
 * @param p
 * @return
 */
BTNode *RchildNode(BTNode *p);

/**
 * 求二叉树高度
 * @param b
 * @return
 */
int BTHeight(BTNode *b);

/**
 * 输出二叉树
 * @param b
 */
void DisplayBTree(BTNode *b);

#endif //CHAPTER07_B_TREE_H
