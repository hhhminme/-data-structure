#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

// ================ ����ť �ڵ� ���� =================
#define MAX_QUEUE_SIZE 100
typedef TreeNode* element;

// ť Ÿ��
typedef struct { 
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
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
// ���� �Լ�
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
// ���� �Լ�
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

void level_order(TreeNode* ptr)
{
	QueueType q;
	init_queue(&q);	 // ť �ʱ�ȭ
	if (ptr == NULL) {
		return;
	}
	enqueue(&q, ptr); //node�� queue�� �־��ش�. 
	while (!is_empty(&q)) {
		ptr = dequeue(&q); //queue�� �ִ� ��带 ������ 
		printf(" [%d] ", ptr->data); //�湮�Ѵ��� 
		if (ptr->left) { //�� node�� �ڽ� ��带 queue�� �������ش�. 
			enqueue(&q, ptr->left);
		}
		if (ptr->right) {
			enqueue(&q, ptr->right);
		}
	}
}

//		         15
//	        4		   20
//     1	        16     25
TreeNode n1 = { 1,  NULL, NULL };
TreeNode n2 = { 4,  &n1,  NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3,  &n4 };
TreeNode n6 = { 15, &n2,  &n5 };
TreeNode* root = &n6;

int main(void)
{
	printf("���� ��ȸ=");
	level_order(root);
	printf("\n");
	return 0;
}

