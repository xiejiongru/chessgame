#include "game.h"
#include <iostream>
#include <GL/glut.h>
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"


Game::Game() : currentPlayer(true) {
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            board[i][j] = nullptr;
}

Game::~Game() {
    // 不需要显式释放，智能指针会自动管理
}

void Game::initialize() {
    // 初始化白色兵
    for (int i = 0; i < 8; ++i) {
        board[i][1] = std::make_unique<Pawn>(i, 1, true);  // 白色兵
        board[i][6] = std::make_unique<Pawn>(i, 6, false); // 黑色兵
    }

    // 初始化白色主力
    board[0][0] = std::make_unique<Rook>(0, 0, true);
    board[7][0] = std::make_unique<Rook>(7, 0, true);
    board[1][0] = std::make_unique<Knight>(1, 0, true);
    board[6][0] = std::make_unique<Knight>(6, 0, true);
    board[2][0] = std::make_unique<Bishop>(2, 0, true);
    board[5][0] = std::make_unique<Bishop>(5, 0, true);
    board[3][0] = std::make_unique<Queen>(3, 0, true);
    board[4][0] = std::make_unique<King>(4, 0, true);

    // 初始化黑色主力
    board[0][7] = std::make_unique<Rook>(0, 7, false);
    board[7][7] = std::make_unique<Rook>(7, 7, false);
    board[1][7] = std::make_unique<Knight>(1, 7, false);
    board[6][7] = std::make_unique<Knight>(6, 7, false);
    board[2][7] = std::make_unique<Bishop>(2, 7, false);
    board[5][7] = std::make_unique<Bishop>(5, 7, false);
    board[3][7] = std::make_unique<Queen>(3, 7, false);
    board[4][7] = std::make_unique<King>(4, 7, false);
}


bool Game::isInCheck(bool whitePlayer) {
    // 1. 查找玩家的国王的位置
    int kingX = -1, kingY = -1;
    
    // 寻找指定玩家的国王位置
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] && board[i][j]->getType() == "King" && board[i][j]->isWhitePiece() == whitePlayer) {
                kingX = i;
                kingY = j;
                break;
            }
        }
        if (kingX != -1) break; // 找到国王后跳出循环
    }
    
    if (kingX == -1) {
        std::cout << "King not found!\n";
        return false; // 如果没有找到国王，返回 false
    }

    // 2. 检查敌方棋子是否能攻击到国王
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            // 只考虑敌方棋子
            if (board[i][j] && board[i][j]->isWhitePiece() != whitePlayer) {
                // 检查敌方棋子是否能攻击到国王
                if (board[i][j]->isValidMove(kingX, kingY)) {
                    return true; // 如果敌方棋子可以攻击到国王，返回 true（表示将军）
                }
            }
        }
    }

    return false; // 如果没有敌方棋子能攻击到国王，返回 false（表示没有将军）
}

void Game::processInput() {
    int startX, startY, endX, endY;
    std::cout << "Enter your move (startX startY endX endY): ";
    std::cin >> startX >> startY >> endX >> endY;
    if (!movePiece(startX, startY, endX, endY)) {
        std::cout << "Invalid move, try again.\n";
    }
}

void Game::drawChessBoard() {
    // 使用 OpenGL 或其他库实现棋盘绘制
    glBegin(GL_QUADS);  // 使用 OpenGL 绘制棋盘的简单代码
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                glColor3f(1.0f, 1.0f, 1.0f);  // 白色格子
            } else {
                glColor3f(0.0f, 0.0f, 0.0f);  // 黑色格子
            }
            glVertex2f(i, j);
            glVertex2f(i + 1, j);
            glVertex2f(i + 1, j + 1);
            glVertex2f(i, j + 1);
        }
    }
    glEnd();
    std::cout << "Drawing the chessboard...\n";
}

void Game::renderPieces() {
    // 渲染所有棋子
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j]) {
                board[i][j]->render();  // 使用棋子的渲染方法
            }
        }
    }
    std::cout << "Rendering chess pieces...\n";
}

bool Game::movePiece(int fromX, int fromY, int toX, int toY) {
    // 获取起始位置的棋子（使用引用）
    std::unique_ptr<Piece>& piece = board[fromX][fromY];  // 使用引用避免复制

    if (!piece) {
        std::cout << "No piece at start position.\n";
        return false;
    }

    // 检查是否是当前玩家的棋子
    if (piece->isWhitePiece() != currentPlayer) {
        std::cout << "It's not your turn!\n";
        return false;
    }

    // 验证目标位置的棋子是否可捕捉
    std::unique_ptr<Piece>& target = board[toX][toY];  // 使用引用
    if (target && target->isWhitePiece() == currentPlayer) {
        std::cout << "Cannot capture your own piece.\n";
        return false;
    }

    // 检查目标位置是否合法
    if (!piece->isValidMove(toX, toY)) {
        std::cout << "Invalid move.\n";
        return false;
    }

    // 将棋子从起始位置移动到目标位置
    board[toX][toY] = std::move(piece);  // 使用 std::move 移动棋子
    board[fromX][fromY] = nullptr;  // 清空起始位置

    // 更新棋子的实际位置
    piece->setPosition(toX, toY);

    // 切换玩家
    currentPlayer = !currentPlayer;

    return true;
}


