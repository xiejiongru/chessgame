#include "knight.h"

Knight::Knight() {}

std::string Knight::getName() const {
    return "N";  // 马在国际象棋中常用 "N" 表示
}

bool Knight::isValidMove(int startX, int startY, int endX, int endY) const {
    // 马的规则：移动是 "L" 型，行差2列差1 或 行差1列差2
    int dx = std::abs(startX - endX);
    int dy = std::abs(startY - endY);
    return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
}
