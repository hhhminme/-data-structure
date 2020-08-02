// 1 ~ 10 까지 정렬 하기 
#include<stdio.h>
int main(void) {
	int arr[10] = { 1,3,2,5,7,6,10,9,8,4 };

	int i, j, index, temp;

	for (i = 0; i < 10; i++) {
		int min = 11;
		for (j = i; j < 10; j++) {
			if (arr[j] < min) {
				min = arr[j];
				index = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}
	for (i = 0; i < 10; i++) {
		printf("%d", arr[i]);
	}
	return 0;
}