#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 40
#define HEIGHT 20

char canvas[HEIGHT][WIDTH];

// Initialize canvas with '_'
void init_canvas() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            canvas[i][j] = '_';
        }
    }
}

// Display the canvas
void display_canvas() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}

// Draw a rectangle
void draw_rectangle(int x, int y, int w, int h) {
    for (int i = y; i < y + h && i < HEIGHT; i++) {
        for (int j = x; j < x + w && j < WIDTH; j++) {
            canvas[i][j] = '*';
        }
    }
}

// Draw a line (simple horizontal/vertical only)
void draw_line(int x1, int y1, int x2, int y2) {
    if (y1 == y2) { // horizontal
        for (int j = x1; j <= x2 && j < WIDTH; j++) {
            canvas[y1][j] = '*';
        }
    } else if (x1 == x2) { // vertical
        for (int i = y1; i <= y2 && i < HEIGHT; i++) {
            canvas[i][x1] = '*';
        }
    }
}

// Draw a circle (midpoint approximation)
void draw_circle(int cx, int cy, int r) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int dx = j - cx;
            int dy = i - cy;
            if (dx*dx + dy*dy <= r*r) {
                canvas[i][j] = '*';
            }
        }
    }
}

// Draw a triangle (simple filled right triangle)
void draw_triangle(int x, int y, int size) {
    for (int i = 0; i < size && y+i < HEIGHT; i++) {
        for (int j = 0; j <= i && x+j < WIDTH; j++) {
            canvas[y+i][x+j] = '*';
        }
    }
}

// Delete object (replace with '_')
void delete_object(int x, int y, int w, int h) {
    for (int i = y; i < y + h && i < HEIGHT; i++) {
        for (int j = x; j < x + w && j < WIDTH; j++) {
            canvas[i][j] = '_';
        }
    }
}

// Modify object (example: redraw rectangle with new size)
void modify_rectangle(int x, int y, int old_w, int old_h, int new_w, int new_h) {
    delete_object(x, y, old_w, old_h);
    draw_rectangle(x, y, new_w, new_h);
}

int main() {
    init_canvas();

    draw_rectangle(2, 2, 10, 4);
    draw_line(0, 10, 20, 10);
    draw_circle(25, 8, 5);
    draw_triangle(5, 12, 6);

    printf("Initial Picture:\n");
    display_canvas();

    modify_rectangle(2, 2, 10, 4, 6, 3);
    printf("\nAfter Modification:\n");
    display_canvas();

    delete_object(25, 8, 10, 10);
    printf("\nAfter Deletion:\n");
    display_canvas();

    return 0;
}
