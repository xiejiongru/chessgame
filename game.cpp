#include "game.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

#include <iostream>
#include <GL/glut.h>
#include <algorithm> // 用于 std::random_shuffle

Game::Game() : currentPlayer(true) {
    std::srand(std::time(nullptr)); // 初始化随机数种子
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            board[i][j] = nullptr;
}
Game::~Game() {
}

void Game::initialize() {
    // 初始化白色兵
    for (int i = 0; i < 8; ++i) {
        board[i][1] = std::make_unique<Pawn>(i, 1, true);  // 白色兵
        board[i][6] = std::make_unique<Pawn>(i, 6, false); // 黑色兵
    }

    // 初始化主要棋子
    auto setupMajorPieces = [&](int y, bool isWhite) {
        board[0][y] = std::make_unique<Rook>(0, y, isWhite);
        board[7][y] = std::make_unique<Rook>(7, y, isWhite);
        board[1][y] = std::make_unique<Knight>(1, y, isWhite);
        board[6][y] = std::make_unique<Knight>(6, y, isWhite);
        board[2][y] = std::make_unique<Bishop>(2, y, isWhite);
        board[5][y] = std::make_unique<Bishop>(5, y, isWhite);
        board[3][y] = std::make_unique<Queen>(3, y, isWhite);
        board[4][y] = std::make_unique<King>(4, y, isWhite);
    };

    setupMajorPieces(0, true);  // 白色主力
    setupMajorPieces(7, false); // 黑色主力
}


// 获取指定棋子的所有合法移动位置
std::vector<std::pair<int, int>> Game::getValidMoves(int x, int y) {
    std::vector<std::pair<int, int>> validMoves;

    // 如果该位置没有棋子，直接返回空的合法移动列表
    if (!board[x][y]) return validMoves;

    // 遍历棋盘所有位置，检查是否是合法移动
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[x][y]->isValidMove(i, j) &&
                (!board[i][j] || board[i][j]->isWhitePiece() != board[x][y]->isWhitePiece())) {
                validMoves.emplace_back(i, j);
            }
        }
    }

    // 打印选中棋子和合法移动
    std::cout << "Selected piece at (" << x << ", " << y << ")\n";
    std::cout << "Valid moves: ";
    for (auto& move : validMoves) {
        std::cout << "(" << move.first << ", " << move.second << ") ";
    }
    std::cout << std::endl;

    return validMoves;
}


// 随机移动当前玩家的一个棋子
void Game::makeRandomMove() {
    std::vector<std::pair<int, int>> validMoves;
    int fromX, fromY, toX, toY;

    // 随机选择一个棋子
    do {
        fromX = rand() % 8;
        fromY = rand() % 8;
    } while (!board[fromX][fromY] || board[fromX][fromY]->isWhitePiece() != currentPlayer);

    // 获取有效移动
    validMoves = getValidMoves(fromX, fromY);

    // 如果没有有效移动，跳过
    if (validMoves.empty()) {
        std::cout << "No valid moves for piece at (" << fromX << ", " << fromY << ")\n";
        return;
    }

    // 随机选择一个有效移动
    auto move = validMoves[rand() % validMoves.size()];
    toX = move.first;
    toY = move.second;

    // 移动棋子
    std::cout << "Moving piece from (" << fromX << ", " << fromY << ") to (" << toX << ", " << toY << ")\n";
    movePiece(fromX, fromY, toX, toY);
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
    // 检查起始位置是否有棋子
    if (!board[fromX][fromY]) {
        std::cout << "No piece at start position.\n";
        return false;
    }

    // 检查目标位置是否在范围内
    if (toX < 0 || toX >= 8 || toY < 0 || toY >= 8) {
        std::cout << "Target position out of bounds.\n";
        return false;
    }

    // 检查是否是当前玩家的棋子
    if (board[fromX][fromY]->isWhitePiece() != currentPlayer) {
        std::cout << "It's not your turn!\n";
        return false;
    }

    // 验证目标位置的棋子是否可捕捉
    if (board[toX][toY] && board[toX][toY]->isWhitePiece() == currentPlayer) {
        std::cout << "Cannot capture your own piece.\n";
        return false;
    }

    // 检查目标位置是否合法
    if (!board[fromX][fromY]->isValidMove(toX, toY)) {
        std::cout << "Invalid move.\n";
        return false;
    }

    // 移动棋子
    board[toX][toY] = std::move(board[fromX][fromY]);
    board[fromX][fromY] = nullptr;

    // 更新棋子位置
    board[toX][toY]->setPosition(toX, toY);

    // 切换玩家
    currentPlayer = !currentPlayer;

    return true;
}




