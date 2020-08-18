#include <stdio.h>
#define MAX 100

int front = -1; 
int rear = -1; 

int queue[MAX];

int isEmpty(void) {
	if (front == rear)
	//fornt�� rear�� ������ ����ִ� ���� 
		return true;
	else return false; 
}
int isFull(void) {
	int temp = (rear + 1) % MAX;
	//���� ť���� rear+1�� MAX�� ���� ���������� 
	if (temp == front)
		//front�� ������ ť�� ���� ���ִ� ���� 
		return true;
	else
		return false;
}
void addQ(int value) {
	if (isFull()) {
		printf("Queue is full.\n");
	}
	else {
		rear = (rear + 1) % MAX; 
		queue[rear] = value; 
	}
}
int deleteQ() {
	if (isEmpty()) {
		printf("queqe is Empty.\n");
	}
	else {
		front = (front + 1) % MAX;
		return queue[front]; 
	}
}

int main() {
	addQ(4);
	addQ(12);
	addQ(24);
	printf("%d\n", deleteQ());
	printf("%d\n", deleteQ());
	printf("%d\n", deleteQ());
	deleteQ();

	return 0; 
}