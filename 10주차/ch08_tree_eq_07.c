#include <stdio.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

//	             +
//	      *		        +
//     1    4 	     16    25
TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, NULL, NULL };
TreeNode n3 = { '*', &n1, &n2 };
TreeNode n4 = { 16, NULL, NULL };
TreeNode n5 = { 25, NULL, NULL };
TreeNode n6 = { '+', &n4, &n5 };
TreeNode n7 = { '+', &n3, &n6 };
TreeNode* exp = &n7;

// ���� ��� �Լ�
int evaluate(TreeNode* root)
{
	if (root == NULL) { //���� ���� Ʈ���� ��������̸� 
		return 0; //�׳� �����Ѵ�. 
	}

	if (root->left == NULL && root->right == NULL) { //�ܸ�����ΰ��
		return root->data; //�ǿ����ڸ� �����Ѵ�. 
	}else {
		//��ܸ� ����ϰ�� ���� ����Ʈ���� ����ϱ� ���Ͽ� evaluate�� �ٽ� ��ȯ ȣ���Ѵ�. 
		//�̶� �Ű������� ���� �ڽ� ��尡 �ȴ�. 
		int op1 = evaluate(root->left); 
		//�Ȱ��� ������ ������ ����Ʈ���� ����Ѵ�. 
		int op2 = evaluate(root->right);
		printf("�߰� %d %c %d�� ����մϴ�.\n", op1, root->data, op2);
		switch (root->data) {
			case '+':	return op1 + op2;
			case '-':	return op1 - op2;
			case '*':	return op1 * op2;
			case '/':	return op1 / op2;
		}
	}
	
	return 0;
}
// 
int main(void)
{
	printf("���� ������ ��� ��� �� : %d \n", evaluate(exp));
	return 0;
}



