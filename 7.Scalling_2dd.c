// 7.Implement 2D Transformations: Scaling 

#include <stdio.h>
#include <math.h>
#include <graphics.h>

int main() {
	int gd = DETECT, gm;
    int x1, y1, x2, y2, sx, sy, x3, y3, x4, y4;

    printf("Enter the starting point of line segment (x1, y1): ");
    scanf("%d%d", &x1, &y1);
    printf("Enter the ending point of the line segment (x2, y2): ");
    scanf("%d%d", &x2, &y2);
    printf("Enter the scaling distance (sx, xy): ");
    scanf("%d%d", &sx, &sy);

    initgraph(&gd, &gm, NULL);
    setcolor(5);
    line(x1, y1, x2, y2);

    x3 = x1 * sx;
    y3 = y1 * sy;
    x4 = x2 * sx;
    y4 = y2 * sy;

    setcolor(7);
    line(x3, y3, x4, y4);

    delay(15000);
    closegraph();
    return 0;
}
