#include <stdio.h>
int data[] = { 4,10,5,3,2,9,7,8,6,1 };
int number = 10; 

quickSort(int* data, int start, int end) {
	if (start >= end) {
		return;
	}

	int key = start; //key�� ù ��° ����
	int i = start + 1; 
	int j = end;
	int temp;

	while (i <= j) { //�������� ���� �ݺ�
		//Ű������ ū ���� ���� ��
		while (i <= end && data[i] <= data[key]) {
			i++;
		}
		while (data[j] >= data[key]) {
			j--;
		}
		//���� ������ ���¸� Ű ���� ��ü
		if (i > j) {
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		//�������� �ʾҴٸ� i�� j�� ��ü
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