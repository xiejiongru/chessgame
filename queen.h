#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen : public Piece {
public:
    Queen(float x, float y, bool isWhite): Piece(x, y, isWhite) {};
    void render() override;
    bool isValidMove(float newX, float newY) override;
};

#endif // QUEEN_H
