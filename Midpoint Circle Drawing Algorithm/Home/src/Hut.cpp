#include <stdlib.h>
#include <graphics.h>
#include <dos.h>
#include <conio.h>
#include <iostream>
using namespace std; 

void CMP(int xcenter, int ycenter, int radius){
	int x = 0;
	int y = radius;
	int p = 1 - radius;
	void plotpoints(int, int , int, int);
	plotpoints(xcenter, ycenter, x, y);
	while(x<y){
		x++;
		if(p<0){
			p = p + 2*x + 1;
		}
		else{
			y--;
			p = p + 2*(x-y) + 1;
		}
		plotpoints(xcenter, ycenter, x, y);
	}
}

void plotpoints(int xcenter, int ycenter, int x, int y){
    putpixel(xcenter+x, ycenter+y, WHITE);
    putpixel(xcenter-x, ycenter+y, WHITE);
    putpixel(xcenter+x, ycenter-y, WHITE);
    putpixel(xcenter-x, ycenter-y, WHITE);
    putpixel(xcenter+y, ycenter+x, WHITE);
    putpixel(xcenter-y, ycenter+x, WHITE);
    putpixel(xcenter+y, ycenter-x, WHITE);
    putpixel(xcenter-y, ycenter-x, WHITE);
}

int main(){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

	int x, y, rad;
	cout << "Enter the x center coordinate, y center coordinate and radius";
	cin >> x >> y >> rad;
	CMP(x, y, rad);


	getch();
	return 0;
}