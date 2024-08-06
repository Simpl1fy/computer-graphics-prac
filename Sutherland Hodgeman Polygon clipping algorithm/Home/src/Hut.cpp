#include <graphics.h>

// Function to draw a polygon
void drawPolygon(int n, int x[], int y[]) {
    for (int i = 0; i < n; i++) {
        line(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
    }
}

// Sutherland-Hodgman Polygon Clipping Algorithm
void clipPolygon(int n, int x[], int y[], int x1, int y1, int x2, int y2) {
    int m = 0;
    int outx[100], outy[100];

    // Iterate over each edge of the polygon
    for (int i = 0; i < n; i++) {
        int x3 = x[i], y3 = y[i];
        int x4 = x[(i + 1) % n], y4 = y[(i + 1) % n];

        // Check if the edge intersects with the clip edge
        if ((x3 - x1) * (y2 - y1) - (y3 - y1) * (x2 - x1) >= 0 &&
            (x4 - x1) * (y2 - y1) - (y4 - y1) * (x2 - x1) < 0) {
            // Calculate the intersection point
            float t = ((x1 - x3) * (y2 - y1) - (y1 - y3) * (x2 - x1)) /
                      ((x4 - x3) * (y2 - y1) - (y4 - y3) * (x2 - x1));
            outx[m] = x3 + (int)((x4 - x3) * t);
            outy[m] = y3 + (int)((y4 - y3) * t);
            m++;
        }

        // Check if the edge is inside the clip edge
        if ((x3 - x1) * (y2 - y1) - (y3 - y1) * (x2 - x1) >= 0 &&
            (x4 - x1) * (y2 - y1) - (y4 - y1) * (x2 - x1) >= 0) {
            outx[m] = x4;
            outy[m] = y4;
            m++;
        }
    }

    // Draw the clipped polygon
    drawPolygon(m, outx, outy);
}

int main() {
    // Set window siz
    initwindow(600, 600);
    // Define the polygon
    int n = 5;
    int x[] = {100, 200, 250, 150, 50};
    int y[] = {100, 50, 200, 250, 150};
    // Define the clip edge
    int x1 = 100, y1 =100;
    int x2 = 250, y2 = 200;
    // Draw the original polygon
    drawPolygon(n, x, y);
	setcolor(RED);
    // Clip the polygon
    clipPolygon(n, x, y, x1, y1, x2, y2);
    
    getch();
    return 0;
}