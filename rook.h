#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public Piece {
public:
    Rook(float x, float y, bool isWhite);
    void render() override;  // 渲染车
};

#endif // ROOK_H
