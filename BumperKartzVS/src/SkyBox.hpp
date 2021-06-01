#ifndef SKYBOX_HPP_INCLUDED
#define SKYBOX_HPP_INCLUDED

#include "GL/glut.h"
#include "Texture.hpp"

#define SKYBOX_RAD 1
#define SKYBOX_HEIGHT 2*SKYBOX_RAD

class SkyBox
{
    private:
        float x,y,z;
        float points[4][2];

        char* texFilename;
        Texture tex;
    public:
        SkyBox();
        ~SkyBox();

        void set(float,float,float);
        float getX();
        float getY();
        float getZ();
        float getRadious();

        void draw();
};

#endif // SKYBOX_HPP_INCLUDED
