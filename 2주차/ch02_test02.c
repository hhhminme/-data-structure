#include <stdio.h>
#include <time.h>
double power_loop(double x, int n); //for loop
double power_rec(double x, int n); //recursive 

int main(void) {
	//power_loop(), power_rec()...
	clock_t start, end;
	double duration,result ;

	start = clock();
	//함수 호출...
	result = power_rec(2.0, 32);
	end = clock(); //msec
	
	duration = (double)(end - start);
	
	printf(">실행 시간 = %lf sec\n", duration/CLOCKS_PER_SEC);
	printf(">result = %lf\n", result);

	return 0;
}

//반복 방법으로 거듭제곱 계산
double power_loop(double x, int n) {
	double result = 1.0;
	for (int i = 0; i < n; i++) {
		result = result * x;
		printf("- 연산 실행\n");
	}
	return result;
}
//순환 방법으로 겁드제곱 계산 함수...
double power_rec(double x, int n) {
	if (n == 0) {
		return 1.0;
	}
	else if (n % 2 == 0) {
		printf("-연산실행:곱 \n");
		return power_rec(x * x, n / 2);
	}
	else if (n % 2 == 1) {
		printf("-연산실행:곱 2회\n");
		return x* power_rec(x * x, n / 2);
	}
}

