#include <GL/glew.h>    // 必须在glut之前
#include <GL/freeglut.h>
#include "game.h"  // 引入 Game 类
#include "render.h"  // 引入 render.h

Game game;  // 创建全局 Game 对象
Render render;  // 创建渲染对象

// 用于显示的回调函数
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    render.drawChessBoard();  // 使用 Render 绘制棋盘
    render.renderPieces(game.getPieces());  // 渲染所有棋子

    glutSwapBuffers();
}

// 主程序入口
int main(int argc, char** argv) {
    // 初始化 OpenGL
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Chess Game");

    // 初始化 GLEW
    glewInit();

    // 初始化 GLEW，确保所有扩展都已正确加载
    if (glewInit() != GLEW_OK) {
        std::cerr << "GLEW Initialization failed!" << std::endl;
        return -1;
    }

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // 背景颜色
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 9.0, -1.0, 9.0);  // 设置投影

    // 初始化游戏（棋盘和棋子）
    game.initialize();

    // 初始化渲染
    render.initialize();

    // 设置绘制回调函数
    glutDisplayFunc(display);  // 每次渲染时调用 display 函数
    glutMainLoop();  // 启动渲染循环

    return 0;
}
