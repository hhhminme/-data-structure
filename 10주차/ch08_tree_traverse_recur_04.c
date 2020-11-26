#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int					data;
	struct TreeNode*	left, * right;
} TreeNode;

//		  15
//	   4     20
// 	1	   16  25

TreeNode n7 = { 22, NULL, NULL };
TreeNode n1 = { 5,  NULL, NULL };
TreeNode n4 = { 95, NULL, NULL };
TreeNode n2 = { 15, &n1,  NULL };
TreeNode n3 = { 35, &n7, NULL };
TreeNode n5 = { 93, &n3,  &n4 };
TreeNode n6 = { 17, &n2,  &n5 };
TreeNode* root = &n6;


// ���� ��ȸ
inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);		// ���ʼ���Ʈ�� ��ȸ
		printf("%d ", root->data); 	// ��� �湮
		inorder(root->right);		// �����ʼ���Ʈ�� ��ȸ
	}
}

// ���� ��ȸ
preorder(TreeNode* root) {
	if (root) {
		printf("%d ", root->data); 	// ��� �湮
		preorder(root->left);		// ���ʼ���Ʈ�� ��ȸ
		preorder(root->right);		// �����ʼ���Ʈ�� ��ȸ
	}
}

// ���� ��ȸ
postorder(TreeNode* root) {
	if (root) {
		postorder(root->left);		// ���� ���� Ʈ�� ��ȸ
		postorder(root->right);		// ������ ���� Ʈ�� ��ȸ
		printf("%d ", root->data); 	// ��� �湮
	}
}

//
int main(void)
{
	printf("���� ��ȸ=");
	inorder(root);
	printf("\n");

	printf("���� ��ȸ=");
	preorder(root);
	printf("\n");

	printf("���� ��ȸ=");
	postorder(root);
	printf("\n");
	return 0;
}
