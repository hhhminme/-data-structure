#include <stdio.h>
#include <time.h>
double power_loop(double x, int n); //for loop
double power_rec(double x, int n); //recursive 

int main(void) {
	//power_loop(), power_rec()...
	clock_t start, end;
	double duration,result ;

	start = clock();
	//�Լ� ȣ��...
	result = power_rec(2.0, 32);
	end = clock(); //msec
	
	duration = (double)(end - start);
	
	printf(">���� �ð� = %lf sec\n", duration/CLOCKS_PER_SEC);
	printf(">result = %lf\n", result);

	return 0;
}

//�ݺ� ������� �ŵ����� ���
double power_loop(double x, int n) {
	double result = 1.0;
	for (int i = 0; i < n; i++) {
		result = result * x;
		printf("- ���� ����\n");
	}
	return result;
}
//��ȯ ������� �̵����� ��� �Լ�...
double power_rec(double x, int n) {
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

