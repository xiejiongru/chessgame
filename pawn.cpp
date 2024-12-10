#include "pawn.h"
#include <iostream>

Pawn::Pawn(float x, float y, bool isWhite) : Piece(x, y, isWhite) {
    setSize(0.4f);  //40pc of the chessboard 
    if (isWhite) {
        setColor(0.9f, 0.9f, 0.9f); 
    } else {
        setColor(0.2f, 0.2f, 0.2f); 
    }
}


void Pawn::render () {
    float gridSize = 1.0f;  
    float offset = gridSize / 2.0f;  
    float posX = x * gridSize + offset;  
    float posY = y * gridSize + offset;  

    glBegin(GL_QUADS);  // square
    glColor3f(colorR, colorG, colorB);
    glVertex2f(posX - size, posY - size);
    glVertex2f(posX + size, posY - size);
    glVertex2f(posX + size, posY + size);
    glVertex2f(posX - size, posY + size);
    glEnd();
    std::cout << "Pawn at grid (" << x << ", " << y << ") is drawn at (" << posX << ", " << posY << ")\n";
}

bool Pawn::isValidMove(float newX, float newY) {
    if (isWhite) {
        return (newX == this->x && newY == this->y + 1) ||
               (this->y == 1 && newX == this->x && newY == this->y + 2) ||
               (abs(newX - this->x) == 1 && newY == this->y + 1); 
    } else {
        return (newX == this->x && newY == this->y - 1) ||
               (this->y == 6 && newX == this->x && newY == this->y - 2) ||
               (abs(newX - this->x) == 1 && newY == this->y - 1); 
    }
}
