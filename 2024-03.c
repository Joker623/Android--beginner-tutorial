//#include <stdio.h>
//#include <stdlib.h>
//int cmp1 (const void* p1, const void* p2){
//	return (*(int*) p1 - *(int*)p2);
//}
//
//int cmp2 (const void* p1, const void* p2){
//	return (*(int*) p2 - *(int*)p1);
//}
//int main(){
//	int i,j;
//	int nums[3][5] = {
//		{2,4,23,1,5},
//		{6,4,5,32,1},
//		{5,7,3,45,1}
//	};
//	for(i = 0; i < 3; i += 2 ){
//		for(j = 0; j < 5; j++ ){
//			qsort(nums,)
//		}
//	}
//	for(i = 1; i < 3; i += 2 ){
//		for(j = 0; j < 5; j++ ){
//			
//		}
//	}
//	return 0;
//}
#include <stdio.h>
#include <stdlib.h>

// ÉýÐò±ÈÝ^º¯”µ
int cmp_asc(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

// ½µÐò±ÈÝ^º¯”µ
int cmp_desc(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}

int main() {
    int nums[3][5] = {
        {2, 4, 23, 1, 5},
        {6, 4, 5, 32, 1},
        {5, 7, 3, 45, 1}
    };
    int rows = 3, cols = 5;
	int i,j;
    // Œ¦»ù”µÐÐ£¨Ë÷Òý0¡¢2£©ÉýÐòÅÅÐò
    for (i = 0; i < rows; i += 2) {
        qsort(nums[i], cols, sizeof(int), cmp_asc);
    }
    // Œ¦Å¼”µÐÐ£¨Ë÷Òý1£©½µÐòÅÅÐò
    for (i = 1; i < rows; i += 2) {
        qsort(nums[i], cols, sizeof(int), cmp_desc);
    }

    // Ý”³öÅÅÐòááµÄ”µ½M
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", nums[i][j]);
        }
        printf("\n");
    }
    return 0;
}
