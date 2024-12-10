#include "queen.h"
#include <GL/glut.h>
#include <iostream>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159
#endif

Queen::Queen(float x, float y, bool isWhite) : Piece(x, y, isWhite) {
        setSize(0.4f);
        setColor(isWhite ? 0.9f : 0.2f, isWhite ? 0.9f : 0.2f, isWhite ? 0.9f : 0.2f);
    }

void Queen::render(){
    float gridSize = 1.0f;
    float offset = gridSize / 2.0f;
    float posX = x * gridSize + offset;
    float posY = y * gridSize + offset;

    glBegin(GL_POLYGON);
    glColor3f(colorR, colorG, colorB);
    for (int i = 0; i < 5; ++i) {
        float angle = i * 2 * M_PI / 5; 
        glVertex2f(posX + cos(angle) * size, posY + sin(angle) * size);
    }
    glEnd();
    std::cout << "Queen at grid (" << x << ", " << y << ") is drawn at (" << posX << ", " << posY << ")\n";
}

bool Queen::isValidMove(float newX, float newY){
        // Queen move: any direction
        return (newX == x || newY == y || abs(newX - x) == abs(newY - y));
}