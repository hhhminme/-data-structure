#include <stdio.h>

int main(void) {
	int i, j, temp;
	int arr[10] = { 1,3,2,5,7,6,10,9,8,4 };
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 9 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for (i = 0; i < 10; i++) {
		printf("%3d", arr[i]);
	}
	return 0;
}