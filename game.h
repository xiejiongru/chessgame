#ifndef GAME_H
#define GAME_H

#include "piece.h"
#include <vector>
#include <memory>
#include <cstdlib> // 用于随机数生成
#include <ctime>   // 用于设置随机数种子

class Game {
private:
    std::unique_ptr<Piece> board[8][8];  // 使用智能指针
    bool currentPlayer;  // 当前玩家（true = 白色, false = 黑色）
    std::vector<std::pair<int, int>> getValidMoves(int x, int y);  // 获取指定棋子的所有合法移动位置

public:
    Game();               // 构造函数
    ~Game();              // 析构函数，释放内存
    void initialize();    // 初始化棋局
    bool movePiece(int fromX, int fromY, int toX, int toY);     // 移动棋子
    void draw();          // 绘制棋盘
    void processInput();  // 处理用户输入
    bool isGameOver();    // 判断游戏是否结束
    bool isInCheck(bool whitePlayer); // 检查是否被将军
    void renderPieces();    // 渲染所有棋子
    void makeRandomMove();  // 让当前玩家的一个棋子随机移动
};

#endif
