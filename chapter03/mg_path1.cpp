// 使用顺序队求解迷宫问题
#include <stdio.h>
#include "sq_queue.h"

#define M 8
#define N 8
int mg[M + 2][N + 2] =
        {
                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
                {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
                {1, 0, 0, 0, 0, 1, 1, 0, 0, 1},
                {1, 0, 1, 1, 1, 0, 0, 0, 0, 1},
                {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
                {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
                {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
                {1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
        };

/**
 * 输出迷宫路径
 * @param queue
 * @param front
 */
void print(SqQueue *queue, int front) {
    int k = front;
    int j;

    // 反向找到最短路径，将该路径上的方块的pre置为-1
    do {
        j = k;
        k = queue->data[k].pre;
        queue->data[j].pre = -1;
    } while (k != 0);

    printf("一条迷宫路径如下：\n");
    k = 0;
    // 正向搜索pre为-1的方块，即构成正向的路径
    int nl = 0;
    while (k < MAX_SIZE) {
        if (queue->data[k].pre == -1) {
            nl++;
            printf("\t(%d,%d)", queue->data[k].i, queue->data[k].j);
            // 每输出5个方块后换行
            if (nl % 5 == 0) {
                printf("\n");
            }
        }
        k++;
    }
    printf("\n");
}

/**
 * 查找迷宫路径
 * @param xi 入口行号
 * @param yi 入口列号
 * @param xe 出口行号
 * @param ye 出口列号
 * @return
 */
bool MgPath1(int xi, int yi, int xe, int ye) {
    SqQueue *queue = nullptr;
    InitQueue(queue);

    Box e;
    e.i = xi;
    e.j = yi;
    e.pre = -1;
    enQueue(queue, e);
    // 置为-1，避免重复搜索
    mg[xi][yi] = -1;

    int i, j, di, i1 = 0, j1 = 0;
    while (!QueueEmpty(queue)) {
        // 出队，由于不是环形队列，该出队元素仍在队列中
        deQueue(queue, e);
        i = e.i;
        j = e.j;
        // 找到出口，输出路径
        if (i == xe && j == ye) {
            print(queue, queue->front);
            DestroyQueue(queue);
            return true;
        }

        // 循环扫描每个方位，把每个可走的方块插入到队列中
        for (di = 0; di < 4; ++di) {
            switch (di) {
                case 0:
                    i1 = i-1;
                    j1 = j;
                    break;
                case 1:
                    i1 = i;
                    j1 = j + 1;
                    break;
                case 2:
                    i1 = i + 1;
                    j1 = j;
                    break;
                case 3:
                    i1 = i;
                    j1 = j - 1;
                    break;
            }

            if (mg[i1][j1] == 0) {
                // 找到一个相邻可走方块
                e.i = i1;
                e.j = j1;
                // 指向路径中上一个方块的下标
                e.pre = queue->front;
                enQueue(queue, e);
                // 将其置为-1，以避免重复搜搜
                mg[i1][j1] = -1;
            }
        }
    }

    DestroyQueue(queue);
    // 未找到任何路径返回false
    return false;
}

int main() {
    if (!MgPath1(1, 1, M, N)) {
        printf("该迷宫问题没有解!\n");
    }

    return 0;
}