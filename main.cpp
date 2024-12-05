#include <vector>
#include <iostream>
#include <GL/glut.h>
#include "chessboard.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"


// 全局变量，保存棋子
std::vector<Piece*> pieces;

// 函数声明
void layoutPieces(std::vector<Piece*>& pieces);
void initializePieces();

// 创建棋子的布局
void layoutPieces(std::vector<Piece*>& pieces) {
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (y == 1) {
                // 白色兵
                pieces.push_back(new Pawn(x, y, true));
            } else if (y == 6) {
                // 黑色兵
                pieces.push_back(new Pawn(x, y, false));
            } else if (y == 0) {
                // 白色主力棋子
                if (x == 0 || x == 7) pieces.push_back(new Rook(x, y, true));
                if (x == 1 || x == 6) pieces.push_back(new Knight(x, y, true));
                if (x == 2 || x == 5) pieces.push_back(new Bishop(x, y, true));
                if (x == 3) pieces.push_back(new Queen(x, y, true));
                if (x == 4) pieces.push_back(new King(x, y, true));
            } else if (y == 7) {
                // 黑色主力棋子
                if (x == 0 || x == 7) pieces.push_back(new Rook(x, y, false));
                if (x == 1 || x == 6) pieces.push_back(new Knight(x, y, false));
                if (x == 2 || x == 5) pieces.push_back(new Bishop(x, y, false));
                if (x == 3) pieces.push_back(new Queen(x, y, false));
                if (x == 4) pieces.push_back(new King(x, y, false));
            }
        }
    }
}

// 初始化棋子，只调用一次
void initializePieces() {
    layoutPieces(pieces);
}

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

    // 初始化棋子布局
    initializePieces();
}

// 绘制棋盘和棋子
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawChessBoard();  // 绘制棋盘

    for (auto piece : pieces) {
        piece->render();
    }

    glutSwapBuffers();
}

// 主函数
int main(int argc, char** argv) {
    initOpenGL(argc, argv);

    glutDisplayFunc(display);
    glutMainLoop();

    // 清理内存
    for (auto piece : pieces) {
        delete piece;
    }
    pieces.clear();

    return 0;
}

