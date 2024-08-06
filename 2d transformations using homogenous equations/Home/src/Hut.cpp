#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <iostream>

using namespace std;

// Function to draw a rectangle
void drawRectangle(int x1, int y1, int x2, int y2) {
    rectangle(x1, y1, x2, y2);
}

// Function to apply translation on the rectangle
void translateRectangle(int &x1, int &y1, int &x2, int &y2, int tx, int ty) {
    x1 += tx;
    y1 += ty;
    x2 += tx;
    y2 += ty;
}

// Function to apply scaling on the rectangle
void scaleRectangle(int &x1, int &y1, int &x2, int &y2, float sx, float sy) {
    x1 = int(x1 * sx);
    y1 = int(y1 * sy);
    x2 = int(x2 * sx);
    y2 = int(y2 * sy);
}

// Function to apply rotation on the rectangle
void rotateRectangle(int &x1, int &y1, int &x2, int &y2, float angle) {
    float radian = angle * M_PI / 180;
    int xc = (x1 + x2) / 2;
    int yc = (y1 + y2) / 2;

    int tempX1 = x1 - xc;
    int tempY1 = y1 - yc;
    int tempX2 = x2 - xc;
    int tempY2 = y2 - yc;

    x1 = xc + int(tempX1 * cos(radian) - tempY1 * sin(radian));
    y1 = yc + int(tempX1 * sin(radian) + tempY1 * cos(radian));
    x2 = xc + int(tempX2 * cos(radian) - tempY2 * sin(radian));
    y2 = yc + int(tempX2 * sin(radian) + tempY2 * cos(radian));
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    int x1 = 100, y1 = 100, x2 = 200, y2 = 200;
    drawRectangle(x1, y1, x2, y2);

    getch();
    cleardevice();

    // Translate the rectangle
    int tx = 50, ty = 50;
    translateRectangle(x1, y1, x2, y2, tx, ty);
    drawRectangle(x1, y1, x2, y2);

    getch();
    cleardevice();

    // Scale the rectangle
    float sx = 1.5, sy = 1.5;
    scaleRectangle(x1, y1, x2, y2, sx, sy);
    drawRectangle(x1, y1, x2, y2);

    getch();
    cleardevice();

    // Rotate the rectangle
    float angle = 45;
    rotateRectangle(x1, y1, x2, y2, angle);
    drawRectangle(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}
