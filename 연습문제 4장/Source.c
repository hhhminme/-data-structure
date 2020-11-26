#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct {
	element data; 
	QueueNode* link;
}QueueNode;

typedef struct {
	QueueNode* front;
	QueueNode* rear;
}LinkedQueueType;

void init(LinkedQueueType* q) {
	q->front = 0;
	q->rear = 0;
}

int is_empty(LinkedQueueType* q) {
	return(q->front == NULL);
}

int is_full(LinkedQueueType* q) {
	return 0;
}

void enqueue(LinkedQueueType* q, element data) {
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = data; 
	temp->link = NULL;

	if (is_empty(q)) {
		fprintf(stderr, "queue가 비여있습니다.");
		exit(1);
	}
	q->rear->link = temp; 
	q->rear = temp; 
}

element dequeue(LinkedQueueType* q) {
	QueueNode* temp = q->front;
	element data; 
	if (is_empty(q)) {
		fprintf(stderr, "queue가 비여있습니다.");
		exit; 
	}
	else {
		data = temp->data;
		q->front = q->front->link;
		if(q->front == NULL) {
			q->rear = NULL;
		}
		free(temp);
		return data; 
	}
}
void print_queue(LinkedQueueType* q) {
	QueueNode* temp;
	for (temp = q->front; temp != NULL; temp = temp->link) {
		printf("%d->", temp->data);
	}
	printf("NULL\n");
}

int main(void) {
	LinkedQueueType* Queue;

	init(&Queue);

	enqueue(&Queue, 10); print_queue(&Queue);
	enqueue(&Queue, 20); print_queue(&Queue);
	enqueue(&Queue, 30); print_queue(&Queue);

	dequeue(&Queue); print_queue(&Queue);
	dequeue(&Queue); print_queue(&Queue);
	dequeue(&Queue); print_queue(&Queue);

	return 0;
}