#include <stdio.h>
#define HEAPSIZE 9

int heap[HEAPSIZE] = { 1,5,3,6,2,6,6,4,9 };

//힙 구조 만들기 

int main(void) {
	for (int i = 1; i < HEAPSIZE; i++) {
		int c = i; 
		do {
			int root = (c - 1) / 2;
			if (heap[root] < heap[c]) {
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			} c = root; 
		} while (c != 0);
	}
	//크기를 줄여가며 힙 정렬
	for (int i = HEAPSIZE - 1; i >= 0; i--) {
		int temp = heap[0]; 
		heap[0] = heap[i]; 
		heap[i] = temp; 
		int root = 0; 
		int c = 1; 
		//자식 중에 큰 값이 있는지 확인 
		do {
			c = 2 * root + 1; 
			if (c < i - 1 && heap[c] < heap[c + 1]) {
				c++;
			}
		//root 값이 더 크다면 교체 
			if (c < i && heap[root] < heap[c]) {
				temp = heap[c];
				heap[c] = heap[root];
				heap[root] = temp; 
			}
			root = c; 
		} while (c < i);
	}
	for (int i = 0; i < HEAPSIZE; i++) {
		printf("%d ", heap[i]);
	}
	return 0;
}