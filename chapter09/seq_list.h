#ifndef CHAPTER09_SEQ_LIST_H
#define CHAPTER09_SEQ_LIST_H

// 最大长度
#define MAXL 100
// 定义关键字类型为int
typedef int KeyType;
// 定义其他数据项类型为char
typedef char InfoType;

// 查找元素(记录,record)的类型
typedef struct {
    // 关键字项
    KeyType key;
    // 其他数据项
    InfoType data;
} RecType;

/**
 * 创建顺序表
 * @param R 顺序表
 * @param keys 关键字
 * @param n 元素个数
 */
void CreateList(RecType R[], KeyType keys[], int n);

/**
 * 输出顺序表
 * @param R 顺序表
 * @param n 元素个数
 */
void DispList(RecType R[], int n);

#endif //CHAPTER09_SEQ_LIST_H
