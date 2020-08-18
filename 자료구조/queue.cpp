#include <stdio.h>
#define MAX 100

int front = -1; 
int rear = -1; 

int queue[MAX];

int isEmpty(void) {
	if (front == rear)
	//fornt와 rear가 같으면 비어있는 상태 
		return true;
	else return false; 
}
int isFull(void) {
	int temp = (rear + 1) % MAX;
	//원형 큐에서 rear+1을 MAX로 나눈 나머지값이 
	if (temp == front)
		//front와 같으면 큐는 가득 차있는 상태 
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