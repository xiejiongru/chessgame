#include "bishop.h"
#include <GL/glut.h>
#include <iostream>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159
#endif
Bishop::Bishop(float x, float y, bool isWhite) : Piece(x, y, isWhite) {
        setSize(0.4f);
        setColor(isWhite ? 0.9f : 0.2f, isWhite ? 0.9f : 0.2f, isWhite ? 0.9f : 0.2f);
    }

void Bishop::render(){
    float gridSize = 1.0f;
    float offset = gridSize / 2.0f;
    float posX = x * gridSize + offset;
    float posY = y * gridSize + offset;

    glBegin(GL_POLYGON);
    glColor3f(colorR, colorG, colorB);
    for (int i = 0; i < 360; i += 10) {  
        float rad = i * M_PI / 180.0f;   
        glVertex2f(posX + cos(rad) * size, posY + sin(rad) * size);
    }
    glEnd();
    std::cout << "Bishop at grid (" << x << ", " << y << ") is drawn at (" << posX << ", " << posY << ")\n";
}

bool Bishop::isValidMove(float newX, float newY) {
    return (abs(newX - x) == abs(newY - y));
}
