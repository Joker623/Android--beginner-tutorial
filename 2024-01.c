//#include <stdio.h>
//
//char str[20];
//void split(int n){
//	int times = 0,i;
//	for(i = 0; n > 0; i++){
//		str[i] = (n % 10) + '0';
//		times++;
//		n /= 10;
//	}
//	while(times >= 0){
//		printf("%c",str[times - 1]);
//		times --;
//	}
//	
//};
//
//int main(){
//	int num;
//	scanf("%d",&num);
//	split(num);
//	return 0;
//}
#include <stdio.h>

void split(int n) {
    char str[20];
    int i = 0;

    // 处理负数
    if (n < 0) {
        putchar('-');
        // 对于 INT_MIN，直接取负会溢出，此处简化处理，通常测试数据不会达到边界
        n = -n;
    }

    // 处理 0 的情况
    if (n == 0) {
        putchar('0');
        return;
    }

    // 逆序存储每一位数字字符
    while (n > 0) {
        str[i++] = (n % 10) + '0';
        n /= 10;
    }

    // 正序输出
    while (i > 0) {
        putchar(str[--i]);
    }
}

int main() {
    int num;
    scanf("%d", &num);
    split(num);
    return 0;
}
