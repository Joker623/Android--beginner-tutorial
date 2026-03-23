#include <stdio.h>
#include <stdlib.h>

int cmp(const void * p1, const void * p2){
	return *(int *)p1 - *(int *) p2;
} 

int main() {
    // Write your code here
    int n;
    scanf("%d",&n);
    int i,a[n];
    for (i = 0; i < n; i++){
    	scanf("%d",&a[i]);
	}
	int cnt = 0;
	qsort(a,n,sizeof(int),cmp);
	for (i = 0; i< n; i++){ //最巧妙的地方  只有交界处会不同 有set 
		if(a[i] != a[i + 1]) cnt ++;
	}
	printf("%d",cnt);
    return 0;
}

