// 5.Implement Area Filling Algorithm using Boundary Fill

#include <stdio.h>
#include <graphics.h>

void boundary_fill(int x, int y, int fcolor, int bcolor) {
	if (getpixel(x, y) != bcolor && getpixel(x, y) != fcolor) {
    	putpixel(x, y, fcolor);
    	delay(10);
    	if (x + 1 < getmaxx()) boundary_fill(x + 1, y, fcolor, bcolor);
    	if (y + 1 < getmaxy()) boundary_fill(x, y + 1, fcolor, bcolor);
    	if (y - 1 >= 0) boundary_fill(x, y - 1, fcolor, bcolor);
    	if (x - 1 >= 0) boundary_fill(x - 1, y, fcolor, bcolor);
	}
}

int main() {
	int x, y, fcolor, bcolor;
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "null");
	rectangle(100, 100, 250, 300);
	boundary_fill(115, 110, 12, 15);
	delay(50000);
	closegraph();
	return 0;
}
