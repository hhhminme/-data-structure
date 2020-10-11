 #include <stdio.h>
#define MAX_DEGREE 101 	// 다항식의 최대차수 + 1
typedef struct {
	int degree; //차수 
	float coef[MAX_DEGREE]; //coefficient 계수
} polynomial;

int MAX(int a, int b);
polynomial poly_add1(polynomial A, polynomial B);
void print_poly(polynomial p);

// 주함수
int main(void)
{
	polynomial a = { 6,{ 5 ,0, 4, 0, 7, 2, 9 } };
	polynomial b = { 4,{ 7, 2, 5, 0, 3 } };
	polynomial c;
	print_poly(a);
	print_poly(b);
	c = poly_add1(a, b);
	printf("----------------------------------------------------------------\n");
	print_poly(c);
	return 0;
}

int MAX(int a, int b) {
	// MAX() 함수를 완성하시오.
	if (a > b) return a;
	else if (a < b) return b;
	else return a;
}

// C = A+B 여기서 A와 B는 다항식이다. 구조체가 반환된다. 
polynomial poly_add1(polynomial A, polynomial B)
{
	polynomial C;						// 결과 다항식
	int Apos = 0, Bpos = 0, Cpos = 0;	// 배열 인덱스 변수
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree); // 결과 다항식 차수

	while (Apos <= A.degree && Bpos <= B.degree) {
		if (degree_a > degree_b) {		// A항 > B항
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if (degree_a < degree_b) {	// B항 > A항
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
		else {							// A항 == B항
			C.coef[Cpos++] = A.coef[Apos++] - B.coef[Bpos++];
			degree_a--;
			degree_b--;
		}
	}
	return C;
}

void print_poly(polynomial p)
{
	// x 항들 차수 순서로 출력.
	// index 0 : 최고 고차 항의 계수가 저장됨.
	for (int i = p.degree; i > 0; i--) {
		printf("(%3.1f)x^%d + ", p.coef[p.degree - i], i);
	}
	// 마지막 상수 출력.
	printf("(%3.1f) \n", p.coef[p.degree]);
}




