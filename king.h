#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece {
public:
    King(float x, float y, bool isWhite);
    void render() override;
    bool isValidMove(float newX, float newY) override;
};

#endif // KING_H
