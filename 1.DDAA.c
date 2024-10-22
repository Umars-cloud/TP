// 1.Implement DDA Line Drawing algorithm

#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

int main()
{
    int gd = DETECT, gm;
    int x, y, x1, y1, x2, y2, xi, yi, k, dx, dy, s;

    printf("Enter the first point(x co-ordinate): ");
    scanf("%d", &x1);

    printf("Enter the first point(y co-ordinate):");
    scanf("%d", &y1);

    printf("Enter the second point(x co-ordinate):");
    scanf("%d", &x2);

    printf("Enter the second point(y co-ordinate)");
    scanf("%d", &y2);

    initgraph(&gd, &gm, NULL);

    x = x1;
    y = y1;
    putpixel(x, y, GREEN);
    dx = x2 - x1;
    dy = y2 - y1;
    if (abs(dx) > abs(dy))
    {
        s = abs(dx);
    }

    else
    {
        s = abs(dy);
    }

    xi = dx / s;
    yi = dy / s;

    for (k = 0; k < s; k++)
    {
        x += xi;
        y += yi;

        putpixel(x, y, GREEN);
    }
    delay(50000);
    closegraph();
    return 0;
}
