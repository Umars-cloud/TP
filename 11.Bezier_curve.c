// 11.Implement Curve: Bezier curve

#include <stdio.h>
#include <math.h>
#include <graphics.h>

int main()

	int x[4], y[4];
	int i;
	double t;
	int gd = DETECT, gm;
	printf("Enter the X and Y Co ordinate of the four control points: ");
	for (i = 0; i < 4; i++)
	{
    	scanf("%d %d", &x[i], &y[i]);
	}
	initgraph(&gd, &gm, NULL);
	for (i = 0; i < 4; i++)
	{
    	putpixel(x[i], y[i], YELLOW);
	}
	for (t = 0.0; t < 1.0; t += 0.0005)
	{
    	double xt = pow(1 - t, 3) * x[0] + 3 * t * pow(1 - t, 2) * x[1] + 3 * pow(t, 2) * (1 - t) * x[2] + pow(t, 3) * x[3];
    	double yt = pow(1 - t, 3) * y[0] + 3 * t * pow(1 - t, 2) * y[1] + 3 * pow(t, 2) * (1 - t) * y[2] + pow(t, 3) * y[3];
    	putpixel((int)xt, (int)yt, WHITE);
	}
	delay(15000);
	closegraph();
	return 0;
}

