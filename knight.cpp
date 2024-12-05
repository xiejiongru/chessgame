#include "knight.h"
#include <GL/glut.h>
#include <cmath>

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

    // 绘制马：一个简单的弧线+顶点组合
    glBegin(GL_POLYGON);
    glColor3f(colorR, colorG, colorB);
    for (int i = 0; i <= 180; ++i) {
        float angle = i * M_PI / 180;
        float dx = cos(angle) * size;
        float dy = sin(angle) * size;
        glVertex2f(posX + dx, posY + dy);
    }
    glEnd();
}
