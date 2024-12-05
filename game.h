#ifndef GAME_H
#define GAME_H

#include "chessboard.h"
#include "pawn.h"
#include <vector>
#include <memory>

class Game {
    ChessBoard board;
    std::vector<std::shared_ptr<Piece>> pieces;

public:
    Game();
    void initPieces();
    void renderPieces(float squareSize) const;
};

#endif // GAME_H
