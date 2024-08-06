#include <graphics.h>
#include <dos.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <iostream>

using namespace std;

void Bresenham(int xa, int ya, int xb, int yb)
{
	int dx = abs(xa - xb), dy = abs(ya - yb);
	int p = 2*dy - dx;
	int twoDy = 2*dy, twoDyDx = 2*(dy - dx);
	int x, y, xEnd;
	/*Determine which points to start and End */
	if(xa>xb){
	   x = xb;
	   y = yb;
	   xEnd = xa;
	}
	else{
	  x = xa; y = ya ; xEnd =  xb;
	}
	putpixel(x, y, WHITE);
	while(x < xEnd){
	   x++;
	   if(p<0){
	     p = p + twoDy;
	   }
	   else{
	     y++;
	     p = p + twoDyDx;
	   }
	   putpixel(x,y,WHITE);
	}

}

int main()
{
    int x0, y0, x1, y1;
    int gd=DETECT, gm, err;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    err = graphresult();
    if(err!=grOk){
	       printf(" error: %s\n", grapherrormsg(err));
    }
    // Entering the coordinates of all 2 points
    cout << "Enter the coordinates of the 1st point: ";
    cin >> x0 >> y0;
    cout << "Enter the coordinates of the 2dn point: ";
    cin >> x1 >> y1;
    Bresenham(x0, y0, x1, y1);
    getch();
    return 0;
}