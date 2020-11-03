#include <stdio.h>
//노드 구조체 정의 

struct NodeType {
	int data; 
	struct NodeType* link;
};
typedef struct NodeType Node;

void PrintList(Node* p) {
//head로부터 데이터를 찍고 link를 헤드로 넣어주고 데이터 찍고 null이 나오면 빠져 나올 수 있도록
	while (p != NULL) { //중요!
		printf(" -> %d",p->data);
		p = p->link; //중요!
	}
}

int main(void) {
	Node* head =NULL, * p1 = NULL , *p2= NULL, * p3 =NULL;

	p1 = (Node*)malloc(sizeof(Node));
	p1->data = 10; 
	p1->link = NULL;

	p2 = (Node*)malloc(sizeof(Node));
	p2->data = 20;
	p2->link = NULL;

	p3 = (Node*)malloc(sizeof(Node));
	p3->data = 30;
	p3->link = NULL;

	p1->link = p2;
	p2->link = p3;

	head = p1;
	PrintList(head);
	return 0;
}