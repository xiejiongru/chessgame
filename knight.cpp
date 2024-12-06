#include "knight.h"
#include <GL/glut.h>
#include <cmath>
#include <iostream>


Knight::Knight(float x, float y, bool isWhite) : Piece(x, y, isWhite) {
    setSize(0.3f);
    if (isWhite) {
        setColor(1.0f, 1.0f, 1.0f);
    } else {
        setColor(0.0f, 0.0f, 0.0f);
    }
}

void Knight::render() {
    float gridSize = 1.0f;
    float offset = gridSize / 2.0f;
    float posX = x * gridSize + offset;
    float posY = y * gridSize + offset;

    glColor3f(colorR, colorG, colorB);
    glPushMatrix();
    glTranslatef(posX, posY, 0);
    glutSolidSphere(size, 20, 20); // 用球体代替马的弧线
    glPopMatrix();
    std::cout << "Knight at grid (" << x << ", " << y << ") is drawn at (" << posX << ", " << posY << ")\n";
}

bool Knight::isValidMove(float newX, float newY){
        // 马的走法是“日”字型：2格直线 + 1格垂直
        return (abs(newX - x) == 2 && abs(newY - y) == 1) || (abs(newX - x) == 1 && abs(newY - y) == 2);
}

