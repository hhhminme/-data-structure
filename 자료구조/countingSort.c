//���������� �ִ� ��쿡 ���ؼ� ���� ���� 
//ũ�⸦ �������� ������ ���� ���? 
//��ġ �ٲ� �ʿ� ���� O(N)

#include <stdio.h>

int main(void) {
	int temp;
	int count[5];
	int array[30] = { 1,3,2,4,3,2,5,3,1,2,
					1,3,2,4,3,2,5,3,1,2,
					1,3,2,4,3,2,5,3,1,2 };
	//count 0���� �ʱ�ȭ 
	for (int i = 0; i < sizeof(count) / sizeof(int); i++) {
		count[i] = 0;
	}
	//count �� array index�ȿ� �ִ� ���� �°� �˸��� count index �� �־��� 
	for (int i = 0; i < sizeof(array) / sizeof(int); i++) {
		count[array[i] - 1]++;
	}
	//count[i]�� �ִ� ���� ������ ����Ѵ�. 
	for (int i = 0; i < sizeof(count) / sizeof(int); i++) {
		if (count[i] != 0) {
			for (int j = 0; j < count[i]; j++) {
				printf("%d ", i + 1);
			}
		}
	}




	return 0;
}