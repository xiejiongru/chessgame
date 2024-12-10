#ifndef PAWN_H
#define PAWN_H

#include "piece.h"
#include <GL/glut.h>

class Pawn : public Piece {

public:
    Pawn(float x, float y, bool isWhite) ;

    void render() override;  
    bool isValidMove(float newX, float newY) override;
};

#endif
