#include <graphics.h>
#include<conio.h>

const int xMin = 100;
const int yMin = 100;
const int xMax = 400;
const int yMax = 400;

// Function to compute the region code for a point
int computeRegionCode(int x, int y) {
    int code = 0;
    if (x < xMin) code |= 1; // Left
    if (x > xMax) code |= 2; // Right
    if (y < yMin) code |= 4; // Bottom
    if (y > yMax) code |= 8; // Top
    return code;
}
// Function to clip a line using Cohen-Sutherland algorithm
void clipLine(int x1, int y1, int x2, int y2) {
    int code1 = computeRegionCode(x1, y1);
    int code2 = computeRegionCode(x2, y2);

    while (true) {
        if (!(code1 || code2)) { // Both points inside the clipping window
            line(x1, y1, x2, y2);
            break;
        } else if (code1 & code2) { // Both points outside the clipping window
            break;
        } else {
            int code = code1 ? code1 : code2;
            int x, y;
            if (code & 1) { // Left
                x = xMin;
                y = y1 + (y2 - y1) * (xMin - x1) / (x2 - x1);
            } else if (code & 2) { // Right
                x = xMax;
                y = y1 + (y2 - y1) * (xMax - x1) / (x2 - x1);
            } else if (code & 4) { // Bottom
                y = yMin;
                x = x1 + (x2 - x1) * (yMin - y1) / (y2 - y1);
            } else if (code & 8) { // Top
                y = yMax;
                x = x1 + (x2 - x1) * (yMax - y1) / (y2 - y1);
            }

            if (code == code1) {
                x1 = x;
                y1 = y;
                code1 = computeRegionCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeRegionCode(x2, y2);
            }
        }
    }
}
int main() {

    initwindow(600, 600);
    rectangle(xMin, yMin, xMax, yMax);
    setcolor(RED);
    // Draw and clip a line
    clipLine(50, 50, 450, 350);
    getch();
}