#include "game.h"

Game::Game() {
    initPieces();
}

void Game::initPieces() {
    // 初始化白兵
    for (int i = 0; i < 8; i++) {
        pieces.push_back(std::make_shared<Pawn>(PieceColor::WHITE, i, 1));
    }

    // 初始化黑兵
    for (int i = 0; i < 8; i++) {
        pieces.push_back(std::make_shared<Pawn>(PieceColor::BLACK, i, 6));
    }

    // TODO: 添加其他棋子（车、马、象、后、王等）
}

void Game::renderPieces(float squareSize) const {
    for (const auto& piece : pieces) {
        piece->render(squareSize);
    }
}
