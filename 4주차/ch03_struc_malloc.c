#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studentTag {
	char 	name[10]; 	// ���ڹ迭�� �� �̸�
	int 	age;	 	// ���̸� ��Ÿ���� ������
	double 	gpa;	 	// ��������� ��Ÿ���� �Ǽ���
} student;

int main(void)
{
	student* p;
	//student p��� �ϸ� static �ϰ� p��� ����ü ����
	//student* p�� 4byte������ �� �ִ� �ּ� ���� 
	p = (student*)malloc(sizeof(student)); //student�� ũ�⸸ŭ �޸� �Ҵ�. *p�� �ּҿ� heap���κ��� ������ 300�� �ּҸ� ����
	if (p == NULL) {
		fprintf(stderr, "�޸𸮰� �����ؼ� �Ҵ��� �� �����ϴ�.\n");
		//fprintf�� file ������� strerr�� Ư�� ������ �ڵ��� �־ ������ ����ϴ°���. strerr�� ���� �������� ���� ������. ������ ������ output�� �����
		exit(1); //return ���� 0�̸� ��������, 1�� �־������μ� ������ ���� �������� �˷���
	}
	strcpy(p->name, "Park"); 
	//����ü��� p.name �����ʹϱ� p->name
	//�� strcpy�� ����ؾ��Ѵ�. p->name = "Park" ��� ���ָ� �ȵȴ�. 
	p->age = 20;
	p->gpa = 4.3;

	// p�� ����Ű�� ������ ����ϴ� �ڵ带 �ϼ��Ͻÿ�.
	printf("name : %s \nage : %d \ngpa : %lf\n", p->name, p->age, p->gpa);

	free(p);
	return 0;
}
