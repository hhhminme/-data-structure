//time.h ������� ����ؼ� 
//power_loop (�ݺ� �ϴ� �Լ�) �ŵ� �� 
//power_rec (recursive �ŵ��)... 
// �ΰ��� �ð� ���� �� �� �ֵ��� �����. 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
int power_loop(int num, int x);
int power_rec(int num, int x);
int main(void) {
	clock_t start, end; 
	double duration; 
	int result, num, x; 

	printf("���� ���ڸ� �Է����ּ���(num)");
	scanf("%d", &num);
	printf("Ƚ���� �Է����ּ���(x)");
	scanf("%d", &x);

	start = clock(); 
	result = power_rec(num,x); //num �� x�� �ݺ�
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
		printf("-�������:�� \n");
		return power_rec(x * x, n / 2);
	}
	else if (n % 2 == 1) {
		printf("-�������:�� 2ȸ\n");
		return x* power_rec(x * x, n / 2);
	}
}





