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
		for (; root; root = root->left) { //�ަU ��� �������� leaf
			push(root); //��� Ǫ�� ���ÿ� �׾Ƶ� 
		}
		root = pop(); //�߰� ��忡�� �˵ȴ�. 
		if (!root) {
			break;
		}
		printf("[%d] ", root->data); //inorder.. 
		root = root->right; //���������� �� �� ������ ����.
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
	printf("���� ��ȸ=");
	inorder_iter(root);
	printf("\n");
	return 0;
}


