#include <stdio.h>
#include <time.h>
int fib(int n); //��ȯ ȣ��, recursive call 
int fib_iter(int n); //�ݺ�, iterative exe.
int call[50];
int value[50];

int main(void) {
	int result;
	clock_t start, end; //�ð� ���� ��Ÿ��
	double duration;

	start = clock();
	for (int i = 0; i <= 40; i++) {
		result = fib(i);
		//result = fib_iter(i);

		printf("%d\t ", result);
	}
	end = clock();
	printf("\n");
	duration = (double)(start - end) / CLOCKS_PER_SEC;
	printf("duration : %lf\n", duration);

	for (int i = 0; i < 40; i++) {
		printf("-f(%d)= %d\n", i, call[i]);
	}

	return 0;
}

int fib(int n) {
	int temp, temp1, temp2;
	//printf("- fibo(%d)\n", n);
	call[n]++;

	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;

	if (value[n - 1] == 0) { //���� ����� ���� ��� 
		temp1 = fib(n - 1);
	}
	else {
		temp1 = value[n - 1]; //�̹� ���� ���
	}

	if (value[n - 2] == 0) { //���� ����� ���� ��� 
		temp2 = fib(n - 2);
	}
	else {
		temp2 = value[n - 2]; //�̹� ���� ���
	}

	temp = temp1 + temp2; 
	value[n] = temp;
	return temp;
}

int fib_iter(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;

	int pp = 0;
	int p = 1;
	int result = 0;

	for (int i = 2; i <= n; i++) {
		result = p + pp;
		pp = p;
		p = result;
	}
	return result;
}