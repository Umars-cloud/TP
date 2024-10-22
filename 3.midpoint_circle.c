// 3.Implement midpoint Circle algorithm.

#include<stdio.h>
 #include<graphics.h>
#include<stdlib.h>
 
int main()
 
 {    
      int gd= DETECT, gm;  
     
      int x,y,r,xc,yc,p;
     
      printf("Enter the x co-ordinate:");
      scanf("%d",&xc);
     
      printf("Enter the y co-ordinate:");
      scanf("%d",&yc);
     
      printf("Enter the radius of the circle:");
      scanf("%d",&r);
         
      if(r<=xc && r<=yc)
      {
          p=1-r;
      x=0;
      y=r;
          initgraph(&gd,&gm,NULL);
 
      while(x<y){
          putpixel(xc+x, yc+y,WHITE);
          putpixel(xc-x, yc+y,WHITE);
          putpixel(xc+x, yc-y,WHITE);
          putpixel(xc-x, yc-y,WHITE);
          putpixel(xc+y, yc+x,WHITE);
          putpixel(xc-y, yc+x,WHITE);
          putpixel(xc+y, yc-x,WHITE);
          putpixel(xc-y, yc-x,WHITE);
          if(p<0)
            p=p+2*x+3;
          else{
              p=p+2*(x-y)+5;
              y=y-1;
              }
          x++;
          delay(150);
         }
         delay(10000);  
          closegraph();  
      }
      else{
            printf("The co-ordinates are invalid");
          }
    	 return 0;
      }  
