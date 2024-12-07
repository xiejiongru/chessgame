#ifndef RENDER_H
#define RENDER_H

#include "shader.h"
#include "piece.h"
#include <vector>

class Render {
public:
    Render();
    void initialize();
    void drawChessBoard();
    void renderPieces(const std::vector<std::unique_ptr<Piece>>& pieces);
private:
    Shader* shader;
    GLuint VAO, VBO;
};

#endif
