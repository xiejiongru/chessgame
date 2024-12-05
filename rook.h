#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public Piece {
public:
    Rook();
    std::string getName() const override;
    bool isValidMove(int startX, int startY, int endX, int endY) const override;
};

#endif // ROOK_H
