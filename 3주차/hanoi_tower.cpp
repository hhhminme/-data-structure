#include <stdio.h>
void hanoi_tower(int n, char from, char tmp, char to) 
{
    if (n == 1) {
        printf("���� 1 : %c ---> %c\n", from, to);
    }
    else {
        hanoi_tower(n - 1, from, to, tmp); //from�� �ִ� ���� �� �ؿ� �ִ� �� �����ϰ� temp�� 
        printf("���� %d : %c ---> %c\n", n, from, to); //from�� �ִ� 1���� ���� temp��
        hanoi_tower(n - 1, tmp, from, to); //temp�� �ִ� ���� to��
    }
}
int main(void)
{
    hanoi_tower(4, 'A', 'B', 'C');
    return 0;
}
