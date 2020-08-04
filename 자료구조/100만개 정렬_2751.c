#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int number, data[1000000];

void quickSort(int* data, int start, int end) {
    if (start >= end) { // 원소가 1개인 경우 그대로 두기 
        return;
    }

    int key = start; // 키는 첫 번째 원소
    int i = start + 1, j = end, temp;

    while (i <= j) { // 엇갈릴 때까지 반복
        while (data[i] <= data[key]) { // 키 값보다 큰 값을 만날 때까지 
            i++;
        }
        while (data[j] >= data[key] && j > start) { // 키 값보다 작은 값을 만날 때까지 
            j--;
        }
        if (i > j) { // 현재 엇갈린 상태면 키 값과 교체 
            temp = data[j];
            data[j] = data[key];
            data[key] = temp;
        }
        else { // 엇갈리지 않았다면 i와 j를 교체 
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }

    quickSort(data, start, j - 1);
    quickSort(data, j + 1, end);
}

int main(void) {
    scanf("%d", &number);
    for (int i = 0; i < number; i++) {
        scanf("%d", &data[i]);
    }
    quickSort(data, 0, number - 1);
    for (int i = 0; i < number; i++) {
        printf("%d\n", data[i]);
    }
    return 0;
}
