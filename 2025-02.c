//#include <stdio.h>
//
//int main(){
//	char str[20];
//	scanf("%s",str);
//	int i,num1 = 0,num2 = 0,flag = 0;
//	for (i = 0; str[i]; i++){
//		while(str[i] != '+' || str[i] != '-' || str[i] != '*'){
//			num1 = num1 * 10 + i;
//		}
//		if (str[i] == )
//	}
//	return 0;
//}

#include <stdio.h>
#include <ctype.h>  // 用于isdigit函数

int main() {
    char str[100];  // 足够存储表达式
    scanf("%s", str);
    
    int i = 0;
    int num1 = 0, num2 = 0;
    char op = 0;
    
    // 解析第一个数字
    while (isdigit(str[i])) {
        num1 = num1 * 10 + (str[i] - '0');
        i++;
    }
    
    // 此时应该遇到运算符
    op = str[i];
    i++;  // 跳过运算符
    
    // 解析第二个数字
    while (isdigit(str[i])) {
        num2 = num2 * 10 + (str[i] - '0');
        i++;
    }
    
    // 根据运算符计算结果
    int result;
    switch (op) {
        case '+': result = num1 + num2; break;
        case '-': result = num1 - num2; break;
        case '*': result = num1 * num2; break;
        default: 
            printf("无效运算符\n");
            return 1;
    }
    
    printf("%d\n", result);
    return 0;
} 
