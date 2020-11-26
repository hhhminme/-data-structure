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

// 수식 계산 함수
int evaluate(TreeNode* root)
{
	if (root == NULL) { //만약 수식 트리가 공백상태이면 
		return 0; //그냥 복귀한다. 
	}

	if (root->left == NULL && root->right == NULL) { //단말노드인경우
		return root->data; //피연산자를 리턴한다. 
	}else {
		//비단말 노드일경우 왼쪽 서브트리를 계산하기 위하여 evaluate를 다시 순환 호출한다. 
		//이때 매개변수는 왼쪽 자식 노드가 된다. 
		int op1 = evaluate(root->left); 
		//똑같은 식으로 오른쪽 서브트리를 계산한다. 
		int op2 = evaluate(root->right);
		printf("중간 %d %c %d을 계산합니다.\n", op1, root->data, op2);
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
	printf("최종 수식의 계산 결과 값 : %d \n", evaluate(exp));
	return 0;
}



