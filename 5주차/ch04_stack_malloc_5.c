#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
//���� �������̰� ���õ� ���
typedef int element;
typedef struct {
	element *data;		// data�� �����ͷ� ���ǵȴ�. 
	int capacity;		// ���� ũ��
	int top;
} StackType;

// ���� ���� �Լ�
void init_stack(StackType *s) //���� �ٽ����� �κ� 
{
	s->top = -1;
	s->capacity = 1; //capacity�� ���� �ʱ� ���̸� ��Ƶ�.. ���⼱ �ش������� 1
	s->data = (element *)malloc(s->capacity * sizeof(element)); //sizeof element == 4; data == 4;
	//1���� ��Ҹ� ������ �� �ִ� ������ �ϴ� Ȯ��
} 

// ���� ���� ���� �Լ�
int is_empty(StackType *s)
{
	return (s->top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full(StackType *s)
{
	return (s->top == (s->capacity - 1));
}
void push(StackType *s, element item)
{
	if (is_full(s)) { //��� ������ full�� �Ǽ� realloc�� �Ǵ��İ� �߿���
		printf(">full �뷮�ø�( %d)\n",s->capacity);
		s->capacity *= 2;
		s->data =
			(element *)realloc(s->data, s->capacity * sizeof(element));
		//������ �����ϸ� �޸𸮸� 2��� �� Ȯ���Ѵ�. capacity�� �ι� ���ݾ�. 
		//return ���� �׻� Ȯ���ض� -> �ü���� system call�� Ȯ���ϱ� ���� 
		//-> heap�� �����ϸ� ������ ���� ����
	}
	else {
		printf("%>push : not full\n");
	}
	s->data[++(s->top)] = item;
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
int main(void)
{
	StackType s;
	init_stack(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	push(&s, 4);
	push(&s, 5);
	printf("%d \n", pop(&s));
	printf("%d \n", pop(&s));
	printf("%d \n", pop(&s));
	free(s.data);
	return 0;
}