#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
//花了25分钟没做对 
//抓紧时间 
//一定亲自动手ac为止   结果没问题 
//ds的代码 结果也是反的   是编辑器的问题 
typedef struct{
	char carmark[12];
	int starthr;
	int endhr;
	int starmin;
	int endmin;
}Car;

int cmp(const void * p1, const void * p2){
	Car * car1 = (Car *) p1;
	Car * car2 = (Car *) p2;
	return strcmp(car1->carmark,car2->carmark);
}

int main(){
	int n,i;
	scanf("%d",&n);
	Car cars[n];
	//Car * cars = (Car *)malloc(n * sizeof(Car));
	for(i = 0; i < n; i++){
		scanf("%s %d:%d %d:%d",cars[i].carmark,&cars[i].starthr,&cars[i].starmin,&cars[i].endhr,&cars[i].endmin);
	}
	qsort(cars,n,sizeof(Car),cmp);
	i = 0;
	while(i < n){
		//累加的数据都要初始化为0； 
		int totalm = 0,totalmin = 0;
		char * temp = cars[i].carmark; //这里瞎赋值 看清楚什么类型 
		int j = i;
		while(j < n && strcmp(temp,cars[j].carmark) == 0){
			//错误的写法 totalmin每次都会被覆盖 有问题    写成累加好吗 
//			totalmin = (cars[j].endhr - cars[j].starthr) * 60;
			totalmin += (cars[j].endhr - cars[j].starthr) * 60;
			totalmin += cars[j].endmin - cars[j].starmin;
			j ++;
		}
		//这里傻傻分不清楚整数出发 和 小数除法  ceil没有意义 
		//totalm = ceil(totalmin / 60) * 5;
		totalm = ceil(totalmin * 1.0 / 60) * 5;
		//这里输出 cars[j].carmark 是要干嘛  j是用来移动位置的
		//temp 才是这次的车牌 
		printf("%s %d\n",temp,totalm);
		i = j;
	}
	return 0;
}
