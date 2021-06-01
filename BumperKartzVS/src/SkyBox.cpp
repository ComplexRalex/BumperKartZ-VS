#include "SkyBox.hpp"

SkyBox::SkyBox()
{
    x = z = 0;
    y = 1;

    tex.loadTexture("res/space.bmp");

    points[0][0] =  SKYBOX_RAD; points[0][1] =  SKYBOX_RAD;
    points[1][0] = -SKYBOX_RAD; points[1][1] =  SKYBOX_RAD;
    points[2][0] = -SKYBOX_RAD; points[2][1] = -SKYBOX_RAD;
    points[3][0] =  SKYBOX_RAD; points[3][1] = -SKYBOX_RAD;
}

SkyBox::~SkyBox(){}

void SkyBox::set(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

float SkyBox::getX(){return x;}
float SkyBox::getY(){return y;}
float SkyBox::getZ(){return z;}
float SkyBox::getRadious(){ return SKYBOX_RAD; }

void SkyBox::draw()
{
    tex.bind();

    glDepthMask(GL_FALSE);
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();

    glTranslatef(x,y,z);
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_QUAD_STRIP);
        for(int i = 0; i < 5; i++)
        {
            glTexCoord2f(0.0f+i,0.0f);
            glVertex3f(points[i%4][0],SKYBOX_HEIGHT,points[i%4][1]);
            glTexCoord2f(0.0f+i,1.0f);
            glVertex3f(points[i%4][0],            0,points[i%4][1]);
        }
    glEnd();

    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glDepthMask(GL_TRUE);

    tex.unbind();
}
