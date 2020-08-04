//bubble sort 

#include <stdio.h>
int main(void) {
	int arr[] = { 1,5,4,2,10,9,8,6,7,3 };
	int i, j, temp;

	for (i = 0; i < 9; i++) {
		for (j = i; j = 9 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for (i = 0; i < 10; i++) {
		printf("%2d", arr[i]);
	}
	return 0;
}