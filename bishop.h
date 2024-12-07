#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public Piece {
public:
    Bishop(float x, float y, bool isWhite);
    void render() override;
    bool isValidMove(float newX, float newY) override;

};

#endif // BISHOP_H
