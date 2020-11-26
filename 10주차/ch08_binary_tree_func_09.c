#include <stdio.h>
#define TRUE	1
#define FALSE	0

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

//		     G
//	     C		  F
//    A	   B   D     E
TreeNode n1 = { 'A',	NULL,	NULL };
TreeNode n2 = { 'B',	NULL,	NULL };
TreeNode n3 = { 'C',	&n1,	&n2 };
TreeNode n4 = { 'D',	NULL,	NULL };
TreeNode n5 = { 'E',	NULL,	NULL };
TreeNode n6 = { 'F',	&n4,	&n5 };
TreeNode n7 = { 'G',	&n3,	&n6 };
TreeNode* btree = &n7;

int max(int a, int b) {
	int result = a;
	if (a < b) {
		result = b;
	}
	return result;
}

int get_node_count(TreeNode *node)
{
	int count = 0;

	if (node != NULL) {
		count = 1 + get_node_count(node->left) + get_node_count(node->right);
	}

	return count;
}

int get_leaf_count(TreeNode *node)
{
	int count = 0;

	if (node != NULL) {
		if (node->left == NULL && node->right == NULL) {
			return 1;
		}else {
			count = get_leaf_count(node->left) + get_leaf_count(node->right);
		}
	}

	return count;
}

int get_height(TreeNode *node)
{
	int height = 0;

	if (node != NULL) {
		height = 1 + max(get_height(node->left), get_height(node->right));
	}

	return height;
}

int main(void)
{
	printf("- height	: %d\n", get_height(btree));
	printf("- leaf count	: %d\n", get_leaf_count(btree));
	printf("- node count	: %d\n", get_node_count(btree));
	
	return 0;
}