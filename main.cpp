#include "game.h"  
#include <GL/glut.h>

Game game;  // Create a game object

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    game.drawChessBoard();  
    game.renderPieces();    

    glutSwapBuffers();
}

    void keyboard(unsigned char key, int x, int y) {
    if (key == ' ') {
        std::cout << "Space key pressed. Making a random move...\n";
        game.makeRandomMove();
        glutPostRedisplay();  
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Chess Game");

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 9.0, -1.0, 9.0);  


    game.initialize();

    glutDisplayFunc(display);  // Display callback for displaying the game
    glutKeyboardFunc([](unsigned char key, int x, int y) {
        if (key == ' ') {
            std::cout << "Space key pressed. Making a move...\n";
            game.makeRandomMove();
            glutPostRedisplay();
        }
    });

    glutKeyboardFunc(keyboard);

    glutMainLoop();  

    return 0;
}

