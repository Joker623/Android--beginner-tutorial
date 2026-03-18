#include <stdio.h>
#include <string.h>

#define MAX_CARS 1000   // 假设最多1000辆车，可根据需要调整

// 记录每个车的累计信息
typedef struct {
    char plate[20];     // 车牌号
    int total_fee;      // 总费用
    int free_used;      // 是否已使用免费机会（0未用，1已用）
    int order;          // 第一次出现的顺序（用于输出）
} CarInfo;

int main() {
    int n,i,order,j;
    scanf("%d", &n);
    
    // 存储所有输入记录
    struct Record {
        char plate[20];
        int time;
    } records[n];
    
    for ( i = 0; i < n; i++) {
        scanf("%s %d", records[i].plate, &records[i].time);
    }
    
    CarInfo cars[MAX_CARS];
    int car_count = 0;  // 不同车牌的数量
    
    // 遍历每条记录
    for ( i = 0; i < n; i++) {
        char *plate = records[i].plate;
        int time = records[i].time;
        
        // 查找该车牌是否已经在cars中
        int idx = -1;
        for ( j = 0; j < car_count; j++) {
            if (strcmp(cars[j].plate, plate) == 0) {
                idx = j;
                break;
            }
        }
        
        // 如果是新车牌，添加到cars
        if (idx == -1) {
            idx = car_count;
            strcpy(cars[idx].plate, plate);
            cars[idx].total_fee = 0;
            cars[idx].free_used = 0;
            cars[idx].order = car_count; // 记录第一次出现的顺序
            car_count++;
        }
        
        // 计算本条记录的费用
        int fee = 0;
        if (time < 60) {
            if (!cars[idx].free_used) {
                // 第一次小于1小时，免费
                cars[idx].free_used = 1;
                fee = 0;
            } else {
                // 已用过免费，按1小时收费
                fee = 5;
            }
        } else {
            // 大于等于1小时，按小时数向上取整
            int hours = (time + 59) / 60;  // 向上取整
            fee = hours * 5;
        }
        
        // 累加费用，并确保不超过50
        cars[idx].total_fee += fee;
        if (cars[idx].total_fee > 50) {
            cars[idx].total_fee = 50;
        }
    }
    
    // 按第一次出现的顺序输出
    // 由于order记录了顺序，我们可以直接按order排序
    // 简单起见，可以按order从小到大输出
    for (order = 0; order < car_count; order++) {
        // 找到order对应的车
        for (i = 0; i < car_count; i++) {
            if (cars[i].order == order) {
                printf("%s:%d\n", cars[i].plate, cars[i].total_fee);
                break;
            }
        }
    }
    
    return 0;
}
