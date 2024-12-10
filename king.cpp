#include "king.h"
#include <GL/glut.h>
#include <iostream>
#include <cmath> 

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

King::King(float x, float y, bool isWhite) : Piece(x, y, isWhite) {
        setSize(0.4f);
        setColor(isWhite ? 0.9f : 0.2f, isWhite ? 0.9f : 0.2f, isWhite ? 0.9f : 0.2f);
    }

void King::render(){
    float gridSize = 1.0f;
    float offset = gridSize / 2.0f;
    float posX = x * gridSize + offset;
    float posY = y * gridSize + offset;
    
    float outerRadius = size;
    float innerRadius = size * 0.6f; 

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(colorR, colorG, colorB);
    glVertex2f(posX, posY);  
    for (int i = 0; i <= 10; ++i) {
        float angle = i * M_PI / 5;
        float radius = (i % 2 == 0) ? outerRadius : innerRadius; 
        glVertex2f(posX + cos(angle) * radius, posY + sin(angle) * radius);
    }
    glEnd();
        std::cout << "King at grid (" << x << ", " << y << ") is drawn at (" << posX << ", " << posY << ")\n";
}

bool King::isValidMove(float newX, float newY){
        // Only allow one square move
        return (abs(newX - x) <= 1 && abs(newY - y) <= 1);
}
