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

#include "util/Menu.hpp"
#include "src/Scene.hpp"
#include "src/MenuScene.hpp"

#define WIDTH 720
#define HEIGHT 480

#define O_X 100
#define O_Y 100

#define SELECT_MENU 'S'
#define PLAY_MENU 'P'
#define HOW_TO_MENU 'H'
#define CREDITS_MENU 'C'

#define VER std::string("1.0.0")

using namespace std;

bool fullscreen;
bool playing;

int c_width, c_height;
int w_width, w_height;

int FPS = 60;

Scene escena;
MenuScene escenaMenu;

Menu select("Select an option"), play("Play"), howto("How to play"), credits("Credits");
Menu *current;

void initMenus()
{
    // Selection menu
    select.addOption(new Option("Play", GLUT_BITMAP_HELVETICA_18, true));
    select.addOption(new Option("How to play", GLUT_BITMAP_HELVETICA_18, true));
    select.addOption(new Option("Credits", GLUT_BITMAP_HELVETICA_18, true));
    select.addOption(new Option(" ", GLUT_BITMAP_HELVETICA_18, false));
    select.addOption(new Option("Quit", GLUT_BITMAP_HELVETICA_18, true));
    select.setGap(22);
    select.setSelectedColor(1.0f,0.5f,0.0f);

    // Play menu
    play.addOption(new Option("Singleplayer", GLUT_BITMAP_HELVETICA_18, true));
    play.addOption(new Option("Local multiplayer (2P)", GLUT_BITMAP_HELVETICA_18, true));
    play.addOption(new Option(" ", GLUT_BITMAP_HELVETICA_18, false));
    play.addOption(new Option("Return", GLUT_BITMAP_HELVETICA_18, true));
    play.setSelected(0);
    play.setGap(22);
    play.setSelectedColor(1.0f, 0.5f, 0.0f);

    // How to play menu
    howto.addOption(new Option(" > Menu controls", GLUT_BITMAP_9_BY_15, false));
    howto.addOption(new Option(" Move up: W - Move down: S - Select: <SPACE>", GLUT_BITMAP_8_BY_13, false));
    howto.addOption(new Option(" > Special keys", GLUT_BITMAP_9_BY_15, false));
    howto.addOption(new Option(" Fullscreen: F11 - Default size: F2 - Default position: F3 - Quick exit: F4", GLUT_BITMAP_8_BY_13, false));
    howto.addOption(new Option("  ", GLUT_BITMAP_9_BY_15, false));
    howto.addOption(new Option(" > In-game controls", GLUT_BITMAP_9_BY_15, false));
    howto.addOption(new Option(" Return to menu: <ESCAPE>", GLUT_BITMAP_8_BY_13, false));
    howto.addOption(new Option(" > Player 1 controls", GLUT_BITMAP_9_BY_15, false));
    howto.addOption(new Option(" Go forward: W - Go backward: S - Turn right: D - Turn left: A", GLUT_BITMAP_8_BY_13, false));
    howto.addOption(new Option(" > Player 2 controls", GLUT_BITMAP_9_BY_15, false));
    howto.addOption(new Option(" Go forward: I - Go backward: K - Turn right: L - Turn left: J", GLUT_BITMAP_8_BY_13, false));
    howto.addOption(new Option("  ", GLUT_BITMAP_9_BY_15, false));
    howto.addOption(new Option("Return", GLUT_BITMAP_HELVETICA_18, true));
    howto.setGap(18);
    howto.setSelected(12);
    howto.lockSelected(true);
    howto.setSelectedColor(1.0f, 0.5f, 0.0f);

    // Credits menu
    credits.addOption(new Option("  > Game designed by", GLUT_BITMAP_9_BY_15, false));
    credits.addOption(new Option("  * MrAlexbross/ComplexRalex * DannyMannn * Mokkuman *", GLUT_BITMAP_HELVETICA_12, false));
    credits.addOption(new Option("  ", GLUT_BITMAP_HELVETICA_12, false));
    credits.addOption(new Option("  > Continued by", GLUT_BITMAP_9_BY_15, false));
    credits.addOption(new Option("  * MrAlexbross/ComplexRalex *", GLUT_BITMAP_HELVETICA_12, false));
    credits.addOption(new Option("  ", GLUT_BITMAP_HELVETICA_12, false));
    credits.addOption(new Option("  I love you Bichi <3", GLUT_BITMAP_9_BY_15, true));
    credits.addOption(new Option("  ", GLUT_BITMAP_HELVETICA_12, false));
    credits.addOption(new Option("Return", GLUT_BITMAP_HELVETICA_18, true));
    credits.setGap(22);
    credits.setSelected(8);
    credits.setSelectedColor(1.0f, 0.5f, 0.0f);
}

void init()
{
    glPolygonMode(GL_FRONT, GL_FILL);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);

    escena.init();
    initMenus();

    glutIgnoreKeyRepeat(true);

    c_width = w_width = WIDTH;
    c_height = w_height = HEIGHT;

    fullscreen = playing = false;
    current = &select;
}

void resize(int width, int height)
{
    if (!fullscreen)
    {
        w_width = width;
        w_height = height;
    }

    c_width = width;
    c_height = height;
    escena.setSize(width,height);
}

void displayMenu()
{
    glViewport(0, 0, c_width, c_height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(FOVY, (float)c_width/c_height, ZNEAR, ZFAR);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    escenaMenu.draw();
    Text::setDisplaySize(c_width, c_height);
    Text::draw("ComplexRalex and 3D-Masters 2021",GLUT_BITMAP_8_BY_13,5,5,1.0f,1.0f,1.0f);
    Text::draw("Ver: "+VER,GLUT_BITMAP_8_BY_13,5,c_height-18,1.0f,1.0f,1.0f);

    current->display(50, 290, c_width, c_height);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();

    if(!playing)
        displayMenu();
    else
        escena.display();

    glPopMatrix();

    glutSwapBuffers();
}

void handleMenuInputs(unsigned char key)
{
    switch (key)
    {
        case 'w': case 'W':
            current->moveUp();
            break;
        case 's': case 'S':
            current->moveDown();
            break;
        case ' ':
            if (current == &select)
            {
                switch (current->getSelected())
                {
                    case 0:
                        current = &play;
                        break;
                    case 1:
                        current = &howto;
                        break;
                    case 2:
                        current = &credits;
                        break;
                    case 4:
                        exit(0);
                        break;
                }
            }
            else if (current == &play)
            {
                switch (current->getSelected())
                {
                    case 0:
                        escena.setSinglePlayer(true);
                        playing = true;
                        break;
                    case 1:
                        escena.setSinglePlayer(false);
                        playing = true;
                        break;
                    case 3:
                        current = &select;
                        break;
                }
            }
            else if (current == &howto)
            {
                switch (current->getSelected())
                {
                    case 12:
                        current = &select;
                        break;
                }
            }
            else if (current == &credits)
            {
                switch (current->getSelected())
                {
                    case 8:
                        current = &select;
                        break;
                }
            }
            break;
    }
}

void KeyboardInput(unsigned char key, int x, int y)
{
    if (!playing)
        handleMenuInputs(key);
    else
        switch (key)
        {
            case 27: playing = false; break;
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
        case GLUT_KEY_F4:
            exit(0);
            break;
        case GLUT_KEY_F11:
            if (fullscreen)
                glutReshapeWindow(w_width, w_height);
            else
                glutFullScreen();
            fullscreen = !fullscreen;
            break;
    }
}

void SpecialUpInput(int key, int x, int y)
{
    return;
}

void limitFPS(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/FPS,limitFPS,0);
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
    glutKeyboardFunc(KeyboardInput);
    glutKeyboardUpFunc(KeyboardUpInput);
    glutSpecialFunc(SpecialInput);
    glutSpecialUpFunc(SpecialUpInput);

    limitFPS(0);
    glutMainLoop();

    return 0;
}
