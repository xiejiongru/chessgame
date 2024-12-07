#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include <iostream>
#include <string>
#include <memory>

class Piece {
protected:
    float x, y;  // 棋子的位置
    float size;  // 棋子大小
    bool isWhite; // 是否为白色棋子
    float colorR, colorG, colorB;  // 棋子颜色
    std::string type;       // 棋子类型（如 "Pawn"、"Rook"）



public:
    Piece(float x, float y, bool isWhite)
        : x(x), y(y), isWhite(isWhite), size(0.5f), colorR(1.0f), colorG(1.0f), colorB(1.0f) {}

    virtual ~Piece() {}

    virtual void render() = 0;    // 渲染棋子
    virtual bool isValidMove(float newX, float newY) = 0; // 骨架方法，具体规则由子类实现
    static std::vector<std::unique_ptr<Piece>> pieces;  // 将 pieces 设为静态成员

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

    
    std::string getType() const { return type; }          // 获取棋子类型
    bool isWhitePiece() const { return isWhite; }         // 判断棋子颜色
    
    // 输出棋子信息
    void printInfo() const {
        std::cout << "Piece: " << type << " at (" << x << ", " << y << "), Color: " 
                  << (isWhite ? "White" : "Black") << std::endl;}
};


#endif
