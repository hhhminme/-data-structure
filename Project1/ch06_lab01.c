#include <stdio.h>
//��� ����ü ���� 

struct NodeType {
	int data; 
	struct NodeType* link;
};
typedef struct NodeType Node;

void PrintList(Node* p) {
//head�κ��� �����͸� ��� link�� ���� �־��ְ� ������ ��� null�� ������ ���� ���� �� �ֵ���
	while (p != NULL) { //�߿�!
		printf(" -> %d",p->data);
		p = p->link; //�߿�!
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