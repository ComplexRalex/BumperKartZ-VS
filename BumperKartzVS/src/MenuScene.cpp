#include "MenuScene.hpp"

MenuScene::MenuScene():
	cam(0, 2.0f, 0, 0, -0.15, -1, 0, 1, 0, 0.75f, 1.5f)
{
	sky.set(cam.getCenterX(), cam.getCenterY(), cam.getCenterZ());
}

MenuScene::~MenuScene(){}

void MenuScene::draw()
{
	glPushMatrix();

	cam.display();
	sky.draw();
	ground.draw();

	glPushMatrix();
	glTranslatef(-0.8f,0.0f,-4.0f);
	glRotatef(48.0f,0.0f,1.0f,0.0f);
	demo.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.8f,0.0f,-5.0f);
	glRotatef(-25.0f,0.0f,1.0f,0.0f);
	ad.draw();
	glPopMatrix();

	glPopMatrix();
}