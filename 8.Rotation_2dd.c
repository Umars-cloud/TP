// 8.Implement 2D Transformations: Rotation

#include <stdio.h>
#include <math.h>
#include <graphics.h>

int main() {
	int gd = DETECT, gm;
    int x1, y1, x2, y2, x3, y3, x4, y4;
    float a, t;

    printf("Enter the starting point of line segment (x1, y1): ");
    scanf("%d%d", &x1, &y1);
    printf("Enter the ending point of the line segment (x2, y2): ");
    scanf("%d%d", &x2, &y2);
    printf("Enter the angle of rotation: ");
    scanf("%f", &a);

    initgraph(&gd, &gm, NULL);
    setcolor(5);
    line(x1, y1, x2, y2);
	t = a * (3.14 / 180);

	x3 = (x1*cos(t)) - (y1*sin(t));
	y3 = (x1*sin(t)) + (y1*cos(t));
	x4 = (x2*cos(t)) - (y2*sin(t));
	y4 = (x2*sin(t)) + (y2*cos(t));

    setcolor(7);
    line(x3, y3, x4, y4);

    delay(15000);
    closegraph();
    return 0;
}
