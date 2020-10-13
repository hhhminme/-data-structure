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

// 공백 상태 검출 함수
int is_empty()
{
	return (top == -1);
}
// 포화 상태 검출 함수
int is_full()
{
	return (top == (MAX_STACK_SIZE - 1));
}
// 삽입 함수
void push(element item)
{
	if (is_full()) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else stack[++top] = item;
}
// 삭제 함수
element pop()
{
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return stack[top--];
}
// 피크함수
element peek()
{
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
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
	int cnt = top + 1; //왜냐하면 top = -1 을 가르키기 떄문이다. 
	for (int i = 0; i < cnt; i++) {
		oe = pop();
		printf("학번: %d\n", oe.student_no);
		printf("이름: %s\n", oe.name);
		printf("주소: %s\n", oe.address);
		putchar('\n');
	}

	return 0;
}