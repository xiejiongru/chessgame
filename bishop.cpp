#include "bishop.h"
#include <GL/glut.h>
#include <iostream>

Bishop::Bishop(float x, float y, bool isWhite) : Piece(x, y, isWhite) {
        setSize(0.4f);
        setColor(isWhite ? 1.0f : 0.0f, isWhite ? 1.0f : 0.0f, isWhite ? 1.0f : 0.0f);
    }

void Bishop::render(){
    float gridSize = 1.0f;
    float offset = gridSize / 2.0f;
    float posX = x * gridSize + offset;
    float posY = y * gridSize + offset;

    glBegin(GL_POLYGON);
    glColor3f(colorR, colorG, colorB);
    glVertex2f(posX, posY + size); // 顶点
    glVertex2f(posX - size, posY - size);
    glVertex2f(posX + size, posY - size);
    glEnd();
    std::cout << "Bishop at grid (" << x << ", " << y << ") is drawn at (" << posX << ", " << posY << ")\n";
}

bool Bishop::isValidMove(float newX, float newY) {
    return (abs(newX - x) == abs(newY - y));
}
