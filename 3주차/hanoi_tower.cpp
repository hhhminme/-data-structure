#include <stdio.h>
void hanoi_tower(int n, char from, char tmp, char to) 
{
    if (n == 1) {
        printf("원판 1 : %c ---> %c\n", from, to);
    }
    else {
        hanoi_tower(n - 1, from, to, tmp); //from에 있는 원판 맨 밑에 있는 걸 제외하고 temp로 
        printf("원판 %d : %c ---> %c\n", n, from, to); //from에 있는 1개의 원반 temp로
        hanoi_tower(n - 1, tmp, from, to); //temp에 있는 원반 to로
    }
}
int main(void)
{
    hanoi_tower(4, 'A', 'B', 'C');
    return 0;
}
