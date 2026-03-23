#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 停车记录结构体
typedef struct {
    char carmark[11];   // 车牌号
    char start[6];      // 进入时间 HH:MM
    char end[6];        // 离开时间 HH:MM
} car;

// 将时间字符串 "HH:MM" 转换为分钟数
int timeToMinutes(const char *t) {
    int hour = (t[0] - '0') * 10 + (t[1] - '0');
    int minute = (t[3] - '0') * 10 + (t[4] - '0');
    return hour * 60 + minute;
}

// 按车牌号字典序排序的比较函数（用于 qsort）
int cmpByPlate(const void *a, const void *b) {
    car *c1 = (car *)a;
    car *c2 = (car *)b;
    return strcmp(c1->carmark, c2->carmark);
}

int main() {
    int n;
    scanf("%d", &n);

    // 动态分配内存，存储所有记录
    car *cars = (car *)malloc(n * sizeof(car));
    for (int i = 0; i < n; i++) {
        scanf("%s %s %s", cars[i].carmark, cars[i].start, cars[i].end);
    }

    // 按车牌号排序，相同车牌号的记录会相邻
    qsort(cars, n, sizeof(car), cmpByPlate);

    // 遍历排序后的数组，对每个车牌累加总停车分钟数
    int i = 0;
    while (i < n) {
        // 当前处理的车牌号
        char *currentPlate = cars[i].carmark;
        int totalMinutes = 0;

        // 收集当前车牌的所有记录
        int j = i;
        while (j < n && strcmp(cars[j].carmark, currentPlate) == 0) {
            int startMin = timeToMinutes(cars[j].start);
            int endMin = timeToMinutes(cars[j].end);
            totalMinutes += (endMin - startMin);
            j++;
        }

        // 计算费用：总分钟数向上取整到小时，每小时5元
        int totalHours = (totalMinutes + 59) / 60;  // 向上取整
        int fee = totalHours * 5;

        // 输出结果
        printf("%s %d\n", currentPlate, fee);

        // 移动到下一个车牌
        i = j;
    }

    free(cars);
    return 0;
}
