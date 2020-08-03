#include <stdio.h>

int main(void)
{
	int arr[10] = { 1,3,2,5,7,6,10,9,8,4 };
	int i, j, tmp;
	for (i = 0; i < 9; i++)
	{
		j = i;
		while (j >= 0 && arr[j] > arr[j + 1]) {
			tmp = arr[j]; 
			arr[j] = arr[j + 1];
			arr[j + 1] = tmp;
			j--;
		}
	}
	for (i = 0; i < 10; i++) {
		printf("%2d", arr[i]);
	}
	return 0;
}