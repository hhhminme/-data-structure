#include <stdio.h>
#define number 10
int sorted[10];

void merge(int a[], int m, int middle, int n) {
	int i = m; 
	int j = middle + 1; 
	int k = m; 

	while (i <= middle && j <= n) {
		if (a[i] <= a[j]) {
			sorted[k] = a[i]; 
			i++;
		}
		else {
			sorted[k] = a[j];
			j++;
		}
		k++;
	}
	if (i > middle) {
		for (int t = j; t <= n; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	else {
		for (int t = i; t <= middle; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	//정렬된 배열을 삽입
	for (int t = m; t <= n; t++) {
		a[t] = sorted[t];
	}
}

void mergeSort(int a[], int m, int n) {
	//이외의 경우는 크기가 1개인 경우 
	if (m < n) {
		int middle = (m + n) / 2;
		mergeSort(a, m, middle);
		mergeSort(a, middle + 1, n);
		merge(a, m, middle, n);
	}
}

int main(void) {
	int array[number] = { 1,5,2,9,10,8,7,3,2,4 };
	mergeSort(array, 0, number - 1);
	for (int i = 0; i < number; i++) {
		printf("%d ", array[i]);
	}

	return 0;
}