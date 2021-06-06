#ifndef BILLBOARD_HPP_INCLUDED
#define BILLBOARD_HPP_INCLUDED

#include <GL/glut.h>
#include <iostream>
#include <cmath>
#include "Texture.hpp"
#include "../util/Utilities.hpp"

#define TUBE_HEIGHT 0.8f
#define TUBE_RAD 0.2f

#define RECT_HEIGHT 2.0f
#define RECT_WIDTH 4.0f
#define RECT_DEPTH 1.0f
#define RECT_IN_DEPTH 0.2f
#define RECT_OUTLINE 0.1f

class Billboard
{
	private:
		float x, y, z;
		float tube[8][2];
		float latitude[4][2];
		float longitude[4][2];
		float rect[4][2];

		Texture tex;

		void drawTube();
		void drawLongBorder(float,float,float,float,float,float);
		void drawLatBorder(float,float,float);
		void drawCenter();
	public:
		Billboard();
		~Billboard();

		float getX();
		float getY();
		float getZ();
		
		void draw();
};

#endif // BILLBOARD_HPP_INCLUDED