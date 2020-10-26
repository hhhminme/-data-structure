# include <stdio.h>
# include <stdlib.h>
#define MAX_QUEUE_SIZE 50

typedef struct { // ��� Ÿ��
	int id; 
	int arrival_time;
	int service_time;
} element;			// ��ü!

// ================ ����ť �ڵ� ���� =================
typedef struct { // ť Ÿ��
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;
// ���� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
// ���� ���� ���� �Լ�
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}
// ���� ���� ���� �Լ�
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}
// ��ȭ ���� ���� �Լ�
int is_full(QueueType* q)
{
	return((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
// ����ť ��� �Լ�
void queue_print(QueueType* q)
{
	printf("queue(front : %d rear : %d)\n", q->front, q->rear);
}
// ���� �Լ�
void enqueue(QueueType* q, element item)
{
	if (is_full(&q)) {
		error("stack is empty");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
// ���� �Լ�
element dequeue(QueueType* q)
{
	if (is_full(q)) error("stack is full");
	q->front = ((q->front + 1) % MAX_QUEUE_SIZE);
	return q->data[q->front];
}
// ================ ����ť �ڵ� ���� =================
//
int main(void)
{
	int minutes = 60; //��
	int total_wait = 0;
	int total_customers = 0;
	int service_time = 0;
	int service_customer;
	int service_person_count = 0;
	QueueType queue;
	init_queue(&queue);

	srand(time(NULL));
	for (int clock = 0; clock < minutes; clock++) {
		printf("> ����ð� = %d \n", clock);
		if ((rand() % 10) < 3) {
			//���񽺸� ���� ����� �����Ͽ� ť �߰��ϱ�
			element customer;
			customer.id = total_customers++; 
			customer.arrival_time = clock; 
			customer.service_time = rand() % 3 + 1;
			enqueue(&queue, customer);
			printf("�� %d�� %d�ʿ� ���ɴϴ�. ����ó���ð� = %d\n",
				customer.id, customer.arrival_time, customer.service_time);
		}
		if (service_time > 0) {
			//���� ���� ���� Ȯ��
			printf("�� %d�� ���񽺸� �ް� �ֽ��ϴ�. \n",
				service_customer);
			service_time--;
		}
		else {
			//���� ���񽺸� �ް� ���� �ʴ� ��� 
			if (!is_empty(&queue)) {
				//ť���� ���� ��� �̾Ƴ���
				element customer = dequeue(&queue);
				service_customer = customer.id;
				service_time = customer.service_time;
				printf("> �� %d�� %d�ʿ� ���񽺸� �ޱ� �����մϴ�.."
					"���ð��� %d�� �̿��ϴ�. \n",
					customer.id, clock,
					clock - customer.arrival_time);
				//ť������ ���ð��� ����ϱ� (�м� ������ ����)
				total_wait += clock - customer.arrival_time; 
				service_person_count++;
			}
		}
	}
	printf("--��ü ���ð� = %d \n", total_wait);
	printf("--1�δ� ���ð� ��� = %f sec", (float)total_wait / service_person_count);
	return 0;
}

