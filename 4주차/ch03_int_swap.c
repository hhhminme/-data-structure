#include <stdio.h>

void swap(int* px, int* py);

int main(void)
{
	int a = 1, b = 2;
	printf("> swap을 호출하기 전: a=%d, b=%d\n", a, b);
	swap(&a, &b);
	printf("> swap을 호출한 다음: a=%d, b=%d\n", a, b);
	return 0;
}

void swap(int* px, int* py)
{
	int tmp;
	tmp = *px;
	*px = *py;
	*py = tmp;
}
//여러개 리턴하고 싶을땐 포인터를 넘겨줘서 main의 a,b를 변경해준다.
//혹은 구조체로 만들어준다.(구조체는 하나로 생각해 처리하기 때문이다.)

