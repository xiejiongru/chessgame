#include "game.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"

#include <iostream>
#include <GL/glut.h>
#include <algorithm> // for std::random_shuffle

Game::Game() : currentPlayer(true) {
    std::srand(std::time(nullptr)); // Initialize the random number seed
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            board[i][j] = nullptr;
}
Game::~Game() {
}

void Game::initialize() {
    for (int i = 0; i < 8; ++i) {
        board[i][1] = std::make_unique<Pawn>(i, 1, true);  // White Pawn
        board[i][6] = std::make_unique<Pawn>(i, 6, false); // Black Pawn
    }

    // Initialize the main pieces
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

    setupMajorPieces(0, true);  
    setupMajorPieces(7, false);
}


std::vector<std::pair<int, int>> Game::getValidMoves(int x, int y) {
    std::vector<std::pair<int, int>> validMoves;

    // If no piece at given position
    if (!board[x][y]) return validMoves;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[x][y]->isValidMove(i, j) &&
                (!board[i][j] || board[i][j]->isWhitePiece() != board[x][y]->isWhitePiece())) {
                validMoves.emplace_back(i, j);
            }
        }
    }

    std::cout << "Selected piece at (" << x << ", " << y << ")\n";
    std::cout << "Valid moves: ";
    for (auto& move : validMoves) {
        std::cout << "(" << move.first << ", " << move.second << ") ";
    }
    std::cout << std::endl;

    return validMoves;
}


void Game::makeRandomMove() {
    std::vector<std::pair<int, int>> validMoves;
    int fromX, fromY, toX, toY;

    do {
        fromX = rand() % 8;
        fromY = rand() % 8;
    } while (!board[fromX][fromY] || board[fromX][fromY]->isWhitePiece() != currentPlayer);

    validMoves = getValidMoves(fromX, fromY);

    // if no valid moves, then pass
    if (validMoves.empty()) {
        std::cout << "No valid moves for piece at (" << fromX << ", " << fromY << ")\n";
        return;
    }

    auto move = validMoves[rand() % validMoves.size()];
    toX = move.first;
    toY = move.second;

    std::cout << "Moving piece from (" << fromX << ", " << fromY << ") to (" << toX << ", " << toY << ")\n";
    movePiece(fromX, fromY, toX, toY);
}


bool Game::isInCheck(bool whitePlayer) {
    // 1.Find the king position
    int kingX = -1, kingY = -1;
    
    // Find the king position for the given player
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

    // 2. Check if any enemy piece can attack the king
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            // Enemy piece only
            if (board[i][j] && board[i][j]->isWhitePiece() != whitePlayer) {
                if (board[i][j]->isValidMove(kingX, kingY)) {
                    return true; // if true, king is in check
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
    std::cout << "Drawing the chessboard...\n";
}

void Game::renderPieces() {
    // render all pieces
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j]) {
                board[i][j]->render(); 
            }
        }
    }
    std::cout << "Rendering chess pieces...\n";
}

bool Game::movePiece(int fromX, int fromY, int toX, int toY) {
    if (!board[fromX][fromY]) {
        std::cout << "No piece at start position.\n";
        return false;
    }

    if (toX < 0 || toX >= 8 || toY < 0 || toY >= 8) {
        std::cout << "Target position out of bounds.\n";
        return false;
    }

    if (board[fromX][fromY]->isWhitePiece() != currentPlayer) {
        std::cout << "It's not your turn!\n";
        return false;
    }

    if (board[toX][toY] && board[toX][toY]->isWhitePiece() == currentPlayer) {
        std::cout << "Cannot capture your own piece.\n";
        return false;
    }

    if (!board[fromX][fromY]->isValidMove(toX, toY)) {
        std::cout << "Invalid move.\n";
        return false;
    }

    if (board[toX][toY] && board[toX][toY]->isWhitePiece() != board[fromX][fromY]->isWhitePiece()) {
    std::cout << "Piece at (" << toX << ", " << toY << ") is captured!\n";
    board[toX][toY] = nullptr; 
    }

    // move piece
    board[toX][toY] = std::move(board[fromX][fromY]);
    board[fromX][fromY] = nullptr;

    // check if the move results in check
    board[toX][toY]->setPosition(toX, toY);

    // switch player
    currentPlayer = !currentPlayer;

    return true;
}




