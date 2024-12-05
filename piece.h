#ifndef PIECE_H
#define PIECE_H

class Piece {
protected:
    float x, y;  // 棋子的位置
    float size;  // 棋子大小
    float colorR, colorG, colorB;  // 棋子颜色

public:
    Piece(float x, float y) : x(x), y(y), size(0.4f), colorR(0.0f), colorG(0.0f), colorB(0.0f) {}

    virtual void render() = 0;  // 渲染棋子
    virtual void setPosition(float x, float y) {
        this->x = x;
        this->y = y;
    }

    void setSize(float size) { this->size = size; }
    void setColor(float r, float g, float b) {
        colorR = r;
        colorG = g;
        colorB = b;
    }

    float getX() const { return x; }
    float getY() const { return y; }

    virtual ~Piece() {}
};

#endif
