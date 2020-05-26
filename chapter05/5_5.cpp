// 采用递归算法求解迷宫问题，并输出从入口到出口的所有迷宫路径
#include <stdio.h>

#define MaxSize 100
#define M 4
#define N 4
int mg[M + 2][N + 2] =
        {{1, 1, 1, 1, 1, 1},
         {1, 0, 0, 0, 1, 1},
         {1, 0, 1, 0, 0, 1},
         {1, 0, 0, 0, 1, 1},
         {1, 1, 0, 0, 0, 1},
         {1, 1, 1, 1, 1, 1}
        };

// 方块类型
typedef struct {
    // 方块的行号
    int i;
    // 方块的列号
    int j;
} Box;

// 迷宫路径的类型
typedef struct {
    // 存放一条路径上的所有方块
    Box data[MaxSize];
    // 迷宫路径的长度
    int length;
} PathType;

// 存放迷宫路径的条数
int count = 0;

/**
 * 求解迷宫问题,(xi, yi) -> (xe, ye)
 * @param xi
 * @param yi
 * @param xe
 * @param ye
 * @param path
 */
void mg_path(int xi, int yi, int xe, int ye, PathType path) {
    int di, k, i = 0, j = 0;
    // 找到了出口，输出一条迷宫路径
    if (xi == xe && yi == ye) {
        // 将(xi, yi)添加到path中
        path.data[path.length].i = xi;
        path.data[path.length].j = yi;
        path.length++;

        // 输出path中的迷宫路径
        printf("迷宫路径%d如下：\n", ++count);
        for (k = 0; k < path.length; k++) {
            printf("\t(%d, %d)", path.data[k].i, path.data[k].j);
        }
        printf("\n");
    }
        // (xi, yi)不是出口
    else {
        // (xi, yi)是一个可走方块
        if (mg[xi][yi] == 0) {
            di = 0;
            // 处理(xi, yi)四周的每一个相邻方块(i, j)
            while (di < 4) {
                // 1. 将(xi, yi)添加到path中
                path.data[path.length].i = xi;
                path.data[path.length].j = yi;
                path.length++;

                switch (di) {
                    case 0:
                        i = xi - 1;
                        j = yi;
                        break;
                    case 1:
                        i = xi;
                        j = yi + 1;
                        break;
                    case 2:
                        i = xi + 1;
                        j = yi;
                        break;
                    case 3:
                        i = xi;
                        j = yi - 1;
                        break;
                    default:
                        break;
                }

                // 2. mg[xi][yi] = -1
                mg[xi][yi] = -1;
                // 3. mg_path(i, j, xe, ye, path)
                mg_path(i, j, xe, ye, path);
                // 4. 恢复(xi, yi)为可走
                mg[xi][yi] = 0;
                // 回退一个方块
                path.length--;
                // 继续处理(xi, yi)下一个相邻方块
                di++;
            }
        }
    }
}

int main() {
    PathType path;
    path.length = 0;                //初始化路径长度
    mg_path(1, 1, M, N, path);

    return 0;
}