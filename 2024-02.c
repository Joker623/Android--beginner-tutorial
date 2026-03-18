//#include <stdio.h>
//
//int main(){
//	int n,i;
//	scanf("%d",&n);
//	int a[n];
//	for (i = 0; i < n; i++){
//		scanf("%d",&a[i]);
//		if(a[i] % 7 ==0 && a[i] % 4 != 0){
//			printf("%d ",a[i]);
//		}
//	}
//	return 0;
//}
#include <stdio.h>

int main() {
    int n, i, num;
    scanf("%d", &n);
    if (n <= 0) return 0;  // 无有效数据直接结束

    int first = 1;  // 标记是否为第一个输出的数
    for (i = 0; i < n; i++) {
        scanf("%d", &num);
        if (num % 7 == 0 && num % 4 != 0) {
            if (first) {
                printf("%d", num);
                first = 0;
            } else {
                printf(" %d", num);
            }
        }
    }
    printf("\n");  // 输出换行，使格式更整洁
    return 0;
}
