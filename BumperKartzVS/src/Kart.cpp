#include "Kart.hpp"
#include <iostream>

int Kart::ID = 0;
std::chrono::steady_clock::time_point Kart::start = std::chrono::steady_clock::now();

Kart::Kart(float x, float y, float z, float dx, float dy, float dz, float step, float rot)
{
    MyID = ID++;

    radious = 1.0f;
    mass = 10.0f;

    posX = x;   posY = y;   posZ = z;
    dirX = dx;  dirY = dy;  dirZ = dz;
    velX = 0.0f; velZ = 0.0f;
    accX = 0.0f; accZ = 0.0f;
    s_magnitude = step;
    r_magnitude = rot;

    updateDirectionAngle();
}

Kart::Kart()
{
    MyID = ID++;

    radious = 1.0f;
    mass = 10.0f;

    posX = posZ = 0;
    posY = 0.5;
    dirX = dirY = 0; dirZ = 1;
    velX = 0.0f; velZ = 0.0f;
    accX = 0.0f; accZ = 0.0f;
    s_magnitude = 1.0f;
    r_magnitude = 2.8f;

    updateDirectionAngle();
}

Kart::~Kart(){}

void Kart::drawUp()
{
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_QUADS);

    //front
        glNormal3f(0.0f,0.0f,1.0f);

        glTexCoord2f(0.0f,0.0f);
        glVertex3f(-0.5f,0.15f,1.0f);

        glTexCoord2f(1.0f,0.0f);
        glVertex3f(0.5f,0.15f,1.0f);

        glTexCoord2f(1.0f,1.0f);
        glVertex3f(0.3f,0.45f,0.7f);

        glTexCoord2f(0.0f,1.0f);
        glVertex3f(-0.3f,0.45f,0.7f);

    //Left
        glNormal3f(1.0f,0.0f,0.0f);

        glTexCoord2f(0.0f,0.0f);
        glVertex3f(0.5f,0.15f,1.0f);

        glTexCoord2f(1.0f,0.0f);
        glVertex3f(0.5f,0.15f,-1.0f);

        glTexCoord2f(1.0f,1.0f);
        glVertex3f(0.3f,0.45f,-0.7f);

        glTexCoord2f(0.0f,1.0f);
        glVertex3f(0.3f,0.45f,0.7f);
    //Right
        glNormal3f(-1.0f,0.0f,0.0f);

        glTexCoord2f(0.0,0.0);
        glVertex3f(-0.5f,0.15f,-1.0f);

        glTexCoord2f(1.0f,0.0f);
        glVertex3f(-0.5f,0.15f,1.0f);

        glTexCoord2f(1.0f,1.0f);
        glVertex3f(-0.3f,0.45f,0.7f);

        glTexCoord2f(0.0f,1.0f);
        glVertex3f(-0.3f,0.45f,-0.7f);

    //back
        glNormal3f(0.0f,0.0f,-1.0f);

        glTexCoord2f(0.0f,0.0f);
        glVertex3f(0.5f,0.15f,-1.0);

        glTexCoord2f(1.0f,0.0f);
        glVertex3f(-0.5f,0.15f,-1.0f);

        glTexCoord2f(1.0f,1.0f);
        glVertex3f(-0.3f,0.45f,-0.7f);

        glTexCoord2f(0.0f,1.0f);
        glVertex3f(0.3f,0.45f,-0.7f);

    //top
        glNormal3f(0.0f,1.0f,0.0f);

        glTexCoord2f(0.0f,0.0f);
        glVertex3f(-0.3f,0.45f,0.7f);

        glTexCoord2f(1.0f,0.0f);
        glVertex3f(0.3f,0.45f,0.7f);

        glTexCoord2f(1.0f,1.0f);
        glVertex3f(0.3f,0.45f,-0.7f);

        glTexCoord2f(0.0f,1.0f);
        glVertex3f(-0.3f,0.45f,-0.7f);
    glEnd();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}

void Kart::drawBase()
{
    //Activando las texturas
    glEnable(GL_TEXTURE_2D);

    glPushMatrix();
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_QUADS);

    //front
        glNormal3f(0.0f, 0.0f, 1.0f);

        glTexCoord2f(0.5f,1.0f);
        glVertex3f(-0.5f, -0.15f, 1.0f);

        glTexCoord2f(0.75f,1.0f);
        glVertex3f(0.5f, -0.15f, 1.0f);

        glTexCoord2f(0.75f,0.0f);
        glVertex3f(0.5f, 0.15f, 1.0f);

        glTexCoord2f(0.5f,0.0f);
        glVertex3f(-0.5f, 0.15f, 1.0f);

	//Left
        glNormal3f(1.0f, 0.0f, 0.0f);

        glTexCoord2f(0.75f,0.0f);
        glVertex3f(0.5f, -0.15f, 1.0f);

        glTexCoord2f(1.0f,0.0f);
        glVertex3f(0.5f, -0.15f, -1.0f);

        glTexCoord2f(1.0f,1.0f);
        glVertex3f(0.5f, 0.15f, -1.0f);

        glTexCoord2f(0.75f,1.0f);
        glVertex3f(0.5f, 0.15f, 1.0f);

	//Back
        glNormal3f(-1.0f, 0.0f, 0.0f);

        glTexCoord2f(0.0f,0.0f);
        glVertex3f(0.5f, -0.15f, -1.0f);

        glTexCoord2f(0.25f,0.0f);
        glVertex3f(-0.5f, -0.15f, -1.0f);

        glTexCoord2f(0.25f,1.0f);
        glVertex3f(-0.5f, 0.15f, -1.0f);

        glTexCoord2f(0.0f,1.0f);
        glVertex3f(0.5f, 0.15f, -1.0f);

	//Right
        glNormal3f(0.0f, 0.0f, -1.0f);

        glTexCoord2f(0.5f,1.0f);
        glVertex3f(-0.5f, 0.15f, 1.0f);

        glTexCoord2f(0.25f,1.0f);
        glVertex3f(-0.5f, 0.15f, -1.0f);

        glTexCoord2f(0.25f,0.0f);
        glVertex3f(-0.5f, -0.15f, -1.0f);

        glTexCoord2f(0.5f,0.0f);
        glVertex3f(-0.5f, -0.15f, 1.0f);
	glEnd();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

}

void Kart::drawBottom()
{
    glPushMatrix();
    glColor3f(1.0f,1.0f,1.0f);
    glShadeModel(GL_SMOOTH);
    glBegin(GL_QUADS);
    //front
        glNormal3f(0.0f,0.0f,1.0f);
        //up
        glColor3f(0.4f,0.4f,0.4f);
        glVertex3f(-0.5f,-0.15f,1.0f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex3f(-0.5f,-0.20f,1.5f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex3f(0.5f,-0.20f,1.5f);
        glColor3f(0.4f,0.4f,0.4f);
        glVertex3f(0.5f,-0.15f,1.0f);
        //middle
        glColor3f(0.8f,0.8f,0.8f);
        glVertex3f(-0.5f,-0.20f,1.5f);
        glVertex3f(-0.5f,-0.25f,1.5f);
        glVertex3f(0.5f,-0.25f,1.5f);
        glVertex3f(0.5f,-0.20f,1.5f);
        //down
        glVertex3f(-0.5f,-0.25f,1.5f);
        glVertex3f(-0.5f,-0.30f,1.0f);
        glVertex3f(0.5f,-0.30f,1.0f);
        glVertex3f(0.5f,-0.25f,1.5f);
    //back
        glNormal3f(0.0f,0.0f,-1.0f);
        //up
        glColor3f(0.4f,0.4f,0.4f);
        glVertex3f(0.5f,-0.15f,-1.0f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex3f(0.5f,-0.20f,-1.5f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex3f(-0.5f,-0.20f,-1.5f);
        glColor3f(0.4f,0.4f,0.4f);
        glVertex3f(-0.5f,-0.15f,-1.0f);
        //middle
        glColor3f(0.8f,0.8f,0.8f);
        glVertex3f(0.5f,-0.20f,-1.5f);
        glVertex3f(0.5f,-0.25f,-1.5f);
        glVertex3f(-0.5f,-0.25f,-1.5f);
        glVertex3f(-0.5f,-0.20f,-1.5f);
        //down
        glVertex3f(0.5f,-0.25f,-1.5f);
        glVertex3f(0.5f,-0.30f,-1.0f);
        glVertex3f(-0.5f,-0.30f,-1.0f);
        glVertex3f(-0.5f,-0.25f,-1.5f);
    //Left

        glNormal3f(1.0f,0.0f,0.0f);
        //up
        glColor3f(0.4f,0.4f,0.4f);
        glVertex3f(0.5f,-0.15f,1.0f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex3f(0.5f,-0.20f,1.5f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex3f(0.5f,-0.20f,-1.5f);
        glColor3f(0.4f,0.4f,0.4f);
        glVertex3f(0.5f,-0.15f,-1.0f);
        //middle
        glColor3f(0.8f,0.8f,0.8f);
        glVertex3f(0.5f,-0.20f,1.5f);
        glVertex3f(0.5f,-0.25f,1.5f);
        glVertex3f(0.5f,-0.25f,-1.5f);
        glVertex3f(0.5f,-0.20f,-1.5f);
        //down
        glVertex3f(0.5f,-0.25f,1.5f);
        glVertex3f(0.5f,-0.30f,1.0f);
        glVertex3f(0.5f,-0.30f,-1.0f);
        glVertex3f(0.5f,-0.25f,-1.5f);

    //Right
        glNormal3f(-1.0f,0.0f,0.0f);
        //up
        glColor3f(0.4f,0.4f,0.4f);
        glVertex3f(-0.5f,-0.15f,-1.0f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex3f(-0.5f,-0.20f,-1.5f);
        glColor3f(0.8f,0.8f,0.8f);
        glVertex3f(-0.5f,-0.20f,1.5f);
        glColor3f(0.4f,0.4f,0.4f);
        glVertex3f(-0.5f,-0.15f,1.0f);
        //middle
        glColor3f(0.8f,0.8f,0.8f);
        glVertex3f(-0.5f,-0.20f,-1.5f);
        glVertex3f(-0.5f,-0.25f,-1.5f);
        glVertex3f(-0.5f,-0.25f,1.5f);
        glVertex3f(-0.5f,-0.20f,1.5f);
        //down
        glVertex3f(-0.5f,-0.25f,-1.5f);
        glVertex3f(-0.5f,-0.30f,-1.0f);
        glVertex3f(-0.5f,-0.30f,1.0f);
        glVertex3f(-0.5f,-0.25f,1.5f);
    glEnd();
    glShadeModel(GL_FLAT);
    glPopMatrix();
}

void Kart::setTimer(std::chrono::steady_clock::time_point str)
{
    Kart::start = str;
}

int Kart::getID(){return MyID;}

float Kart::getRadious(){return radious;}
void Kart::setRadious(float r){radious = r;}
float Kart::getMass(){return mass;}
void Kart::setMass(float m){mass = m;}

void Kart::setPositionPoint(float x, float y, float z)
{
    posX = x;   posY = y;   posZ = z;
}
void Kart::setPosX(float x){posX = x;}
void Kart::setPosY(float y){posY = y;}
void Kart::setPosZ(float z){posZ = z;}
float Kart::getPosX(){return posX;}
float Kart::getPosY(){return posY;}
float Kart::getPosZ(){return posZ;}
void Kart::setDirectionVector(float dx, float dy, float dz)
{
    dirX = dx;  dirY = dy;  dirZ = dz;
    updateDirectionAngle();
    updateDirection();
}
void Kart::setDirX(float dx){dirX = dx; updateDirectionAngle(); updateDirection();}
void Kart::setDirY(float dy){dirY = dy; updateDirectionAngle(); updateDirection();}
void Kart::setDirZ(float dz){dirZ = dz; updateDirectionAngle(); updateDirection();}
float Kart::getDirX(){return dirX;}
float Kart::getDirY(){return dirY;}
float Kart::getDirZ(){return dirZ;}
void Kart::setVelocity(float vx, float vz)
{
    velX = vx;  velZ = vz;
}
void Kart::setVelX(float vx){velX = vx;}
void Kart::setVelZ(float vz){velZ = vz;}
float Kart::getVelX(){return velX;}
float Kart::getVelZ(){return velZ;}
void Kart::setAcceleration(float ax, float az)
{
    accX = ax;  accZ = az;
}
void Kart::setAccX(float ax){accX = ax;}
void Kart::setAccZ(float az){accZ = az;}
float Kart::getAccX(){return accX;}
float Kart::getAccZ(){return accZ;}
void Kart::setStepMagnitude(float m){s_magnitude = m;}
float Kart::getStepMagnitude(){return s_magnitude;}
void Kart::setRotMagnitude(float m){r_magnitude = m;}
float Kart::getRotMagnitude(){return r_magnitude;}
float Kart::getDirection(){return direction;}

void Kart::accelerateForward()
{
    accX = 0.1f * s_magnitude * dirX;
    accZ = 0.1f * s_magnitude * dirZ;
}

void Kart::accelerateBackward()
{
    accX = - 0.1f * s_magnitude * dirX;
    accZ = - 0.1f * s_magnitude * dirZ;
}

void Kart::moveRight()
{
    direction += r_magnitude;
    direction = (direction >= 360.0f) ? direction-360.0f : direction;
    updateDirection();
}

void Kart::moveLeft()
{
    direction -= r_magnitude;
    direction = (direction < 0.0f) ? direction+360.0f : direction;
    updateDirection();
}

void Kart::attack(Kart *target, int seconds)
{
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    int elapsed_time = int(std::chrono::duration_cast <std::chrono::seconds>(end - Kart::start).count());

    //nuevo vector de direccionamiento para enemigo
    float vecX = target->getPosX() - posX;
    float vecZ = target->getPosZ() - posZ;

    //normalizacion del vector
    float hyp = std::sqrt((vecX * vecX) + (vecZ * vecZ));
    vecX /= hyp;
    vecZ /= hyp;

    //actualizando posicion del enemigo
    setDirectionVector(vecX,dirY,vecZ);

    //acelarcion cada "seconds" segundos durante 1 segundo
    if(elapsed_time % seconds == 0)
        accelerateForward();
}

void Kart::updateDirection()
{
    float rads = Util::degToRad(direction);

    //std::cout << direction << std::endl;

    dirX = cos(rads);
    dirZ = sin(rads);
}

void Kart::updateDirectionAngle()
{
    direction = Util::getAngle(dirX,dirZ);
}

void Kart::draw()
{
    glPushMatrix();

    // Estas funciones permiten posicionar al Kart en su lugar
    glTranslatef(posX,posY,posZ);
    glRotatef(direction-90,0,-1,0);

    texDown.bind();    // Textura de la base
    drawBase();
    texDown.unbind();

    texUp.bind();    // Textura de la parte superior
    drawUp();
    texUp.unbind();

    drawBottom();

    glPopMatrix();
}
