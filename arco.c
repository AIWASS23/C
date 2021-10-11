
#include<conio.h>
#include<graphics.h>
void main(){
	
	int g=DETECT,gd;
	initgraph(&g,&gd,"c:\\turboc3\\bgi");
	outtextxy(23,23,"arc example");

	arc(300,350,0,90,100);
getch();
	closegraph();
}

