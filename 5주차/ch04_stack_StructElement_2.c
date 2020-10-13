#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define MAX_STRING 100

typedef struct {
	int		student_no;
	char	name[MAX_STRING];
	char	address[MAX_STRING];
} element;

element  stack[MAX_STACK_SIZE];
int  top = -1;

// ���� ���� ���� �Լ�
int is_empty()
{
	return (top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full()
{
	return (top == (MAX_STACK_SIZE - 1));
}
// ���� �Լ�
void push(element item)
{
	if (is_full()) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else stack[++top] = item;
}
// ���� �Լ�
element pop()
{
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return stack[top--];
}
// ��ũ�Լ�
element peek()
{
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return stack[top];
}

int main(void)
{
	element ie[3] = {
		{20190001,"Hong","Soeul"}, 
		{20190002,"kim","inchon"},
		{20190003,"lee","siheong"}};
	element oe;
	 
	for (int i = 0; i < 3; i++) {
		push(ie[i]);
	}
	int cnt = top + 1; //�ֳ��ϸ� top = -1 �� ����Ű�� �����̴�. 
	for (int i = 0; i < cnt; i++) {
		oe = pop();
		printf("�й�: %d\n", oe.student_no);
		printf("�̸�: %s\n", oe.name);
		printf("�ּ�: %s\n", oe.address);
		putchar('\n');
	}

	return 0;
}