#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define SIZE 100

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

TreeNode* stack[SIZE];
int top = -1;

void push(TreeNode* p)
{
	if (top < SIZE - 1)
		stack[++top] = p;
}

TreeNode* pop()
{
	TreeNode* p = NULL;
	if (top >= 0)
		p = stack[top--];
	return p;
}

void inorder_iter(TreeNode* root)
{
	while (1) {
		for (; root; root = root->left) { //왼쪾 노드 방향으로 leaf
			push(root); //계속 푸쉬 스택에 쌓아둠 
		}
		root = pop(); //중간 노드에서 팝된다. 
		if (!root) {
			break;
		}
		printf("[%d] ", root->data); //inorder.. 
		root = root->right; //오른쪽으로 갈 수 있으면 간다.
	}
}

//		       15
//	       4		 20
//     1	     16     25
TreeNode n7 = { 22, NULL, NULL};
TreeNode n1 = { 5,  NULL, NULL };
TreeNode n4 = { 95, NULL, NULL };
TreeNode n2 = { 15, &n1,  NULL };
TreeNode n3 = { 35, &n7, NULL };
TreeNode n5 = { 93, &n3,  &n4 };
TreeNode n6 = { 17, &n2,  &n5 };
TreeNode* root = &n6;

int main(void)
{
	printf("중위 순회=");
	inorder_iter(root);
	printf("\n");
	return 0;
}


