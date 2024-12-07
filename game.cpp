#include <iostream>
#include <GL/glut.h>
#include "piece.h"
#include "game.h"
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
    layoutPieces(); // 调用layoutPieces进行初始化
}

void Game::layoutPieces() {
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

    // 将棋盘中的棋子移动到 pieces 向量中
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j]) {
                pieces.push_back(std::move(board[i][j]));  // 使用 std::move
            }
        }
    }
}

bool Game::isInCheck(bool whitePlayer) {
    int kingX = -1, kingY = -1;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] && board[i][j]->getType() == "King" && board[i][j]->isWhitePiece() == whitePlayer) {
                kingX = i;
                kingY = j;
                break;
            }
        }
        if (kingX != -1) break;
    }

    if (kingX == -1) {
        std::cout << "King not found!\n";
        return false;
    }

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] && board[i][j]->isWhitePiece() != whitePlayer) {
                if (board[i][j]->isValidMove(kingX, kingY)) {
                    return true;
                }
            }
        }
    }

    return false;
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
    glBegin(GL_QUADS);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                glColor3f(1.0f, 1.0f, 1.0f);
            } else {
                glColor3f(0.0f, 0.0f, 0.0f);
            }
            glVertex2f(i, j);
            glVertex2f(i + 1, j);
            glVertex2f(i + 1, j + 1);
            glVertex2f(i, j + 1);
        }
    }
    glEnd();
}

void Game::renderPieces() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j]) {
                board[i][j]->render();
            }
        }
    }
}

bool Game::movePiece(int fromX, int fromY, int toX, int toY) {
   std::unique_ptr<Piece>& piece = board[fromX][fromY];

   if (!piece) {
       std::cout << "No piece at start position.\n";
       return false;
   }

   if (piece->isWhitePiece() != currentPlayer) {
       std::cout << "It's not your turn!\n";
       return false;
   }

   std::unique_ptr<Piece>& target = board[toX][toY];
   if (target && target->isWhitePiece() == currentPlayer) {
       std::cout << "Cannot capture your own piece.\n";
       return false;
   }

   if (!piece->isValidMove(toX, toY)) {
       std::cout << "Invalid move.\n";
       return false;
   }

   board[toX][toY] = std::move(piece);
   board[fromX][fromY] = nullptr;
   piece->setPosition(toX, toY);

   currentPlayer = !currentPlayer;

   return true;
}

const std::vector<std::unique_ptr<Piece>>& Game::getPieces() const {
    static std::vector<std::unique_ptr<Piece>> pieces;
    pieces.clear();

    // 将棋盘中的所有棋子添加到 pieces 中
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j]) {
                pieces.push_back(std::move(board[i][j]));
            }
        }
    }
    return pieces;
}

