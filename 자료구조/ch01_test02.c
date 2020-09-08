#include <stdio.h>
#include <time.h>
#define DATA_SIZE 100000
#define LOOP_CNT 10000

int main(void) {
	int data[DATA_SIZE]; //hard coding
	double result = 0.0;
	time_t start, end;
	double duration; 

	// data �迭 �� �ʱ�ȭ.
	for (int i = 0; i < DATA_SIZE; i++) {
		data[i] = i + 1; 
	}
	start= time(NULL); //sec
	printf(">���α׷� ���� �ð� ������ �����մϴ�.\n");
	//���� �ӵ� ���� ����. 
	for (int i = 0; i < LOOP_CNT; i++) {
		for (int j = 0; j < DATA_SIZE; j++) {
			result += (double)data[i];
		}
	}
	end = time(NULL); 
	printf(">���α׷� ���� �ð� ������ �Ϸ��մϴ�.\n");
	//���� �ӵ� ���� �Ϸ�...
	duration = (double)(end - start);

	printf("> ���� �ð� = %lf sec \n", duration);
	printf("- CLOCKS_PER_SEC : %d \n", CLOCKS_PER_SEC);
	return 0;
}