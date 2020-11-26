#include <stdio.h>
#include <stdlib.h>

typedef int element;	// 요소의 타입
typedef struct QueueNode {	// 큐의 노드의 타입 
	element data;
	struct QueueNode* link;
} QueueNode;

typedef struct {		// 큐 ADT 구현
	QueueNode* front, * rear;
} LinkedQueueType;

void init(LinkedQueueType* q)
{
	q->front = q->rear = 0;
}

int is_empty(LinkedQueueType* q)
{
	return (q->front == NULL);
}

int is_full(LinkedQueueType * q)
{
	return 0;
}

void print_queue(LinkedQueueType* q)
{
	QueueNode* p;
	for (p = q->front; p != NULL; p=p->link) {
		printf("%d ->",p->data);
	}
	printf("NULL\n");
}

// 삽입 함수
void enqueue(LinkedQueueType* q, element data)
{
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = data; 		// 데이터 저장
	temp->link = NULL; 		// 링크 필드를 NULL
	if (is_empty(q)) { 		// 큐가 공백이면
		q->front = temp;
		q->rear = temp;
	}
	else { 		// 큐가 공백이 아니면
		q->rear->link = temp;  // 연결 생성 부분 
		q->rear = temp;			//마지막(rear) 갱신 
	}
}

// 삭제 함수 front 에서 뽑아냄
element dequeue(LinkedQueueType* q)
{
	QueueNode* temp = q->front; //front 값을 카피 
	element data;
	if (is_empty(q)) {		// 공백상태
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		data = temp->data; 	// 데이터를 꺼낸다.
		q->front = q->front->link; // front로 다음노드
		if (q->front == NULL) 	// 공백 상태
			q->rear = NULL;
		free(temp); 		// 동적메모리 해제
		return data; 		// 데이터 반환
	}
}

int main(void)
{
	LinkedQueueType queue; //포인터변수 내부에는 front, rear pointer 정의되어있다. 

	init(&queue);

	// 1 2 3
	enqueue(&queue, 1);		print_queue(&queue);
	enqueue(&queue, 2);		print_queue(&queue);
	enqueue(&queue, 3);		print_queue(&queue);
	//2 3 
	dequeue(&queue);		print_queue(&queue);
	//3
	dequeue(&queue);		print_queue(&queue);
	//전부 삭제
	dequeue(&queue);		print_queue(&queue);

	return 0;
}