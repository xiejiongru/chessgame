#include "chessboard.h"
#include <GL/glew.h>
#include <iostream>

Chessboard::Chessboard() : vao(0), vbo(0) {
    // 初始化棋盘顶点数据 (8x8 棋盘格，每个格子 6 个顶点)
    float gridSize = 1.0f;
    int idx = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            float x = i * gridSize;
            float z = j * gridSize;

            // 当前格子的颜色
            float color = ((i + j) % 2 == 0) ? 1.0f : 0.0f;

            // 每个格子 6 个顶点，分别定义 x, y, z, r, g, b
            vertices[idx++] = x;     vertices[idx++] = 0.0f; vertices[idx++] = z;     vertices[idx++] = color; vertices[idx++] = color; vertices[idx++] = color;
            vertices[idx++] = x + 1; vertices[idx++] = 0.0f; vertices[idx++] = z;     vertices[idx++] = color; vertices[idx++] = color; vertices[idx++] = color;
            vertices[idx++] = x + 1; vertices[idx++] = 0.0f; vertices[idx++] = z + 1; vertices[idx++] = color; vertices[idx++] = color; vertices[idx++] = color;

            vertices[idx++] = x;     vertices[idx++] = 0.0f; vertices[idx++] = z;     vertices[idx++] = color; vertices[idx++] = color; vertices[idx++] = color;
            vertices[idx++] = x + 1; vertices[idx++] = 0.0f; vertices[idx++] = z + 1; vertices[idx++] = color; vertices[idx++] = color; vertices[idx++] = color;
            vertices[idx++] = x;     vertices[idx++] = 0.0f; vertices[idx++] = z + 1; vertices[idx++] = color; vertices[idx++] = color; vertices[idx++] = color;
        }
    }
}

Chessboard::~Chessboard() {
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
}

void Chessboard::load() {
    // 创建 VAO 和 VBO
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // 设置顶点属性
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Chessboard::render() {
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, 8 * 8 * 6);
    glBindVertexArray(0);
}
