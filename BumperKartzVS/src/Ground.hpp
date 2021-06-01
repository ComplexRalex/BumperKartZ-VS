#ifndef GROUND_HPP_INCLUDED
#define GROUND_HPP_INCLUDED

#include "GL/glut.h"
#include "Texture.hpp"

#define FLOOR_RAD 50.0f
#define FLOOR_REPEAT 5

class Ground
{
    private:
        float x,y,z;
        float points[4][2];

        char* texFilename;
        Texture tex;
    public:
        Ground();
        ~Ground();

        float getX();
        float getY();
        float getZ();
        float getRadious();

        void draw();
};

#endif // GROUND_HPP_INCLUDED
