#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct I {
	int item; 
	char string[21];
}I;

int main(void) {
	I* input; 
	input = (I*)malloc(sizeof(I));
	input->item = 100;
	strcpy(input->string, "just testing");

	printf("%d %s", input->item, input->string);
	free(input);
	return 0;
}