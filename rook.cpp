#include "rook.h"

Rook::Rook() {}

std::string Rook::getName() const {
    return "R";
}

bool Rook::isValidMove(int startX, int startY, int endX, int endY) const {
    // 车的规则：水平或垂直移动任意步
    return (startX == endX || startY == endY);
}
