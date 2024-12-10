#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : public Piece {
public:
    Knight(float x, float y, bool isWhite);
    void render() override;  
    bool isValidMove(float newX, float newY) override;

};

#endif // KNIGHT_H
