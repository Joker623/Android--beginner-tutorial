#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//图书馆书籍管理系统 

//1.小结  几个大问题说一下
//2. 输入数据的统一  卡了2小时  分情况就行
//3.  第二个大循环 i j 不分  做错了很多了   
//4.  借书 还书 查书的时候不知道 循环内放什么代码  乱写
//5. 利用flag  随便控制特别的输入输出
//6. 字符是第一个输出的时候 一定要注意 吸收换行符   易错点 
//7. scanf("%c") 和 getchar() 都可以读入换行符（'\n'） 
typedef struct {
	int num;
	char bookname[20];
	int flag;
}Book;  //书的结构体内容 

int cmp (const void * p1, const void * p2){
	Book * book1 = (Book *) p1;
	Book * book2 = (Book *) p2;
	return book1->num - book2->num;
}//查询时需要编号升序输出 

int main() {
    int n;
    scanf("%d",&n);
    int i;
    Book books[n];
    //读入数据 
    for(i = 0; i < n; i++){
    	scanf("%d %s %d",&books[i].num,books[i].bookname,&books[i].flag);
	}
	//按书的编号排序 
	qsort(books,n,sizeof(Book),cmp);
	int m;
	scanf("%d",&m);
	int j;
	getchar();//吸收换行 
	//7. scanf("%c") 和 getchar() 都可以读入换行符（'\n'）
	for(i = 0; i < m; i++){
		char c; 
		int flag1 = 0,flag2 = 0 ,flag3 = 0;
		char bookn[20];
		int booknum; 
		//7. scanf("%c") 和 getchar() 都可以读入换行符（'\n'）
		if(i != 0 ){
			getchar();
		}
		scanf("%c",&c);
		if(c == 'Q'){  //查书的时候后面输入书名是字符串 
			scanf("%s",bookn);
		}
		else if(c == 'B' || c == 'R'){ //借还书的时候 后面是书编号 整数 
			scanf("%d",&booknum);
		}
		
		
		if(c == 'Q'){
				for(j = 0; j < n; j++){
					if(strcmp(bookn,books[j].bookname) == 0){
//					printf("%d %s %d\n",books[j].num,books[j].bookname,books[j].flag);
//为了ac 写了一个
				 printf("%d %s",books[j].num,books[j].bookname);
				 if(books[j].flag == 0){
				 	printf(" 可借\n");
				 }
				 else if(books[j].flag == 1){
				 	printf(" 已借出\n");
				 }
					flag1 = 1;
				}
			}
			//循环完都没找到就输出 
			if(flag1 == 0){
					printf("Not Found\n");
				}
			
		}
		
		
		else if(c == 'B'){
			for(j = 0; j < n; j++){
				if(books[j].num == booknum){ 
					if(books[j].flag == 0){ //可以借才借出去 
						books[j].flag = 1;
						printf("Succeed\n");
						flag2 = 1;
						break;
					} 
				}
				
			}
			if(flag2 == 0){
					printf("Failed\n");
				}
		}
		
		
		else if(c == 'R'){
			for(j = 0; j < n; j++){
				if(books[j].num == booknum){ 
					if(books[j].flag == 1){ //可以还才还回去 
						books[j].flag = 0;
						printf("Succeed\n");
						flag3 = 1;
						break;
					}
				}
			}
			if(flag3 == 0){
					printf("Failed\n");
				}
		}
	}
    return 0;
}

