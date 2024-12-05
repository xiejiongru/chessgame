#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public Piece {
public:
    Bishop();
    std::string getName() const override;
    bool isValidMove(int startX, int startY, int endX, int endY) const override;
};

#endif // BISHOP_H
