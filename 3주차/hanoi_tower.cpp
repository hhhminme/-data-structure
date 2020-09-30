#include <stdio.h>
void hanoi_tower(int n, char from, char tmp, char to) 
{
    if (n == 1) {
        printf("원판 1 : %c ---> %c\n", from, to);
    }
    else {
        hanoi_tower(n - 1, from, to, tmp);
        printf("원판 %d : %c ---> %c\n", n, from, to);
        hanoi_tower(n - 1, tmp, from, to);
    }
}
int main(void)
{
    hanoi_tower(3, 'A', 'B', 'C');
    return 0;
}
