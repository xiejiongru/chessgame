#include "game.h"
#include "model_loader.h"
#include <string>

// 游戏初始化
void Game::initialize() {
    // 初始化棋盘和棋子
    for (int i = 0; i < 8; i++) {
        board[i][1] = new Pawn(i, 1, true); // 白色兵
        board[i][6] = new Pawn(i, 6, false); // 黑色兵
    }

    // 初始化白色主力棋子
    loadPieceModel("pawn", true);  // 载入白色兵的模型
    loadPieceModel("rook", true);  // 载入白色车的模型
    loadPieceModel("knight", true);  // 载入白色马的模型
    loadPieceModel("bishop", true);  // 载入白色象的模型
    loadPieceModel("queen", true);  // 载入白色后的模型
    loadPieceModel("king", true);  // 载入白色后的模型

    // 初始化黑色主力棋子
    loadPieceModel("pawn", false);  // 载入黑色兵的模型
    loadPieceModel("rook", false);  // 载入黑色车的模型
    loadPieceModel("knight", false);  // 载入黑色马的模型
    loadPieceModel("bishop", false);  // 载入黑色象的模型
    loadPieceModel("queen", false);  // 载入黑色后的模型
    loadPieceModel("king", false);  // 载入黑色后的模型
}

void Game::loadPieceModel(const std::string& pieceName, bool isWhite) {
    std::string color = isWhite ? "white" : "black";
    std::string filePath = "obj/" + color + "_" + pieceName + ".obj"; // 拼接文件路径
    ModelLoader::loadModel(filePath);  // 加载模型
}

void Game::draw() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j]) {
                board[i][j]->render();
            }
        }
    }
}
