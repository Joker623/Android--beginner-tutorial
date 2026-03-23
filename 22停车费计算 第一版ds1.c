#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 原始记录结构体
typedef struct {
    char carmark[11];   // 车牌号，长度不超过10，留一位给'\0'
    char start[6];      // 进入时间 HH:MM，共5个字符+'\0'
    char end[6];        // 离开时间 HH:MM
} Record;

// 聚合结果结构体，用于存储每个车牌的总分钟数和车牌号
typedef struct {
    char carmark[11];
    int totalMinutes;   // 总停车分钟数
} Result;

// 将时间字符串 "HH:MM" 转换为分钟数
int timeToMinutes(const char *timeStr) {
    int hour = (timeStr[0] - '0') * 10 + (timeStr[1] - '0');
    int minute = (timeStr[3] - '0') * 10 + (timeStr[4] - '0');
    return hour * 60 + minute;
}

// 用于 qsort 的比较函数，按车牌号字典序排序
int cmpByPlate(const void *a, const void *b) {
    Result *r1 = (Result *)a;
    Result *r2 = (Result *)b;
    return strcmp(r1->carmark, r2->carmark);
}

int main() {
    int n;
    scanf("%d", &n);

    // 读取所有记录
    Record *records = (Record *)malloc(n * sizeof(Record));
    for (int i = 0; i < n; i++) {
        scanf("%s %s %s", records[i].carmark, records[i].start, records[i].end);
    }

    // 结果数组，最多有 n 个不同的车牌
    Result *results = (Result *)malloc(n * sizeof(Result));
    int resultCount = 0; // 当前已存储的不同车牌数量

    // 遍历每条记录，累加每个车牌的总停车时间
    for (int i = 0; i < n; i++) {
        char *plate = records[i].carmark;
        int startMin = timeToMinutes(records[i].start);
        int endMin = timeToMinutes(records[i].end);
        int duration = endMin - startMin;   // 本次停车分钟数

        // 查找该车牌是否已经在 results 中
        int found = -1;
        for (int j = 0; j < resultCount; j++) {
            if (strcmp(results[j].carmark, plate) == 0) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            // 已存在，累加分钟数
            results[found].totalMinutes += duration;
        } else {
            // 新车牌，添加到 results 中
            strcpy(results[resultCount].carmark, plate);
            results[resultCount].totalMinutes = duration;
            resultCount++;
        }
    }

    // 按车牌号字典序排序
    qsort(results, resultCount, sizeof(Result), cmpByPlate);

    // 输出结果，计算费用：总分钟数向上取整到小时，每小时5元
    for (int i = 0; i < resultCount; i++) {
        int totalHours = (results[i].totalMinutes + 59) / 60; // 向上取整
        int fee = totalHours * 5;
        printf("%s %d\n", results[i].carmark, fee);
    }

    // 释放内存
    free(records);
    free(results);
    return 0;
}
