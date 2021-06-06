#ifndef MENUSCENE_HPP_INCLUDED
#define MENUSCENE_HPP_INCLUDED

#include <GL/glut.h>
#include <iostream>

#include "SkyBox.hpp"
#include "Camera.hpp"
#include "Model.hpp"
#include "Ground.hpp"
#include "Billboard.hpp"

class MenuScene
{
	private:
		SkyBox sky;
		Billboard ad;
		Camera cam;
		ModelX demo;
		Ground ground;
	public:
		MenuScene();
		~MenuScene();

		void draw();
};

#endif // MENUSCENE_HPP_INCLUDED