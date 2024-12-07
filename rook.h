#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public Piece {
public:
    Rook(float x, float y, bool isWhite);  // 声明构造函数
    void render() override;  // 渲染车
    bool isValidMove(float newX, float newY) override;  // 只声明，不定义
};

#endif // ROOK_H
