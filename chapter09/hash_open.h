#ifndef CHAPTER09_HASH_OPEN_H
#define CHAPTER09_HASH_OPEN_H

// 定义空关键字值
#define NULLKEY -1
// 定义被删关键字值
#define DELETKEY -2
// 关键字类型
typedef int KeyType;
#define MAX_SIZE 100

// 哈希表单元类型
typedef struct {
    // 关键字域
    KeyType key;
    // 探测次数域
    int count;
} HashTable;

/**
 * 将关键字k插入哈希表
 * @param ha 哈希表
 * @param n 哈希表元素个数
 * @param m 哈希表长度
 * @param p 除数
 * @param k 关键字值
 */
void InsertHT(HashTable ha[], int &n, int m, int p, KeyType k);

/**
 * 根据关键字数组创建哈希表
 * @param ha 哈希表
 * @param n 哈希表元素个数
 * @param m 哈希表长度
 * @param p 除数
 * @param keys 关键字数组
 * @param n1 关键字数组长度
 */
void CreateHT(HashTable ha[], int &n, int m, int p, KeyType keys[], int n1);

/**
 * 删除哈希表中关键字k
 * @param ha 哈希表
 * @param n 哈希表元素个数
 * @param m 哈希表长度
 * @param p 除数
 * @param k 关键字
 * @return
 */
bool DeleteHT(HashTable ha[], int &n, int m, int p, KeyType k);

/**
 * 查找哈希表中关键字k
 * @param ha 哈希表
 * @param m 哈希表长度
 * @param p 长度
 * @param k 关键字
 */
void SearchHT(HashTable ha[], int m, int p, KeyType k);

/**
 * 计算哈希表平均查找长度
 * @param ha 哈希表
 * @param n 哈希表元素个数
 * @param m 哈希表长度
 * @param p 除数
 */
void ASL(HashTable ha[], int n, int m, int p);

/**
 * 输出哈希表
 * @param ha 哈希表
 * @param n 哈希表元素个数
 * @param m 哈希表长度
 * @param p 除数
 */
void DispHT(HashTable ha[], int n, int m, int p);

#endif //CHAPTER09_HASH_OPEN_H
