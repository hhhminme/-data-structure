//O(N*log N) 분할 정복 채택, 정확히 반씩 나눔, 
//항상 nlogn보장

//일단 반으로 나누고 나중에 합쳐서 정렬하면 어떨까?
//피벗값이 없고 항상 반으로 나눔
//합칠땐 2의 배수만큼 합침  

#include <stdio.h>
# define number 8
int sorted[8]; 
//정렬 배열은 반드시 전역변수로 선언
//추가적인 배열이 필요한데 필요할때마다 배열을 생성하는게 비효율적
//모든 함수가 공통적으로 sorted 배열을 사용 

void merge(int a[], int m, int middle, int n) {
	int i = m;
	int j = middle + 1; 
	int k = m;
	//작은 순서대로 배열에 삽입. 
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
	//남은 데이터도 삽입 
	if (i > middle) {
		for (int t = j; t <= n; t++) {
			sorted[k] = a[t];
			k++;
		}
	}
	else{
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
	int array[number] = { 7,6,5,8,3,5,9,1 };
	mergeSort(array, 0, number - 1);
	for (int i = 0; i < number; i++) {
		printf("%d ", array[i]);
	}
	return 0; 
}