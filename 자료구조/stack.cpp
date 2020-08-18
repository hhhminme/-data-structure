#include <stdio.h>
#define MAX_STACK_SIZE 100

int stack[MAX_STACK_SIZE];
int top = -1; 

int isEmpty() {
	if (top < 0) {
		return true;
	}
	else
		return false;
}
int isFull() {
	if (top >= MAX_STACK_SIZE - 1) {
		return true; 
	}
	else {
		return false; 
	}
}
void push(int value) {
	if (isFull() == true) {
		printf("스택이 가득찼습니다.\n");
	}
	else {
		stack[++top] = value;
	}
}
int pop() {
	if (isEmpty() == true) {
		printf("스택이 비였습니다.\n");
	}
	else {
		return stack[top--];
	}
}

int main(void) {
	push(3);
	push(5);
	push(12);
	printf("%d ", pop());
	printf("%d ", pop());
	printf("%d ", pop());
	
	return 0; 
}

//top = -1
//
//stack[0] = 3; top = 0;
//stack[1] = 5; top = 1;
//stack[2] = 12; top = 2;
//
//stack[2], top = 2;
//top = 1;
//
//stack[1], top = 1;
//top = 0;
//
//stack[0], top = 0;
//top = -1;
//
//top is empty