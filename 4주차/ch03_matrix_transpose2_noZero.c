#include <stdio.h>
#define MAX_TERMS 101
typedef struct {
	int row;
	int col;
	int value;
} element;

typedef struct SparseMatrix { //희소행렬
	element data[MAX_TERMS];
	int rows;	// 행의 개수
	int cols;	// 열의 개수
	int terms; 	// 항의 개수
} SparseMatrix;


void matrix_print(SparseMatrix a);
SparseMatrix matrix_transpose2(SparseMatrix a);

// 
int main(void)
{
	SparseMatrix m = {
		{	{ 0, 3, 7 },{ 1, 0, 9 },{ 1, 5, 8 },{ 3, 0, 6 },
			{ 3, 1, 5 },{ 4, 5, 1 },{ 5, 2, 2 } },
		6, //열의 개수
		6, //행의 개수 
		7  //항의 개수
	};
	SparseMatrix result;
	result = matrix_transpose2(m);
	matrix_print(m);
	matrix_print(result);
	return 0;
}

SparseMatrix matrix_transpose2(SparseMatrix a) //계산된 전치행렬 구조체 b를 반환 
{
	SparseMatrix b;
	int bindex;		// 행렬 b에서 현재 저장 위치
	b.rows = a.rows;
	b.cols = a.cols;
	b.terms = a.terms;
	if (a.terms > 0) {
		bindex = 0;
		// row 값 오름차순으로 정렬하기 위한 for문장.
		for (int c = 0; c < a.cols; c++) { //기존 행열의 열이 행으로 변경되기 때문에 
			for (int i = 0; i < a.terms; i++) {
				if (a.data[i].col == c) { //0열에 있는 요소를 모두 찾아 전치행렬의 0열에 저장 
					b.data[bindex].row = a.data[i].col;
					b.data[bindex].col = a.data[i].row;
					b.data[bindex].value = a.data[i].value;
					bindex++;
				}
			}
		}
	}
	return b;
}

void matrix_print(SparseMatrix a)
{
	printf("====================\n");
	for (int i = 0; i < a.terms; i++) {
		printf("(%d, %d, %d) \n", a.data[i].row, a.data[i].col, a.data[i].value);
	}
	printf("====================\n");
}



