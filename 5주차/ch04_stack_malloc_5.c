#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
//가장 현실적이고 세련된 방법
typedef int element;
typedef struct {
	element *data;		// data은 포인터로 정의된다. 
	int capacity;		// 현재 크기
	int top;
} StackType;

// 스택 생성 함수
void init_stack(StackType *s) //가장 핵심적인 부분 
{
	s->top = -1;
	s->capacity = 1; //capacity를 통해 초기 사이를 잡아둠.. 여기선 극단적으로 1
	s->data = (element *)malloc(s->capacity * sizeof(element)); //sizeof element == 4; data == 4;
	//1개의 요소를 저장할 수 있는 공간을 일단 확보
} 

// 공백 상태 검출 함수
int is_empty(StackType *s)
{
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType *s)
{
	return (s->top == (s->capacity - 1));
}
void push(StackType *s, element item)
{
	if (is_full(s)) { //어느 순간에 full이 되서 realloc이 되느냐가 중요함
		printf(">full 용량늘림( %d)\n",s->capacity);
		s->capacity *= 2;
		s->data =
			(element *)realloc(s->data, s->capacity * sizeof(element));
		//공간이 부족하면 메모리를 2배로 더 확보한다. capacity에 두배 하잖아. 
		//return 값을 항상 확인해라 -> 운영체제가 system call을 확인하기 때문 
		//-> heap이 부족하면 안해줄 수도 있음
	}
	else {
		printf("%>push : not full\n");
	}
	s->data[++(s->top)] = item;
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