#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : public Piece {
public:
    Knight();
    std::string getName() const override;
    bool isValidMove(int startX, int startY, int endX, int endY) const override;
};

#endif // KNIGHT_H
