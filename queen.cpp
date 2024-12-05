#include "queen.h"

Queen::Queen() {}

std::string Queen::getName() const {
    return "Q";
}

bool Queen::isValidMove(int startX, int startY, int endX, int endY) const {
    // 后的规则：水平、垂直或斜着移动
    return (startX == endX || startY == endY || 
            std::abs(startX - endX) == std::abs(startY - endY));
}
