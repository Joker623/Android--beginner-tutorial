//#include <stdio.h>
//
//int main(){
//	int nums,i,sum = 0;
//	for(i = 1; i <= 8; i++){
//		nums *= 2;
//	}
//	printf("%d",765 / nums);
//	return 0;
//}

//#include <stdio.h>
//
//int main() {
//    int total = 765;
//    //等比数列求和公式 
//    int sum = (1 << 8) - 1;  // 2^8 - 1 = 255
//    int top = total / sum;
//    printf("%d\n", top);
//    return 0;
//}
#include <stdio.h>

int main() {
    int total = 765;
    int base = 1; // 最上层灯数初始值
    int sum;
    int i; 
    // 从1开始尝试，直到找到满足条件的值
    while (1) {
        sum = 0;
        int layer = base;
        for (i = 0; i < 8; i++) {
            sum += layer;
            layer *= 2;
        }
        if (sum == total) {
            printf("最上层灯数为：%d\n", base);
            break;
        }
        base++;
    }
    return 0;
} 
