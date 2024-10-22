#include <graphics.h>
#include <conio.h>
#include <stdio.h>

void floodFill(int x, int y, int oldColor, int newColor) {
    if (getpixel(x, y) == oldColor) {
        putpixel(x, y, newColor);
        floodFill(x + 1, y, oldColor, newColor); // Right
        floodFill(x - 1, y, oldColor, newColor); // Left
        floodFill(x, y + 1, oldColor, newColor); // Down
        floodFill(x, y - 1, oldColor, newColor); // Up
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    rectangle(50, 50, 200, 200);
    int oldColor = WHITE;
    int newColor = RED;
    floodFill(51, 51, oldColor, newColor);

    getch();
    closegraph();
    return 0;
}
