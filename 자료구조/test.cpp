//time.h 헤더파일 사용해서 
//power_loop (반복 하는 함수) 거듭 곱 
//power_rec (recursive 거듭곱)... 
// 두가지 시간 측정 할 수 있도록 만들기. 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
int power_loop(int num, int x);
int power_rec(int num, int x);
int main(void) {
	clock_t start, end; 
	double duration; 
	int result, num, x; 

	printf("곱할 숫자를 입력해주세요(num)");
	scanf("%d", &num);
	printf("횟수를 입력해주세요(x)");
	scanf("%d", &x);

	start = clock(); 
	result = power_rec(num,x); //num 을 x번 반복
	//power_rec(num,x)
	end = clock(); 

	duration = (double)(start - end);

	printf("duration : %lf\n", duration/CLOCKS_PER_SEC);
	printf("result : %d\n", result);

	return 0; 
}

int power_loop(int num, int x) {
	int result = 1;
	for (int i = 0; i <= x; i++) {
		result = result *num;
		printf("%d : result",result);
	}
	return result; 
}

int power_rec(int num, int x) {
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





