#ifndef TEXT_HPP_INCLUDED
#define TEXT_HPP_INCLUDED

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>

class Text
{
	private:
		static int width;
		static int height;
	public:
		static void draw(std::string,void*,int,int,float,float,float);
		static void setDisplaySize(int,int);
};

#endif // TEXT_HPP_INCLUDED