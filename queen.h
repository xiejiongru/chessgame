#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen : public Piece {
public:
    Queen();
    std::string getName() const override;
    bool isValidMove(int startX, int startY, int endX, int endY) const override;
};

#endif // QUEEN_H
