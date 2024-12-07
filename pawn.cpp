#include "pawn.h"
#include <iostream>

// 构造函数
Pawn::Pawn(float x, float y, bool isWhite) : Piece(x, y, isWhite) {
    setSize(0.4f);  // 设置大小为棋盘格子的 40%
    if (isWhite) {
        setColor(1.0f, 1.0f, 1.0f);  // 白色
    } else {
        setColor(0.0f, 0.0f, 0.0f);  // 黑色
    }
}

// 渲染棋子
void Pawn::render () {
    float gridSize = 1.0f;  // 棋盘每个格子的大小
    float offset = gridSize / 2.0f;  // 偏移量，使棋子位于网格中心
    float posX = x * gridSize + offset;  // 修正 x 坐标
    float posY = y * gridSize + offset;  // 修正 y 坐标

    glBegin(GL_TRIANGLES);
    glColor3f(colorR, colorG, colorB);
    glVertex2f(posX - size, posY - size);
    glVertex2f(posX + size, posY - size);
    glVertex2f(posX, posY + size);
    glEnd();
    std::cout << "Pawn at grid (" << x << ", " << y << ") is drawn at (" << posX << ", " << posY << ")\n";
}

bool Pawn::isValidMove(float newX, float newY) {
    if (isWhite) {
        return (newX == this->x && newY == this->y + 1) ||
               (this->y == 1 && newX == this->x && newY == this->y + 2) ||
               (abs(newX - this->x) == 1 && newY == this->y + 1); // 吃子
    } else {
        return (newX == this->x && newY == this->y - 1) ||
               (this->y == 6 && newX == this->x && newY == this->y - 2) ||
               (abs(newX - this->x) == 1 && newY == this->y - 1); // 吃子
    }
}
