#include <stdio.h>

void swap(int* px, int* py);

int main(void)
{
	int a = 1, b = 2;
	printf("> swap�� ȣ���ϱ� ��: a=%d, b=%d\n", a, b);
	swap(&a, &b);
	printf("> swap�� ȣ���� ����: a=%d, b=%d\n", a, b);
	return 0;
}

void swap(int* px, int* py)
{
	int tmp;
	tmp = *px;
	*px = *py;
	*py = tmp;
}
//������ �����ϰ� ������ �����͸� �Ѱ��༭ main�� a,b�� �������ش�.
//Ȥ�� ����ü�� ������ش�.(����ü�� �ϳ��� ������ ó���ϱ� �����̴�.)

