#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
//
typedef char element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;
//
void init_stack(StackType* s)
{
	s->top = -1;
}
//
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// 
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
//
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
//
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
//
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[s->top];
}
//
int check_matching(const char* in)
{
	StackType s;
	StackType no;
	char ch, open_ch;
	int i, n = strlen(in);  	// n= ���ڿ��� ����
	init_stack(&s);				// ������ �ʱ�ȭ
	init_stack(&no);
	int count = 1;
	printf("��ȣ �� : ");
	for (i = 0; i < n; i++) {
		ch = in[i];				// ch = ���� ����
		switch (ch) {
		case '(':   case '[':    case '{': //���� ��ȣ�� ������
			push(&s,ch);
			push(&no, (char)(count));
			printf("%d ", (int)peek(&no));
			count++;
			break;
		case ')':   case ']':    case '}':
			if (is_empty(&s))  return 0;
			else {
				open_ch = pop(&s);
				if ((open_ch == '(' && ch != ')') || //open_ch = ���ʰ�ȣ ch = ������ ��ȣ
					(open_ch == '[' && ch != ']') || //ch �� ���� ���� ���ϱ� ������ return ���� �Ѿ
					(open_ch == '{' && ch != '}')) {
					
					return 0;
				}
				printf("%d ",(int)pop(&no));
				break;
			}
		}
	}
	if (!is_empty(&s)) return 0;	// ���ÿ� ���������� ���� -> return 0 -> false �� �ǹ� 
	return 1; //true�� ����
}

int main(void)
{
	char* p = "((())(()))";
	printf("���� : %s\n", p);
	if (check_matching(p) == 1)
		printf("\n��ȣ�˻缺��");
	else
		printf("\n��ȣ�˻����");
	return 0;
}
//�ڵ尡 ������ �ڵ忡 ���� ���� 
//�ڵ带 ����� �ڵ带 �ۼ��϶�
//�ڵ带 �м��϶�
//�ڵ� �м��� ���� �ϰ� ���� �� �ܿ���