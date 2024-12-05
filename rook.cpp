#include "rook.h"
#include <GL/glut.h>

Rook::Rook(float x, float y, bool isWhite) : Piece(x, y, isWhite) {
    setSize(0.35f);  // 设置大小
    if (isWhite) {
        setColor(1.0f, 1.0f, 1.0f);  // 白色
    } else {
        setColor(0.0f, 0.0f, 0.0f);  // 黑色
    }
}

void Rook::render() {
    float gridSize = 1.0f;
    float offset = gridSize / 2.0f;
    float posX = x * gridSize + offset;
    float posY = y * gridSize + offset;

    // 绘制车：一个简单的正方形
    glBegin(GL_QUADS);
    glColor3f(colorR, colorG, colorB);
    glVertex2f(posX - size, posY - size);
    glVertex2f(posX + size, posY - size);
    glVertex2f(posX + size, posY + size);
    glVertex2f(posX - size, posY + size);
    glEnd();
}
