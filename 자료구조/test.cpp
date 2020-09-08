#include <stdio.h>
#define MAX 100	

int front = -1; 
int rear = -1; 

int queue[MAX]; 

int isEmpty(void) {
	if (front == rear)
		//front와 rear가 같으면 비어있는 상태 
		return true;
	else return false; 
}
int isFull(void) {
	int temp = (rear + 1) % MAX; 
	//원형 큐에서 rear + 1을 MAX 로 나눈 나머지 값이 
	if (temp == front)
		//front 와 같으면 큐는 가득찬 상태 
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