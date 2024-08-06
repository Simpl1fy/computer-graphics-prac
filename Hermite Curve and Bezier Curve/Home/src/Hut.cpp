#include<graphics.h>
#include <conio.h>
#include<math.h>
#include<stdio.h>
void drawHermiteCurve(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3) {
    float t;
    for (t = 0; t <= 1; t += 0.01) {
        float x = (2 * pow(t, 3) - 3 * pow(t, 2) + 1) * x0 +
                  (pow(t, 3) - 2 * pow(t, 2) + t) * x1 +
                  (-2 * pow(t, 3) + 3 * pow(t, 2)) * x2 +
                  (pow(t, 3) - pow(t, 2)) * x3;
        float y = (2 * pow(t, 3) - 3 * pow(t, 2) + 1) * y0 +
                  (pow(t, 3) - 2 * pow(t, 2) + t) * y1 +
                  (-2 * pow(t, 3) + 3 * pow(t, 2)) * y2 +
                  (pow(t, 3) - pow(t, 2)) * y3;
        putpixel(round(x), round(y), WHITE);
    }
}

void bezierPoint(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3, float t) {
    float x = (1 - t) * (1 - t) * (1 - t) * x0 + 3 * (1 - t) * (1 - t) * t * x1 + 3 * (1 - t) * t * t * x2 + t * t * t * x3;
    float y = (1 - t) * (1 - t) * (1 - t) * y0 + 3 * (1 - t) * (1 - t) * t * y1 + 3 * (1 - t) * t * t * y2 + t * t * t * y3;
    putpixel((int)x, (int)y, WHITE);
}

void drawBezier(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3) {
    for (float t = 0; t <= 1; t += 0.01) {
        bezierPoint(x0, y0, x1, y1, x2, y2, x3, y3, t);
    }
}


main(){
	initwindow(600,600);
    int x0 = 100, y0 = 100;
    int x1 = 150, y1 = 50;
    int x2 = 250, y2 = 150;
    int x3 = 300, y3 = 200;
    drawHermiteCurve(x0, y0, x1, y1, x2, y2, x3, y3);
    getch();
	cleardevice();


	drawBezier(x0, y0, x1, y1, x2, y2, x3, y3);
	getch();

	return 0;
}