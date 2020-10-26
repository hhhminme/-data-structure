#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// ���� �ʱ�ȭ �Լ�
void init_stack(StackType *s)
{
	s->top = -1;
}

// ���� ���� ���� �Լ�
int is_empty(StackType *s)
{
	return (s->top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// �����Լ�
void push(StackType *s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// �����Լ�
element pop(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
// ��ũ�Լ�
element peek(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[s->top];
}


int main(void)
{
	StackType *s; //�����͸� �����ϰ� //�������� ���� ���ü���

	s = (StackType *)malloc(sizeof(StackType));
	//malloc�� ���� �������� �޸𸮸� �Ҵ� 
	//������ malloc�Ƚ����� &s �� �Ķ���͸� �Ѱ��� 
	//������ �����ͷ� �������־��� ������ s�θ� �Ѱ��ָ� �ȴ�. 
	//������ ����ִ� ����� static�̳� dynamic�̳ĸ� Ȯ��
	init_stack(s);
	//���� ���ÿ� ���� �����ڵ��� �Լ��� �����ϰ� ��� 
	push(s, 1);
	push(s, 2);
	push(s, 3);
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));

	printf("%d\n", pop(s));
	free(s);
}
