#ifndef GAME_H
#define GAME_H

#include "piece.h"
#include <vector>
#include <memory>
#include <cstdlib> // random() use
#include <ctime>   // random seeds

class Game {
private:
    std::unique_ptr<Piece> board[8][8];  // Smart Pointer
    bool currentPlayer;  // Current player(true: white, false: black)
    std::vector<std::pair<int, int>> getValidMoves(int x, int y);  

public:
    Game();               
    ~Game();              
    void initialize();    
    bool movePiece(int fromX, int fromY, int toX, int toY);     
    void draw();          
    void processInput();  
    bool isGameOver();   
    bool isInCheck(bool whitePlayer); 
    void drawChessBoard();  
    void renderPieces();   
    void makeRandomMove();  
};

#endif
