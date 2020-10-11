#include <stdio.h>
#include <stdlib.h>

// ���Ŀ� ������ �ʿ��ϸ� ���⸸ �����Ͽ� ���δ�. 
// ===== ���� �ڵ��� ���� ===== 
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType; //����ü�� ���� stack�� ���������μ� �������� stack�� ����ϱ� ����

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
// ===== ���� �ڵ��� �� ===== 


int main(void)
{
	StackType* s;
	s = (StackType*)malloc(sizeof(StackType));
	if (s == NULL) {
		printf("malloc ����\n");
		exit(1);
	}
	init_stack(s); //s�� ����Ű�� �����͸� ����Ŵ
	
	push(s, 1);
	push(s, 2);
	push(s, 3);
	
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));

	free(s);
	return 0;
}
