#include <stdio.h>
#include <algorithm>

int number, data[1000000];

int main(void) {
	scanf("%d", &number);
	for (int i = 0; i < number; i++) {
		scanf("%d", &data);
	}

	std::sort(data, data + number);
	for (int i = 0; i < number; i++) {
		printf("%d\n", data[i]);
	}
	return 0; 
}