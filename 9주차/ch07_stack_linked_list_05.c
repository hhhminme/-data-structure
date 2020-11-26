#include <stdio.h>
#include <malloc.h>

typedef int element;
typedef struct StackNode {
	element data;
	struct StackNode* link;
} StackNode;

typedef struct {
	StackNode* top;
} LinkedStackType;

// �ʱ�ȭ �Լ�
void init(LinkedStackType* s)
{
	s->top = NULL;
}
int is_empty(LinkedStackType* s) // ���� ���� ���� �Լ�
{
	return (s->top == NULL);
}

int is_full(LinkedStackType* s) // ��ȭ ���� ���� �Լ�
{
	return 0;
}

void push(LinkedStackType* s, element item) // ���� �Լ�
{
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode)); //���� ���� ��� 
	temp->data = item; 
	temp->link = s->top;
	s->top = temp;
}

void print_stack(LinkedStackType* s)
{
	for (StackNode* p = s->top; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

// ���� �Լ�
element pop(LinkedStackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "������ �������\n");
		exit(1);
	}
	else {
		StackNode* temp = s->top;
		int data = temp->data;
		s->top = s->top->link;
		free(temp);
		return data;
	}
}

// �� �Լ�
int main(void)
{
	LinkedStackType s;
	init(&s);

	//top -> 1
	push(&s, 1); print_stack(&s);
	//top -> 2 1
	push(&s, 2); print_stack(&s);
	//top -> 3 2 1 
	push(&s, 3); print_stack(&s);

	pop(&s); print_stack(&s);
	//top -> 2 1
	pop(&s); print_stack(&s);
	//top -> 1
	pop(&s); print_stack(&s);
	return 0;
}
