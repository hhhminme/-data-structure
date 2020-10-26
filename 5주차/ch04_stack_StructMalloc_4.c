#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType *s)
{
	s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType *s)
{
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입함수
void push(StackType *s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// 삭제함수
element pop(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
// 피크함수
element peek(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}


int main(void)
{
	StackType *s; //포인터만 선언하고 //동적으로 공간 스택선언

	s = (StackType *)malloc(sizeof(StackType));
	//malloc을 통해 동적으로 메모리를 할당 
	//기존에 malloc안썼으면 &s 로 파라메터를 넘겨줌 
	//지금은 포인터로 선언해주었기 때문에 s로만 넘겨주면 된다. 
	//공간을 잡아주는 방식이 static이냐 dynamic이냐를 확인
	init_stack(s);
	//기존 스택에 대한 연산자들은 함수를 동일하게 사용 
	push(s, 1);
	push(s, 2);
	push(s, 3);
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));

	printf("%d\n", pop(s));
	free(s);
}
