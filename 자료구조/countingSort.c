//범위조건이 있는 경우에 한해서 빠른 정렬 
//크기를 기준으로 갯수를 세면 어떨까? 
//위치 바꿀 필요 없음 O(N)

#include <stdio.h>

int main(void) {
	int temp;
	int count[5];
	int array[30] = { 1,3,2,4,3,2,5,3,1,2,
					1,3,2,4,3,2,5,3,1,2,
					1,3,2,4,3,2,5,3,1,2 };
	//count 0으로 초기화 
	for (int i = 0; i < sizeof(count) / sizeof(int); i++) {
		count[i] = 0;
	}
	//count 에 array index안에 있는 값에 맞게 알맞은 count index 에 넣어줌 
	for (int i = 0; i < sizeof(array) / sizeof(int); i++) {
		count[array[i] - 1]++;
	}
	//count[i]에 있는 값을 값만번 출력한다. 
	for (int i = 0; i < sizeof(count) / sizeof(int); i++) {
		if (count[i] != 0) {
			for (int j = 0; j < count[i]; j++) {
				printf("%d ", i + 1);
			}
		}
	}




	return 0;
}