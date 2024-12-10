#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include <iostream>
#include <string>
#include <memory>

class Piece {
protected:
    float x, y;  
    float size;  
    bool isWhite;
    float colorR, colorG, colorB; 
    std::string type; 



public:
    Piece(float x, float y, bool isWhite)
        : x(x), y(y), isWhite(isWhite), size(0.5f), colorR(1.0f), colorG(1.0f), colorB(1.0f) {}

    virtual ~Piece() {}

    virtual void render() = 0;    
    virtual bool isValidMove(float newX, float newY) = 0; 
    static std::vector<std::unique_ptr<Piece>> pieces;  

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

    
    std::string getType() const { return type; }       
    bool isWhitePiece() const { return isWhite; }     
    
    void printInfo() const {
        std::cout << "Piece: " << type << " at (" << x << ", " << y << "), Color: " 
                  << (isWhite ? "White" : "Black") << std::endl;}
};


#endif
