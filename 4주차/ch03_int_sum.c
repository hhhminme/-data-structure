#include <stdio.h>
#define SIZE 6
int cal_sum(int list[]);
void get_integers(int list[]);

int main(void)
{
	int list[SIZE];
	get_integers(list);
	printf("> �� = %d \n", cal_sum(list));
	return 0;
}

void get_integers(int list[])
{
	printf("6���� ������ �Է��Ͻÿ�: ");
	for (int i = 0; i < SIZE; ++i) {
		scanf("%d", &list[i]);
	}
}

int cal_sum(int list[])
{
	int sum = 0;
	for (int i = 0; i < SIZE; ++i) {
		sum += *(list + i);
	}
	return sum;
}

