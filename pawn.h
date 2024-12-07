#ifndef PAWN_H
#define PAWN_H

#include "piece.h"
#include <GL/glut.h>

class Pawn : public Piece {

public:
    Pawn(float x, float y, bool isWhite) : Piece(x, y, isWhite) {}

    virtual void render() override;  // 重写渲染方法
    virtual bool isValidMove(float newX, float newY) override;
};

#endif
