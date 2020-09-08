#include <stdio.h>
#include <time.h>
#define DATA_SIZE 100000
#define LOOP_CNT 10000

int main(void) {
	int data[DATA_SIZE]; //hard coding
	double result = 0.0;
	time_t start, end;
	double duration; 

	// data 배열 값 초기화.
	for (int i = 0; i < DATA_SIZE; i++) {
		data[i] = i + 1; 
	}
	start= time(NULL); //sec
	printf(">프로그램 실행 시간 측정을 시작합니다.\n");
	//실행 속도 측정 시작. 
	for (int i = 0; i < LOOP_CNT; i++) {
		for (int j = 0; j < DATA_SIZE; j++) {
			result += (double)data[i];
		}
	}
	end = time(NULL); 
	printf(">프로그램 실행 시간 측정을 완료합니다.\n");
	//실행 속도 측정 완료...
	duration = (double)(end - start);

	printf("> 실행 시간 = %lf sec \n", duration);
	printf("- CLOCKS_PER_SEC : %d \n", CLOCKS_PER_SEC);
	return 0;
}