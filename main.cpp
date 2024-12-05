#include <vector>
#include <iostream>
#include "chessboard.h"
#include "pawn.h"

// 初始化 OpenGL 的函数
void initOpenGL(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Chessboard");

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // 背景颜色
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 9.0, -1.0, 9.0);  // 投影范围
}

// 创建棋子的布局
void layoutPieces(std::vector<Piece*>& pieces) {
    for (int i = 0; i < 8; i++) {
        pieces.push_back(new Pawn(i, 1, true));  // 白色兵
        pieces.push_back(new Pawn(i, 6, false)); // 黑色兵
    }
}

// 绘制棋盘和棋子
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawChessBoard();  // 绘制棋盘

    // 创建并绘制棋子
    std::vector<Piece*> pieces;
    layoutPieces(pieces);

    for (auto piece : pieces) {
        piece->render();
    }

    // 打印棋子位置（用于调试）
    for (auto piece : pieces) {
        std::cout << "Piece at (" << piece->getX() << ", " << piece->getY() << ")\n";
    }

    // 清理内存
    for (auto piece : pieces) {
        delete piece;
    }

    glutSwapBuffers();
}

// 主函数
int main(int argc, char** argv) {
    initOpenGL(argc, argv);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
