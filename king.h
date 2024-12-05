#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece {
public:
    King();
    std::string getName() const override;
    bool isValidMove(int startX, int startY, int endX, int endY) const override;
};

#endif // KING_H
