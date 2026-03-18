//#include <stdio.h>
//输出逻辑错误：对原数组bbooks进行排序后，输出前j个元素的booknum。但排序后数组顺序改变，前j个不一定是目标学号的书籍号，导致输出错误。正确做法是对筛选出的数组a排序。
//
//缺少头文件：qsort函数需要<stdlib.h>，但代码未包含，可能导致编译警告或错误。
//
//潜在数组大小为零：若目标学号没有借书记录，j=0，则int a[j]定义了一个大小为0的数组。C标准中变长数组大小必须为正，零大小是未定义行为，可能引发运行时错误。
//
//变量复用：j先用于计数，后又作为数组下标填充，最后用于循环输出，虽然逻辑上正确，但可读性稍差。
//
//排序函数不匹配：cmp函数比较的是booknum，但排序对象是整个结构体数组，排序后结构体顺序改变，却只输出前几个结构体的booknum，错误如上。
//
//未处理无记录情况：当j=0时，代码会尝试创建大小为0的数组，且后续循环不会执行，但数组定义本身可能出错，应提前处理。
//struct bbook{
//	int stunum;
//	int booknum;
//};
//int cmp(const void* p1, const void* p2){
//	return ((struct bbook*)p1)->booknum - ((struct bbook*)p2)->booknum;
//}
//int main(){
//	int n,i,num;
//	scanf("%d",&n);
//	struct bbook bbooks[n];
//	for(i = 0; i < n; i++){
//		scanf("%d %d",&bbooks[i].stunum,&bbooks[i].booknum);
//	}
//	scanf("%d",&num);
//	int j = 0;
//	for(i = 0; i < n; i++){
//		if(bbooks[i].stunum == num){
//			j++;
//		}
//	}
//	int a[j];
//	j = 0;
//	for(i = 0; i < n; i++){
//		if(bbooks[i].stunum == num){
//			a[j++] = bbooks[i].booknum;
//		}
//	}
////	int sz = sizeof(bbooks) / sizeof(bbooks[0]);
//	qsort(bbooks,n,sizeof(bbooks[0]),cmp);
//	for(i = 0; i < j; i++){
//		printf("%d\n",bbooks[i].booknum);
//	}
//	return 0;
//} 
#include <stdio.h>
#include <stdlib.h>  // 提供qsort

struct bbook {
    int stunum;
    int booknum;
};

// 比较两个整数，用于对书籍号数组排序
int cmp_int(const void* p1, const void* p2) {
    int a = *(int*)p1;
    int b = *(int*)p2;
    return a - b;
}

int main() {
    int n, i, num;
    scanf("%d", &n);
    struct bbook bbooks[n];  // 存储所有借书记录

    // 输入记录
    for (i = 0; i < n; i++) {
        scanf("%d %d", &bbooks[i].stunum, &bbooks[i].booknum);
    }

    // 输入待查询学号
    scanf("%d", &num);

    // 统计该学号借书数量
    int count = 0;
    for (i = 0; i < n; i++) {
        if (bbooks[i].stunum == num) {
            count++;
        }
    }

    // 如果没有借书记录，直接结束
    if (count == 0) {
        return 0;
    }

    // 提取该学号的所有书籍号
    int books[count];  // 变长数组
    int idx = 0;
    for (i = 0; i < n; i++) {
        if (bbooks[i].stunum == num) {
            books[idx++] = bbooks[i].booknum;
        }
    }

    // 对书籍号排序
    qsort(books, count, sizeof(int), cmp_int);

    // 按顺序输出
    for (i = 0; i < count; i++) {
        printf("%d\n", books[i]);
    }

    return 0;
}
