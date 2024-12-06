#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public Piece {
public:
    Rook(float x, float y, bool isWhite): Piece(x, y, isWhite) {};
    void render() override;  // 渲染车
    bool isValidMove(float newX, float newY) override {
        // 车只能走横、竖方向
        return (newX == x || newY == y);
    }
};

#endif // ROOK_H
