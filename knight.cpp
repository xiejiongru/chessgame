#include "knight.h"
#include <GL/glut.h>
#include <cmath>
#include <iostream>


Knight::Knight(float x, float y, bool isWhite) : Piece(x, y, isWhite) {
    setSize(0.4f);
    if (isWhite) {
        setColor(1.0f, 1.0f, 1.0f);
    } else {
        setColor(0.0f, 0.0f, 0.0f);
    }
}

void Knight::render() {
    float gridSize = 1.0f; // 棋盘每个格子的大小
    float offset = gridSize / 2.0f; // 偏移量，使棋子位于网格中心
    float posX = x * gridSize + offset; // 计算渲染位置
    float posY = y * gridSize + offset;

    glBegin(GL_TRIANGLES); // 开始绘制三角形
    glColor3f(colorR, colorG, colorB); // 设置颜色

    glVertex2f(posX, posY + size); // 顶点
    glVertex2f(posX - size, posY - size); // 左下
    glVertex2f(posX + size, posY - size); // 右下

    glEnd();

bool Knight::isValidMove(float newX, float newY){
        // 马的走法是“日”字型：2格直线 + 1格垂直
        return (abs(newX - x) == 2 && abs(newY - y) == 1) || (abs(newX - x) == 1 && abs(newY - y) == 2);
}

