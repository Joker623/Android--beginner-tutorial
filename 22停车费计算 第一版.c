#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//没做出来 
typedef struct {
	char carmark[10];
	char start[10];
	char end[10];
	int money;
	int totaltime;
//	int flag;
}car;
//int cmp(const void * p1, const void * p2){
//	car * c1 = (car *) p1;
//	car * c2 = (car *) p2;
//	return strcmp(c1->carmark,c2->carmark); 
//}
int hrs(char a[]){
	return (a[0] -'0') * 10 + (a[1] - '0');
}
int mins(char a[]){
	return (a[3] -'0') * 10 + (a[4] - '0');
}
int main() {
    // Write your code here
    int n;
    scanf("%d",&n);
    int i;
    car cars[n];
    for (i = 0; i < n; i++){
    	scanf("%s %s %s",cars[i].carmark,cars[i].start,cars[i].end);
	}
//	for (i = 0; i < n; i++){
//    	cars[i].flag = 0;
//	}
	for (i = 0; i < n; i++){
    	cars[i].money = 0;
	}
//	qsort(cars,n,sizeof(car),cmp);
	char temp [10];
	for(i = 0; i < n; i++){
		//问题所在 ： 这里真不知道怎么去重复 
		//很简单  车牌一样 什么不一样  进入时间啊  不用去重 和排序 
		for(j = 0; j < n; j++){
			if(str(cars[i].carmark,cars[j].carmark) == 0 && strcmp(cars[i].start,cars[j].start) != 0){
				
			}
		}
	}
    return 0;
}

