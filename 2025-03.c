//#include <stdio.h>
//
//int a[26];
//int b[26];
//int main(){
//	int n,i;
//	char str[100];
//	scanf("%d",&n);
//	for (i = 0; i < n; i++){
//		scanf("%s",str);
//		if(isupper(str[0])){
//			a[str[0] - 'A'] ++;
//		}
//		else{
//			b[str[0] - 'a'] ++;
//		}
//	}
//	for(i = 0; i < 26; i++){
//		if(a[i] > 0){
//			 printf("%c:%d\n",'A' + i, a[i]) ;
//		} 
//	} 
//	for(i = 0; i < 26; i++){
//		if(b[i] > 0){
//			 printf("%c:%d\n",'a' + i, b[i]) ;
//		} 
//	} 
//	return 0;
//} 
#include <stdio.h>
#include <ctype.h>   // 包含isupper函数

int a[26];  // 大写字母计数
int b[26];  // 小写字母计数

int main() {
    int n, i;
    char str[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s", str);  // 简单起见仍用scanf，实际可用fgets更安全
        char first = str[0];
        if (isupper(first)) {
            a[first - 'A']++;
        } else if (islower(first)) {  // 明确判断小写，避免非字母情况
            b[first - 'a']++;
        }
        // 若题目保证一定是字母，也可以直接else，但加上判断更严谨
    }
    // 输出大写统计（ASCII码较小，先输出）
    for (i = 0; i < 26; i++) {
        if (a[i] > 0) {
            printf("%c:%d\n", 'A' + i, a[i]);
        }
    }
    // 输出小写统计
    for (i = 0; i < 26; i++) {
        if (b[i] > 0) {
            printf("%c:%d\n", 'a' + i, b[i]);  // 补上换行符
        }
    }
    return 0;
}
