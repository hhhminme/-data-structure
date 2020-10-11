#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
	switch (op) {
		case '(': case ')': return 0;
		case '+': case '-': return 1;
		case '*': case '/': return 2;
	}
	return -1;
}
// ���� ǥ�� ���� -> ���� ǥ�� ����
void infix_to_postfix(char exp[])
{
	int i = 0;
	char ch, top_op;
	int len = strlen(exp);
	StackType s;
	init_stack(&s);					// ���� �ʱ�ȭ 
	for (i = 0; i<len; i++) {
		ch = exp[i];
		switch (ch) {
		case '+': case '-': case '*': case '/': // ������
			// ���ÿ� �ִ� �������� �켱������ �� ũ�ų� ������ ���
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s)))) {
				printf("%c", pop(&s));
			}
			push(&s, ch);
			break;
		case '(':	// ���� ��ȣ
			push(&s, ch);
			break;
		case ')':	// ������ ��ȣ
			top_op = pop(&s);
			// ���� ��ȣ�� ���������� ���
			while (top_op != '(') {
				printf("%c", top_op);
				top_op = pop(&s);
			}
			break;
		default:		// �ǿ�����
			printf("%c", ch);
			break;
		}
	}
	while (!is_empty(&s)) {
		// ���ÿ� ����� �����ڵ� ���
		printf("%c", pop(&s));
	}
}
// 
int main(void)
{
	char *s = "(2+3)*4+9";
	printf("����ǥ�ü��� %s \n", s);
	printf("����ǥ�ü��� ");
	infix_to_postfix(s);
	printf("\n");
	return 0;
}