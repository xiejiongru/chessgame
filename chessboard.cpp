#include "chessboard.h"
#include <GL/glut.h>
#include <iostream>

void drawChessBoard() {
    float gridSize = 1.0f;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                glColor3f(1.0f, 1.0f, 1.0f);  
            } else {
                glColor3f(0.0f, 0.0f, 0.0f);  
            }

            glBegin(GL_QUADS);
            glVertex2f(i * gridSize, j * gridSize);
            glVertex2f((i + 1) * gridSize, j * gridSize);
            glVertex2f((i + 1) * gridSize, (j + 1) * gridSize);
            glVertex2f(i * gridSize, (j + 1) * gridSize);
            glEnd();

            // Print the position of each grid
            std::cout << "Grid at (" << i << ", " << j << ")\n";
        }
    }
}
