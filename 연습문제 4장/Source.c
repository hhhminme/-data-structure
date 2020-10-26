# include <stdio.h>
# include <stdlib.h>
#define MAX_QUEUE_SIZE 50

typedef struct { // 요소 타입
	int id; 
	int arrival_time;
	int service_time;
} element;			// 교체!

// ================ 원형큐 코드 시작 =================
typedef struct { // 큐 타입
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;
// 오류 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
// 공백 상태 검출 함수
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}
// 공백 상태 검출 함수
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}
// 포화 상태 검출 함수
int is_full(QueueType* q)
{
	return((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
// 원형큐 출력 함수
void queue_print(QueueType* q)
{
	printf("queue(front : %d rear : %d)\n", q->front, q->rear);
}
// 삽입 함수
void enqueue(QueueType* q, element item)
{
	if (is_full(&q)) {
		error("stack is empty");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}
// 삭제 함수
element dequeue(QueueType* q)
{
	if (is_full(q)) error("stack is full");
	q->front = ((q->front + 1) % MAX_QUEUE_SIZE);
	return q->data[q->front];
}
// ================ 원형큐 코드 종료 =================
//
int main(void)
{
	int minutes = 60; //초
	int total_wait = 0;
	int total_customers = 0;
	int service_time = 0;
	int service_customer;
	int service_person_count = 0;
	QueueType queue;
	init_queue(&queue);

	srand(time(NULL));
	for (int clock = 0; clock < minutes; clock++) {
		printf("> 현재시각 = %d \n", clock);
		if ((rand() % 10) < 3) {
			//서비스를 받을 사람을 생성하여 큐 추가하기
			element customer;
			customer.id = total_customers++; 
			customer.arrival_time = clock; 
			customer.service_time = rand() % 3 + 1;
			enqueue(&queue, customer);
			printf("고객 %d이 %d초에 들어옵니다. 업무처리시간 = %d\n",
				customer.id, customer.arrival_time, customer.service_time);
		}
		if (service_time > 0) {
			//서비스 중인 지를 확인
			printf("고객 %d가 서비스를 받고 있습니다. \n",
				service_customer);
			service_time--;
		}
		else {
			//현재 서비스를 받고 있지 않는 경우 
			if (!is_empty(&queue)) {
				//큐에서 받을 사람 뽑아내기
				element customer = dequeue(&queue);
				service_customer = customer.id;
				service_time = customer.service_time;
				printf("> 고객 %d가 %d초에 서비스를 받기 시작합니다.."
					"대기시간은 %d초 이였니다. \n",
					customer.id, clock,
					clock - customer.arrival_time);
				//큐에서의 대기시간을 계산하기 (분석 데이터 수집)
				total_wait += clock - customer.arrival_time; 
				service_person_count++;
			}
		}
	}
	printf("--전체 대기시간 = %d \n", total_wait);
	printf("--1인당 대기시간 평균 = %f sec", (float)total_wait / service_person_count);
	return 0;
}

