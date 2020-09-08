#include <stdio.h>
#define MAX 100	

int front = -1; 
int rear = -1; 

int queue[MAX]; 

int isEmpty(void) {
	if (front == rear)
		//front�� rear�� ������ ����ִ� ���� 
		return true;
	else return false; 
}
int isFull(void) {
	int temp = (rear + 1) % MAX; 
	//���� ť���� rear + 1�� MAX �� ���� ������ ���� 
	if (temp == front)
		//front �� ������ ť�� ������ ���� 
		return true;
	else
		return false;
}
void addQ(int val) {
	if (isFull()) {
		printf("Queue is full\n");
	}
	else {
		rear = (rear + 1) % MAX;
		queue[rear] = val;
	}
}
int deleteQ() {
	if (isEmpty() == true) {
		printf("queue is empty\n");
	}
	else {
		front = (front + 1) % MAX; 
		return queue[front]; 
	}
}
int main(void) {
	int i = 0; 
	while (isFull() != true) {
		addQ(i); 
		i++;
	}
	while (isEmpty() != true) {
		printf("%d\n", deleteQ());
	}
	return 0;
}