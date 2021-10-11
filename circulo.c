
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
void main(){
	
  int gd=DETECT,gm;
  initgraph(&gd,&gm,"C:\\turboc3\\bgi");
  cleardevice();
  line(100,100,500,100);
  circle(200,200,50);
  getch();
  closegraph();
}