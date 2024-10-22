// 9.Implement 3D Transformations: Translation

#include <stdio.h>
#include <math.h>
#include <graphics.h>

int main() {
    int gd = DETECT , gm;
    int a1, b1, a2, b2, dep, x, y;
    int x1, y1, x2, y2, depth;

    printf("3D Translation:-\n\n");
    printf("Enter 1st to value (x1, y1): ");
    scanf("%d%d", &x1, &y1);
    printf("Enter the bottom value (x2, y2): ");
    scanf("%d%d", &x2, &y2);
    printf("Enter the Translation Distances (x, y): ");
    scanf("%d%d", &x, &y);

    initgraph(&gd, &gm, NULL);
    depth = (x2 - x1) / 4;
    bar3d(x1, y1, x2, y2, depth, 1);
    
    a1 = x1 + x;
    a2 = x2 + x;
    b1 = y1 + y;
    b2 = y2 + y;
    
    dep = (a2-a1)/4;
    bar3d(a1, b1, a2, b2, dep, 1);
    delay(20000);
    closegraph();
    return 0;
}
