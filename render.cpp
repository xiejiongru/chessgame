#include "render.h"
#include <GL/glew.h>
#include <GL/glut.h>
#include <iostream>

Render::Render() {
    shader = nullptr;
    VAO = VBO = 0;
}

void Render::initialize() {
    shader = new Shader("vertex_shader.glsl", "fragment_shader.glsl");

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // OpenGL 初始化代码
}

void Render::drawChessBoard() {
    // 使用 OpenGL 绘制棋盘
    shader->use();
    // 绘制棋盘
}

void Render::renderPieces(const std::vector<std::unique_ptr<Piece>>& pieces) {
    shader->use();
    for (const auto& piece : pieces) {
        piece->render();  // 每个棋子的渲染
    }
    std::cout << "Rendering chess pieces...\n";
}
