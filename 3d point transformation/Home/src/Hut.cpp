#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <iostream>

using namespace std;

// Define a 3D point
struct Point3D {
    float x, y, z;
};

// Define a 2D point
struct Point2D {
    float x, y;
};

// Function to draw a line between two 3D points after projection
void drawLine(Point3D p1, Point3D p2, bool isPerspective) {
    Point2D p1_2D, p2_2D;

    if (isPerspective) {
        // Perspective projection
        float d = 500;  // distance from the viewer
        p1_2D.x = d * p1.x / (d + p1.z);
        p1_2D.y = d * p1.y / (d + p1.z);
        p2_2D.x = d * p2.x / (d + p2.z);
        p2_2D.y = d * p2.y / (d + p2.z);
    } else {
        // Parallel projection
        p1_2D.x = p1.x;
        p1_2D.y = p1.y;
        p2_2D.x = p2.x;
        p2_2D.y = p2.y;
    }

    line(p1_2D.x + getmaxx() / 2, getmaxy() / 2 - p1_2D.y, p2_2D.x + getmaxx() / 2, getmaxy() / 2 - p2_2D.y);
}

// Function to translate a 3D point
void translate(Point3D &p, float tx, float ty, float tz) {
    p.x += tx;
    p.y += ty;
    p.z += tz;
}

// Function to scale a 3D point
void scale(Point3D &p, float sx, float sy, float sz) {
    p.x *= sx;
    p.y *= sy;
    p.z *= sz;
}

// Function to rotate a 3D point around the Z-axis
void rotateZ(Point3D &p, float angle) {
    float rad = angle * M_PI / 180;
    float x_new = p.x * cos(rad) - p.y * sin(rad);
    float y_new = p.x * sin(rad) + p.y * cos(rad);
    p.x = x_new;
    p.y = y_new;
}

// Function to rotate a 3D point around the Y-axis
void rotateY(Point3D &p, float angle) {
    float rad = angle * M_PI / 180;
    float x_new = p.x * cos(rad) + p.z * sin(rad);
    float z_new = -p.x * sin(rad) + p.z * cos(rad);
    p.x = x_new;
    p.z = z_new;
}

// Function to rotate a 3D point around the X-axis
void rotateX(Point3D &p, float angle) {
    float rad = angle * M_PI / 180;
    float y_new = p.y * cos(rad) - p.z * sin(rad);
    float z_new = p.y * sin(rad) + p.z * cos(rad);
    p.y = y_new;
    p.z = z_new;
}

// Function to draw a 3D cube
void drawCube(Point3D *vertices, bool isPerspective) {
    for (int i = 0; i < 4; i++) {
        drawLine(vertices[i], vertices[(i + 1) % 4], isPerspective);
        drawLine(vertices[i + 4], vertices[((i + 1) % 4) + 4], isPerspective);
        drawLine(vertices[i], vertices[i + 4], isPerspective);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Define vertices of a cube
    Point3D vertices[8] = {
        {100, 100, 100}, {200, 100, 100}, {200, 200, 100}, {100, 200, 100},
        {100, 100, 200}, {200, 100, 200}, {200, 200, 200}, {100, 200, 200}
    };

    // Initial drawing of the cube in parallel projection
    drawCube(vertices, false);

    getch();
    cleardevice();

    // Apply transformations
    for (int i = 0; i < 8; i++) {
        translate(vertices[i], 50, 50, 50);
        scale(vertices[i], 1.5, 1.5, 1.5);
        rotateX(vertices[i], 30);
        rotateY(vertices[i], 30);
        rotateZ(vertices[i], 30);
    }

    // Draw the transformed cube in parallel projection
    drawCube(vertices, false);

    getch();
    cleardevice();

    // Draw the transformed cube in perspective projection
    drawCube(vertices, true);

    getch();
    closegraph();
    return 0;
}
