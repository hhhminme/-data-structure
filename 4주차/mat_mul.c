#include <stdio.h>
#define MAX_ROW_COLUMN  3
void print_matrix(int m[MAX_ROW_COLUMN][MAX_ROW_COLUMN]);
void mul_matrix(int a[MAX_ROW_COLUMN][MAX_ROW_COLUMN],
				int b[MAX_ROW_COLUMN][MAX_ROW_COLUMN],
				int c[MAX_ROW_COLUMN][MAX_ROW_COLUMN]);
int main(void)
{
	int a[MAX_ROW_COLUMN][MAX_ROW_COLUMN] = 
		{	{ 1, 2, 3},
			{ 4, 5, 6},
			{ 7, 8, 9}
		};
	int b[MAX_ROW_COLUMN][MAX_ROW_COLUMN] =
		{	{ 1, 2, 3},
			{ 4, 5, 6},
			{ 7, 8, 9}
		};
	int c[MAX_ROW_COLUMN][MAX_ROW_COLUMN] = { 0 };

	printf("1. print a[][]\n");
	print_matrix(a);
	printf("2. print b[][]\n");
	print_matrix(b);
	printf("3. print c[][]\n");
	print_matrix(c);

	mul_matrix(a, b, c);

	printf("4. print c[][]\n");
	print_matrix(c);
	return 0;
}

void mul_matrix(	int a[MAX_ROW_COLUMN][MAX_ROW_COLUMN], 
					int b[MAX_ROW_COLUMN][MAX_ROW_COLUMN],
					int c[MAX_ROW_COLUMN][MAX_ROW_COLUMN] ) 
{
	// 1. 매트릭스를 곱하는 함수를 완성하시오.  c = a x b
	int sum = 0; 
	for (int i = 0; i < MAX_ROW_COLUMN; i++) {
		for (int j = 0; j < MAX_ROW_COLUMN; j++) {
			for (int k = 0; k < MAX_ROW_COLUMN; k++) {
				sum += a[i][k] * b[k][j];
				c[i][j] = sum;
				
			}
			sum = 0;
		}
	}
}

void print_matrix( int m[MAX_ROW_COLUMN][MAX_ROW_COLUMN] )
{
	for (int i = 0; i < MAX_ROW_COLUMN; i++) {
		for (int j = 0; j < MAX_ROW_COLUMN; j++) {
			printf("%d\t", m[i][j]);
		}
		putchar('\n');
	}
}


