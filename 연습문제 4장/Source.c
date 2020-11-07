#include <stdio.h>
#include <stdlib.h>

typedef int element; 

typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	
	p->data = value; 
	p->link = head; 
	head = p; 
	return head; 
}
ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value; 
	p->link = pre->link; 
	pre->link = p; 
	return head; 
}
ListNode* delete_first(ListNode* head) {
	ListNode* removed; 
	if (head == NULL) return NULL;
	removed = head; 
	head = removed->link;
	free(removed);
	return head; 
}

ListNode* delete_pre(ListNode* head, ListNode* pre) {
	ListNode* removed; 
	removed = pre->link; 
	pre->link = removed->link;
	free(removed); 
	return head; 
}
void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%d -> ", p->data);
	}
		printf("NULL\n");
}

ListNode* search_list(ListNode* head, element vlaue) {
	ListNode* p = head; 
	if (p->data == NULL) return NULL; 
	while (p->link != NULL) {
		if (p->data = vlaue) return p; 
		p = p->link;
	}
	return NULL; //탐색실패
}
int main(void) {
	ListNode* head = NULL; //linked list를 가르키는 head pointer
	
	head = insert_first(head, 10);
	print_list(head);
	head = insert_first(head, 20);
	print_list(head);
	head = insert_first(head, 30);
	print_list(head);

	if (search_list(head, 20) != NULL) {
		printf("데이터 값 (%d) 발견\n", 20);
	}
	else {
		printf("데이터 값 (%d) 찾지못함\n", 20);
	}
	return 0; 
}
