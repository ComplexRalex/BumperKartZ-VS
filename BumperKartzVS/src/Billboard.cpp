#include "Billboard.hpp"

Billboard::Billboard()
{
	x = y = z = 0.0f;

	tex.loadTexture("res/billboard.bmp");

	for (int i = 0; i < 8; i++)
	{
		tube[i][0] = (float)TUBE_RAD*cos(Util::degToRad((float)(-45*i)));
		tube[i][1] = (float)TUBE_RAD*sin(Util::degToRad((float)(-45*i)));
		//std::cout << tube[i][0] << " " << tube[i][1] << std::endl;
	}

	latitude[0][0] = RECT_WIDTH / 2 + RECT_OUTLINE;		latitude[0][1] = - RECT_DEPTH / 2;
	latitude[1][0] = - RECT_WIDTH / 2 - RECT_OUTLINE;	latitude[1][1] = - RECT_DEPTH / 2;
	latitude[2][0] = - RECT_WIDTH / 2 - RECT_OUTLINE;	latitude[2][1] = RECT_DEPTH / 2;
	latitude[3][0] = RECT_WIDTH / 2 + RECT_OUTLINE;		latitude[3][1] = RECT_DEPTH / 2;

	longitude[0][0] = RECT_OUTLINE / 2;		longitude[0][1] = - RECT_DEPTH / 2;
	longitude[1][0] = - RECT_OUTLINE / 2;	longitude[1][1] = - RECT_DEPTH / 2;
	longitude[2][0] = - RECT_OUTLINE / 2;	longitude[2][1] = RECT_DEPTH / 2;
	longitude[3][0] = RECT_OUTLINE / 2;		longitude[3][1] = RECT_DEPTH / 2;

	rect[0][0] = - RECT_WIDTH / 2;	rect[0][1] = RECT_DEPTH / 2 - RECT_IN_DEPTH;
	rect[1][0] = RECT_WIDTH / 2;	rect[1][1] = RECT_DEPTH / 2 - RECT_IN_DEPTH;
	rect[2][0] = RECT_WIDTH / 2;	rect[2][1] = - RECT_DEPTH / 2;
	rect[3][0] = - RECT_WIDTH / 2;	rect[3][1] = - RECT_DEPTH / 2;
}

Billboard::~Billboard(){}

float Billboard::getX() { return x; }
float Billboard::getY() { return y; }
float Billboard::getZ() { return z; }

void Billboard::drawTube()
{
	glPushMatrix();

	glShadeModel(GL_SMOOTH);
	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i <= 8; i++)
	{
		glColor3f(0.3f, 0.3f, 0.3f);
		glVertex3f(tube[i % 8][0], TUBE_HEIGHT, tube[i % 8][1]);
		glColor3f(0.6f, 0.6f, 0.6f);
		glVertex3f(tube[i % 8][0], 0, tube[i % 8][1]);
	}
	glEnd();
	glShadeModel(GL_FLAT);
	
	glPopMatrix();
}

void Billboard::drawLatBorder(float r, float g, float b)
{
	glPushMatrix();

	glColor3f(r,g,b);
	glBegin(GL_QUAD_STRIP);
		for(int i = 0; i <= 4; i++)
		{
			glVertex3f(latitude[i % 4][0], RECT_OUTLINE, latitude[i % 4][1]);
			glVertex3f(latitude[i % 4][0], 0, latitude[i % 4][1]);
		}
	glEnd();
	
	glBegin(GL_QUADS);
		for (int i = 0; i < 4; i++)
			glVertex3f(latitude[i][0], RECT_OUTLINE, latitude[i][1]);
		for (int i = 3; i >= 0; i--)
			glVertex3f(latitude[i][0], 0, latitude[i][1]);
	glEnd();
	
	glPopMatrix();
}

void Billboard::drawLongBorder(float r1, float g1, float b1, float r2, float g2, float b2)
{
	glPushMatrix();

	glShadeModel(GL_SMOOTH);
	glBegin(GL_QUAD_STRIP);
		for(int i = 0; i <= 4; i++)
		{
			glColor3f(r1,g1,b1);
			glVertex3f(longitude[i % 4][0], RECT_HEIGHT, longitude[i % 4][1]);
			glColor3f(r2,g2,b2);
			glVertex3f(longitude[i % 4][0], 0, longitude[i % 4][1]);
		}
	glEnd();
	glShadeModel(GL_FLAT);
	
	glPopMatrix();
}

void Billboard::drawCenter()
{
	glPushMatrix();

	tex.bind();
	glEnable(GL_TEXTURE_2D);
	glColor3f(1.0f, 1.0f, 1.0f);
	
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f,1.0f);
		glVertex3f(rect[0][0], RECT_HEIGHT, rect[0][1]);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(rect[0][0], 0, rect[0][1]);
		glTexCoord2f(1.0f,0.0f);
		glVertex3f(rect[1][0], 0, rect[1][1]);
		glTexCoord2f(1.0f,1.0f);
		glVertex3f(rect[1][0], RECT_HEIGHT, rect[1][1]);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	tex.unbind();

	glColor3f(0.1f,0.1f,0.1f);
	glBegin(GL_QUADS);
		glVertex3f(rect[2][0], RECT_HEIGHT, rect[2][1]);
		glVertex3f(rect[2][0], 0, rect[2][1]);
		glVertex3f(rect[3][0], 0, rect[3][1]);
		glVertex3f(rect[3][0], RECT_HEIGHT, rect[3][1]);
	glEnd();

	glPopMatrix();
}

void Billboard::draw()
{
	glPushMatrix();
	glTranslatef(x,y,z);
	
	glPushMatrix();
	glTranslatef(1.5f, 0.0f, 0.0f);
	drawTube();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.5f, 0.0f, 0.0f);
	drawTube();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, TUBE_HEIGHT, 0.0f);
	drawLatBorder(0.3f, 0.3f, 0.3f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, TUBE_HEIGHT + RECT_OUTLINE + RECT_HEIGHT, 0.0f);
	drawLatBorder(0.2f, 0.2f, 0.2f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(RECT_OUTLINE / 2 + RECT_WIDTH / 2, TUBE_HEIGHT + RECT_OUTLINE, 0.0f);
	drawLongBorder(0.2f, 0.2f, 0.2f, 0.3f, 0.3f, 0.3f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(- RECT_OUTLINE / 2 - RECT_WIDTH / 2, TUBE_HEIGHT + RECT_OUTLINE, 0.0f);
	drawLongBorder(0.2f, 0.2f, 0.2f, 0.3f, 0.3f, 0.3f);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0.0f, TUBE_HEIGHT + RECT_OUTLINE, 0.0f);
	drawCenter();
	glPopMatrix();

	glPopMatrix();
}