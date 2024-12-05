#ifndef PAWN_H
#define PAWN_H

#include "piece.h"
#include <GL/glut.h>

class Pawn : public Piece {
    bool isWhite;  // 是否是白色棋子

public:
    Pawn(float x, float y, bool isWhite);

    void render() override;  // 重写渲染方法
};

#endif
