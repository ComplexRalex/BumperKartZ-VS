#include "Text.hpp"

int Text::width = 0;
int Text::height = 0;

// Code from rbellek's repo:
// https://github.com/rbellek/simpledrawtext/blob/master/simpledrawtext.h
void Text::draw(std::string text, void* font, int x, int y, float r, float g, float b)
{
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0,width,0,height,0,1);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glColor3f(r,g,b);
    glRasterPos2i(x,y);
    for (const char c: text)
        glutBitmapCharacter(font,(int)c);
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}

void Text::setDisplaySize(int w, int h)
{
    width = w; height = h;
}