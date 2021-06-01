#ifndef WALL_HPP_INCLUDED
#define WALL_HPP_INCLUDED

#include "GL/glut.h"
#include "Texture.hpp"
#include "../util/Utilities.hpp"
#include <cmath>

#define WALL_RES 32
#define WALL_HEIGHT 6.5f
#define WALL_RAD 50.0f
#define WALL_TIMES 3

class Wall
{
    private:
        float x,y,z;
        float points[WALL_RES][2];

        char* texFilename;
        Texture tex;
    public:
        Wall();
        ~Wall();

        float getX();
        float getY();
        float getZ();
        float getRadious();

        void draw();
};

#endif // WALL_HPP_INCLUDED
