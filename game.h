#ifndef GAME_H
#define GAME_H

#include "piece.h"
#include <vector>
#include <memory>

class Game {
private:
    std::unique_ptr<Piece> board[8][8];  // 使用智能指针
    bool currentPlayer;  // 当前玩家（true = 白色, false = 黑色）

public:
    Game();               // 构造函数
    ~Game();              // 析构函数，释放内存
    void initialize();    // 初始化棋局
    void layoutPieces();  // 添加声明
    bool movePiece(int fromX, int fromY, int toX, int toY);     // 移动棋子
    void draw();          // 绘制棋盘
    void processInput();  // 处理用户输入
    bool isGameOver();    // 判断游戏是否结束
    bool isInCheck(bool whitePlayer); // 检查是否被将军
    void drawChessBoard();  // 绘制棋盘
    void renderPieces();    // 渲染所有棋子

    const std::vector<std::unique_ptr<Piece>>& getPieces() const; // 获取所有棋子的引用
};

#endif
