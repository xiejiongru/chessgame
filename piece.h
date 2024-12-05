#ifndef PIECE_H
#define PIECE_H

class Piece {
protected:
    float x, y;  // 棋子的位置
    float size;  // 棋子大小
    bool isWhite; // 是否为白色棋子
    float colorR, colorG, colorB;  // 棋子颜色

public:
    // 构造函数初始化列表正确使用冒号
    Piece(float x, float y, bool isWhite)
        : x(x), y(y), isWhite(isWhite), size(0.5f), colorR(1.0f), colorG(1.0f), colorB(1.0f) {}

    // 渲染棋子
    virtual void render() = 0;

    // 设置位置
    virtual void setPosition(float x, float y) {
        this->x = x;
        this->y = y;
    }

    // 设置大小
    void setSize(float size) { this->size = size; }

    // 设置颜色
    void setColor(float r, float g, float b) {
        colorR = r;
        colorG = g;
        colorB = b;
    }

    // 获取位置
    float getX() const { return x; }
    float getY() const { return y; }

    // 析构函数
    virtual ~Piece() {}
};

#endif
