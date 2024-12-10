#include "knight.h"
#include <GL/glut.h>
#include <cmath>
#include <iostream>


Knight::Knight(float x, float y, bool isWhite) : Piece(x, y, isWhite) {
    setSize(0.4f);
    if (isWhite) {
        setColor(0.9f, 0.9f, 0.9f);
    } else {
        setColor(0.2f, 0.2f, 0.2f);
    }
}

void Knight::render() {
    float gridSize = 1.0f; 
    float offset = gridSize / 2.0f; 
    float posX = x * gridSize + offset; 
    float posY = y * gridSize + offset;

    glBegin(GL_TRIANGLES); 
    glColor3f(colorR, colorG, colorB); 

    glVertex2f(posX, posY + size); // top
    glVertex2f(posX - size, posY - size); // left bottom
    glVertex2f(posX + size, posY - size); // right bottom

    glEnd();
}

bool Knight::isValidMove(float newX, float newY){
        // horse moves: L shape
        return (abs(newX - x) == 2 && abs(newY - y) == 1) || (abs(newX - x) == 1 && abs(newY - y) == 2);
}

