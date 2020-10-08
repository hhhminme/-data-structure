#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct { // ť Ÿ��
	int			front;
	int			rear;
	element		data[MAX_QUEUE_SIZE];
} QueueType;

void init_queue(QueueType* q);
void queue_print(QueueType* q);
int is_full(QueueType* q);
int is_empty(QueueType* q);
void enqueue(QueueType* q, int item);
int dequeue(QueueType* q);
void error(char* message);

int main(void)
{
	int item = 0;
	QueueType q;
	init_queue(&q);
	enqueue(&q, 10);		queue_print(&q);
	enqueue(&q, 20);		queue_print(&q);
	enqueue(&q, 30);		queue_print(&q);
	item = dequeue(&q);		queue_print(&q);
	item = dequeue(&q);		queue_print(&q);
	item = dequeue(&q);		queue_print(&q);
	return 0;
}

// ���� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
// ť �ʱ�ȭ �Լ�
void init_queue(QueueType* q)
{
	q->rear = -1;
	q->front = -1;
}
// ť ���� ��� �Լ�
void queue_print(QueueType* q)
{
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		if (i <= q->front || i > q->rear)
			printf("   | ");
		else
			printf("%d | ", q->data[i]);
	}
	printf("\n");
}
// ť full Ȯ�� �Լ�
int is_full(QueueType* q)
{
	if (q->rear == MAX_QUEUE_SIZE - 1)
		return 1;
	else
		return 0;
}
// ť empty Ȯ�� �Լ�
int is_empty(QueueType* q)
{
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}
// ť�� ��� �߰�
void enqueue(QueueType* q, int item)
{
	if (is_full(q)) {
		error("ť�� ��ȭ�����Դϴ�.");
		return;
	}
	q->data[++(q->rear)] = item;
}
// ť���� ��� ����
int dequeue(QueueType* q)
{
	if (is_empty(q)) {
		error("ť�� ��������Դϴ�.");
		return -1;
	}
	int item = q->data[++(q->front)];
	return item;
}




