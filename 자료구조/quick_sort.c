#include <stdio.h>
int data[] = { 4,10,5,3,2,9,7,8,6,1 };
int number = 10; 

quickSort(int* data, int start, int end) {
	if (start >= end) {
		return;
	}

	int key = start; //key는 첫 번째 원소
	int i = start + 1; 
	int j = end;
	int temp;

	while (i <= j) { //엇갈릴때 까지 반복
		//키값보다 큰 값을 만날 때
		while (i <= end && data[i] <= data[key]) {
			i++;
		}
		while (data[j] >= data[key]) {
			j--;
		}
		//현재 엇갈린 상태면 키 값과 교체
		if (i > j) {
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		//엇갈리지 않았다면 i와 j를 교체
		else {
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}

	quickSort(data, start, j - 1);
	quickSort(data, j + 1, end);
}


int main(void) {
	quickSort(data, 0, number - 1);
	for (int i = 0; i < number; i++) {
		printf("%d", data[i]);
	}
	return 0;
}