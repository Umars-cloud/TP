// 6.Implement 2D Transformations: Translation

#include <stdio.h>
#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2, tx, ty, x3, y3, x4, y4;

    printf("Enter the starting point of line segment (x1 y1): ");
    scanf("%d %d", &x1, &y1);
  
    printf("Enter the ending point of line segment (x2 y2): ");
    scanf("%d %d", &x2, &y2);
 
    printf("Enter translation distance tx and ty:\n");
    scanf("%d %d", &tx, &ty);

    initgraph(&gd, &gm, "NULL");
    setcolor(5);
    line(x1, y1, x2, y2);

    x3 = x1 + tx;
    y3 = y1 + ty;
    x4 = x2 + tx;
    y4 = y2 + ty;
    
    setcolor(7);
    line(x3, y3, x4, y4);
    
    delay(50000);
    closegraph();

    return 0;
}
