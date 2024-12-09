#include "chessboard.h"
#include <GL/glew.h>
#include <GL/glut.h>
#include "game.h"

// 全局变量
Game game;
Chessboard chessboard;

// 显示回调
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    chessboard.render();   // 渲染 3D 棋盘
    game.renderPieces();   // 渲染棋子

    glutSwapBuffers();
}

// 初始化 OpenGL
void initOpenGL() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
}

// 主程序入口
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutCreateWindow("3D Chess");

    glewInit();  // 初始化 GLEW
    initOpenGL();

    chessboard.load();     // 加载棋盘
    game.initialize();     // 初始化游戏

    glutDisplayFunc(display);
    glutKeyboardFunc([](unsigned char key, int x, int y) {
        if (key == ' ') {
            game.makeRandomMove();
            glutPostRedisplay();
        }
    });

    glutMainLoop();
    return 0;
}
