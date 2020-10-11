 #include <stdio.h>
#define MAX_DEGREE 101 	// ���׽��� �ִ����� + 1
typedef struct {
	int degree; //���� 
	float coef[MAX_DEGREE]; //coefficient ���
} polynomial;

int MAX(int a, int b);
polynomial poly_add1(polynomial A, polynomial B);
void print_poly(polynomial p);

// ���Լ�
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
	// MAX() �Լ��� �ϼ��Ͻÿ�.
	if (a > b) return a;
	else if (a < b) return b;
	else return a;
}

// C = A+B ���⼭ A�� B�� ���׽��̴�. ����ü�� ��ȯ�ȴ�. 
polynomial poly_add1(polynomial A, polynomial B)
{
	polynomial C;						// ��� ���׽�
	int Apos = 0, Bpos = 0, Cpos = 0;	// �迭 �ε��� ����
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree); // ��� ���׽� ����

	while (Apos <= A.degree && Bpos <= B.degree) {
		if (degree_a > degree_b) {		// A�� > B��
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if (degree_a < degree_b) {	// B�� > A��
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
		else {							// A�� == B��
			C.coef[Cpos++] = A.coef[Apos++] - B.coef[Bpos++];
			degree_a--;
			degree_b--;
		}
	}
	return C;
}

void print_poly(polynomial p)
{
	// x �׵� ���� ������ ���.
	// index 0 : �ְ� ���� ���� ����� �����.
	for (int i = p.degree; i > 0; i--) {
		printf("(%3.1f)x^%d + ", p.coef[p.degree - i], i);
	}
	// ������ ��� ���.
	printf("(%3.1f) \n", p.coef[p.degree]);
}




