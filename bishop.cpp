#include "bishop.h"

Bishop::Bishop() {}

std::string Bishop::getName() const {
    return "B";
}

bool Bishop::isValidMove(int startX, int startY, int endX, int endY) const {
    // 象的规则：斜着移动，且行列差相同
    return std::abs(startX - endX) == std::abs(startY - endY);
}
