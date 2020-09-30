#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studentTag {
	char 	name[10]; 	// 문자배열로 된 이름
	int 	age;	 	// 나이를 나타내는 정수값
	double 	gpa;	 	// 평균평점을 나타내는 실수값
} student;

int main(void)
{
	student* p;
	p = (student*)malloc(sizeof(student));
	if (p == NULL) {
		fprintf(stderr, "메모리가 부족해서 할당할 수 없습니다.\n");
		exit(1);
	}
	strcpy(p->name, "Park");
	p->age = 20;
	p->gpa = 4.3;

	// p가 가리키는 내용을 출력하는 코드를 완성하시오.
	

	free(p);
	return 0;
}
