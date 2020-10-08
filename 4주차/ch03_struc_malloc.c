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
	//student p라고 하면 static 하게 p라는 구조체 선언
	//student* p는 4byte저장할 수 있는 주소 저장 
	p = (student*)malloc(sizeof(student)); //student의 크기만큼 메모리 할당. *p의 주소에 heap으로부터 가져온 300번 주소를 저장
	if (p == NULL) {
		fprintf(stderr, "메모리가 부족해서 할당할 수 없습니다.\n");
		//fprintf은 file 입출력임 strerr에 특정 파일의 핸들을 넣어서 오류를 출력하는것임. strerr를 통해 오른쪽의 말이 나간다. 현재의 설정은 output이 모니터
		exit(1); //return 값이 0이면 정상종료, 1을 넣어줌으로서 에러를 통한 종료임을 알려줌
	}
	strcpy(p->name, "Park"); 
	//구조체라면 p.name 포인터니깐 p->name
	//꼭 strcpy를 사용해야한다. p->name = "Park" 라고 해주면 안된다. 
	p->age = 20;
	p->gpa = 4.3;

	// p가 가리키는 내용을 출력하는 코드를 완성하시오.
	printf("name : %s \nage : %d \ngpa : %lf\n", p->name, p->age, p->gpa);

	free(p);
	return 0;
}
