#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <string>

class Chessboard {
private:
    unsigned int vao, vbo; // OpenGL 顶点数组和缓冲区对象
    float vertices[288];   // 棋盘顶点数据 (8x8 的网格)

public:
    Chessboard();
    ~Chessboard();
    void load();    // 加载棋盘顶点
    void render();  // 渲染棋盘
};

#endif
