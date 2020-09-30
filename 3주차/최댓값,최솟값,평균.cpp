#include <stdio.h>
int main(void)
{
	int data[10] = { 1,4,2,3,7,6,5,9,8,10 };
	int max, min,sum;
	double avg = 0.0;

	max = data[0];
	min = data[0];
	sum = data[0];
	for (int i = 1; i < 10; i++) {
		if (max <= data[i]) {
			max = data[i];
		}
		if (min >= data[i]) {
			min = data[i];
		}
		sum += data[i];
	}
	avg = (double)(sum / 10);

	printf("max : %d, min : %d, avg: %lf", max, min, avg);
	return 0;
}