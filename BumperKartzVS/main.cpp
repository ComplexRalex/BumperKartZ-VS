#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <chrono>

#include <cstdlib>

#include "src/Scene.hpp"

#define WIDTH 640
#define HEIGHT 480

#define O_X 100
#define O_Y 100

using namespace std;

bool fullscreen = false;
bool playing = true;

int c_width, c_height;

Scene escena;

void init()
{
    glPolygonMode(GL_FRONT, GL_FILL);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);

    escena.init();

    glutIgnoreKeyRepeat(true);
}

void resize(int width, int height)
{
    if (!fullscreen)
    {
        c_width = width;
        c_height = height;
    }

    escena.setSize(width,height);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();

    //if(!playing)
    //    // something about menu
    //else
        escena.display();

    glPopMatrix();

    glutSwapBuffers();
}

void KeyboardInput(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27: exit(0); break;
        default: escena.inputPressed(key, x, y);
    }
}

void KeyboardUpInput(unsigned char key, int x, int y)
{
    escena.inputReleased(key, x, y);
}

void SpecialInput(int key, int x, int y)
{
    switch (key)
    {
        case GLUT_KEY_F2:
            glutReshapeWindow(WIDTH,HEIGHT);
            break;
        case GLUT_KEY_F3:
            glutPositionWindow(O_X,O_Y);
            break;
        case GLUT_KEY_F11:
            if (fullscreen)
                glutReshapeWindow(c_width, c_height);
            else
                glutFullScreen();
            fullscreen = !fullscreen;
    }
}

void SpecialUpInput(int key, int x, int y)
{
    return;
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(O_X, O_Y);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Bumper KartZ VS");

    init();

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutKeyboardFunc(KeyboardInput);
    glutKeyboardUpFunc(KeyboardUpInput);
    glutSpecialFunc(SpecialInput);
    glutSpecialUpFunc(SpecialUpInput);

    glutMainLoop();

    return 0;
}
