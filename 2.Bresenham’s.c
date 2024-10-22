// 2.Implement Bresenham’s Line algorithm

#include <stdio.h>
#include <graphics.h>

int main()
{
    int gd = DETECT, gm;
    int x, y, x1, y1, x2, y2, dx, dy, signx, signy, p, exchange;

    printf("Enter the first point(x co-ordinate): ");
    scanf("%d", &x1);

    printf("Enter the first point(y co-ordinate):");
    scanf("%d", &y1);

    printf("Enter the second point(x co-ordinate):");
    scanf("%d", &x2);

    printf("Enter the second point(y co-ordinate)");
    scanf("%d", &y2);

    initgraph(&gd, &gm, NULL);

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    x = x1;
    y = y1;

    putpixel(x, y, RED);
    signx = (x2 - x1) / (abs(x2 - x1));
    signy = (y2 - y1) / (abs(y2 - y1));

    if (dy > dx)
    {
        exchange = 1;
    }
    else
    {
        exchange = 0;
    }

    p = (2 * dy) - dx;

    while (x <= x2)
    {
        if (p < 0)
        {
            if (exchange == 1)
            {
                y += signy;
            }
            else
            {
                x += signx;
            }
            p += (2 * dy);
        }
        else
        {
            x += signx;
            y += signy;

            p += (2 * dy) - (2 * dx);
        }
        putpixel(x, y, RED);
    }

    delay(5000);
    closegraph();
    return 0;
}
