#include <stdio.h>
#include <time.h>
int fib(int n); //순환 호출, recursive call 
int fib_iter(int n); //반복, iterative exe.
int call[50];
int value[50];

int main(void) {
	int result;
	clock_t start, end; //시간 측정 스타일
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

	if (value[n - 1] == 0) { //계산된 결과가 없는 경우 
		temp1 = fib(n - 1);
	}
	else {
		temp1 = value[n - 1]; //이미 계산된 경우
	}

	if (value[n - 2] == 0) { //계산된 결과가 없는 경우 
		temp2 = fib(n - 2);
	}
	else {
		temp2 = value[n - 2]; //이미 계산된 경우
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