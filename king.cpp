#include "king.h"

King::King() {}

std::string King::getName() const {
    return "K";
}

bool King::isValidMove(int startX, int startY, int endX, int endY) const {
    // 王的规则：每次移动一格，可以水平、垂直或对角线
    int dx = std::abs(startX - endX);
    int dy = std::abs(startY - endY);
    return (dx <= 1 && dy <= 1);
}
