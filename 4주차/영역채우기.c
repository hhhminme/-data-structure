#include <stdio.h>

#define WHITE 0
#define BLACK 1 
#define YELLOW 2	
#define WIDTH 3	// x
#define HEIGHT 3// y

int screen[WIDTH][HEIGHT] = {
	{2,0,2},
	{2,0,0},
	{2,2,2} };

char read_pixel(int x, int y) {
	return screen[x][y];
}

void write_pixel(int x, int y, int color) {
	screen[x][y] = color; 
}
//영역 채우기 알고리즘 
void flood_fill(int x,int y){
	if (read_pixel(x, y) == WHITE) {
		write_pixel(x, y, BLACK);
		if (x > 0 && y > 0 && x < WIDTH && y < WIDTH) {
			flood_fill(x + 1, y);
			flood_fill(x, y + 1);
			flood_fill(x - 1, y);
			flood_fill(x, y - 1);
		}
	}
}
void print_screen(int x, int y) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			printf("%d ", screen[i][j]);
		}
		putchar('\n');
	}
}
int main(void) {
	print_screen(WIDTH, HEIGHT);
	flood_fill(1, 1);
	putchar('\n');
	print_screen(WIDTH, HEIGHT);

	return 0;
}

