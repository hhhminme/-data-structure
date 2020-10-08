#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 6
int cal_sum(int list[]);
void get_integers(int list[]);

int main(void)
{
	int list[SIZE];
	get_integers(list); //&list[0] 배열의 이름은 첫번째 배열의 주소
	printf("> 합 = %d \n", cal_sum(list));
	return 0;
}

void get_integers(int list[])
{
	printf("6개의 정수를 입력하시오: ");
	for (int i = 0; i < SIZE; ++i) {
		scanf("%d", &list[i]);
	}
}

int cal_sum(int list[])
{
	int sum = 0;
	for (int i = 0; i < SIZE; ++i) {
		sum += *(list + i); //sum += list[i]; //표현 같으니깐 외워둬라 시험에도 나올 수 있다.
	}
	return sum;
}