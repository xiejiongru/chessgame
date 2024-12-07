#include <GL/glut.h>
#include "piece.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

// 用于初始化OpenGL的函数
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

// 绘制棋盘的函数（此处仅示范简单绘制）
void drawChessBoard();

// 创建棋子的布局
void layoutPieces(std::vector<std::unique_ptr<Piece>>& pieces) {
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (y == 1) {
                pieces.push_back(std::move(std::make_unique<Pawn>(x, y, true)));
            } else if (y == 6) {
                pieces.push_back(std::move(std::make_unique<Pawn>(x, y, false)));
            } else if (y == 0) {
                if (x == 0 || x == 7) pieces.push_back(std::move(std::make_unique<Rook>(x, y, true)));
                if (x == 1 || x == 6) pieces.push_back(std::move(std::make_unique<Knight>(x, y, true)));
                if (x == 2 || x == 5) pieces.push_back(std::move(std::make_unique<Bishop>(x, y, true)));
                if (x == 3) pieces.push_back(std::move(std::make_unique<Queen>(x, y, true)));
                if (x == 4) pieces.push_back(std::move(std::make_unique<King>(x, y, true)));
            } else if (y == 7) {
                if (x == 0 || x == 7) pieces.push_back(std::move(std::make_unique<Rook>(x, y, false)));
                if (x == 1 || x == 6) pieces.push_back(std::move(std::make_unique<Knight>(x, y, false)));
                if (x == 2 || x == 5) pieces.push_back(std::move(std::make_unique<Bishop>(x, y, false)));
                if (x == 3) pieces.push_back(std::move(std::make_unique<Queen>(x, y, false)));
                if (x == 4) pieces.push_back(std::move(std::make_unique<King>(x, y, false)));
            }
        }
    }
}

// 初始化棋子，只调用一次
void initializePieces() {
    layoutPieces(Piece::pieces);  // 传递静态成员 pieces
}

// 绘制棋盘和棋子
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawChessBoard();  // 绘制棋盘

    for (auto& piece : Piece::pieces) {  // 遍历静态成员 pieces
        piece->render();  // 渲染每个棋子
    }

    glutSwapBuffers();
}

// 主函数
int main(int argc, char** argv) {
    initOpenGL(argc, argv);  // 初始化OpenGL

    initializePieces();  // 初始化棋子

    glutDisplayFunc(display);
    glutMainLoop();

    // 自动清理unique_ptr
    Piece::pieces.clear();  // 清除棋子列表

    return 0;
}
