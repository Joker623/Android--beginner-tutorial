//#include <stdio.h>
//
//double factorial(int n){
//	double sum = 1.0;
//	int i;
//	for (i = 1; i <= n; i++){
//		sum *= i;
//	}
//	return sum;
//}
//int main(){
//	int n;
//	scanf("%d",&n);
//	int i;
//	double sum = 1,fz = 1; 不需要分子 没变用常量 
//	for(i = 1; i <= n; i++){ 
//		sum += fz*1.0 / factorial(i); n大时这里会溢出 
//	}
//	printf("%.8lf",sum);
//	return 0;
//} 
#include <stdio.h>

int main() {
    int n,i;
    scanf("%d", &n);
    double sum = 1.0;  // 第0项 1/0! = 1
    double term = 1.0; // 当前项的值
    for (i = 1; i <= n; i++) {
    	//不断去除 非常巧妙 
        term /= i;      // 得到 1/i!
        sum += term;
    }
    printf("%.8lf\n", sum);
    return 0;
}
