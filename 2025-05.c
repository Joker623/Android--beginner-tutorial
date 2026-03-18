#include <stdio.h>
#include <stdlib.h>

// 定义飞机结构，包含最晚起飞时间（deadline）和起飞所需时间（duration）
typedef struct {
    int deadline;
    int duration;
} Plane;
//a：是qsort传递给比较函数的第一个参数，它的类型是const void *。void *是一种通用指针，
//可以指向任何类型的数据，但不能直接解引用，因为编译器不知道它指向的数据有多大、是什么结构。

//(Plane *)：这是一个强制类型转换操作符。它将a从const void *类型转换为Plane *类型（指向Plane结构体的指针）。
//转换后，编译器就知道这个指针指向的是一个Plane结构体，后续可以通过该指针访问结构体成员。

//Plane *pa：定义了一个名为pa的变量，类型是Plane *，即指向Plane结构体的指针。然后将转换后的指针值赋给pa。
//现在pa就可以当作普通的Plane指针使用了。
// 比较函数：先按最晚起飞时间升序，相同时按耗时升序（短任务优先）
int cmp(const void *a, const void *b) {
    Plane *pa = (Plane *)a;
    Plane *pb = (Plane *)b;
    //->是结构体指针访问成员运算符，等价于(*pa).deadline
    if (pa->deadline != pb->deadline)
        return pa->deadline - pb->deadline;
    else
        return pa->duration - pb->duration;
}

int main() {
    int n,i;
    scanf("%d", &n);
    Plane *planes = (Plane *)malloc(n * sizeof(Plane));
    for (i = 0; i < n; i++) {
        scanf("%d %d", &planes[i].deadline, &planes[i].duration);
    }

    // 按策略排序
    qsort(planes, n, sizeof(Plane), cmp);

    int cur_time = 0;  // 当前已用总时间（即下一架飞机可以开始起飞的时间）
    int count = 0;     // 能起飞的飞机数量

    for (i = 0; i < n; i++) {
        // 如果当前时间不超过该飞机的最晚起飞时间，则可以安排
        if (cur_time <= planes[i].deadline) {
            cur_time += planes[i].duration;  // 占用跑道
            count++;
        }
        // 否则跳过该飞机
    }

    printf("%d\n", count);

    free(planes);
    return 0;
}
