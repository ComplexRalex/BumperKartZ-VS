#ifndef KART_HPP_INCLUDED
#define KART_HPP_INCLUDED

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <chrono>

#include "GL/glut.h"
#include "../util/Utilities.hpp"
#include "Texture.hpp"

#define TEXTURE_LIMIT 4

class Kart
{
    protected:
        static std::chrono::steady_clock::time_point start;
        static int ID;
        int MyID;

        float radious;
        float mass;

        float posX,posY,posZ;   // pos = position
        float dirX,dirY,dirZ;   // dir = direction
        float velX,     velZ;   // vel = velocity
        float accX,     accZ;   // acc = acceleration
        float direction;        // angle of direction
        float s_magnitude;      // step magnitude
        float r_magnitude;      // rotation magnitude

        Texture texUp, texDown;
        virtual void initTextures() = 0;    // this must be initialized inside derived classes

        void drawUp();
        void drawBase();
        void drawBottom();

        void updateDirectionAngle();
        void updateDirection();
    public:
        Kart(float,float,float,float,float,float,float,float);
        Kart();
        ~Kart();

        int getID();
        static void setTimer(std::chrono::steady_clock::time_point);
        float getRadious();
        void setRadious(float);
        float getMass();
        void setMass(float);
        void setPositionPoint(float,float,float);
        void setPosX(float);
        void setPosY(float);
        void setPosZ(float);
        float getPosX();
        float getPosY();
        float getPosZ();
        void setDirectionVector(float,float,float);
        void setDirX(float);
        void setDirY(float);
        void setDirZ(float);
        float getDirX();
        float getDirY();
        float getDirZ();
        void setVelocity(float,float);
        void setVelX(float);
        void setVelZ(float);
        float getVelX();
        float getVelZ();
        void setAcceleration(float,float);
        void setAccX(float);
        void setAccZ(float);
        float getAccX();
        float getAccZ();
        void setStepMagnitude(float);
        float getStepMagnitude();
        void setRotMagnitude(float);
        float getRotMagnitude();
        float getDirection();

        virtual void draw();                // Función específica para dibujarlo
        virtual void accelerateForward();   // Función especial para mover al objeto
        virtual void accelerateBackward();  // Función especial para mover al objeto
        virtual void moveRight();           // Función especial para mover al objeto
        virtual void moveLeft();            // Función especial para mover al objeto
        virtual void attack(Kart*,int);    // Función que ataca al objetivo

        // Maybe some "actions", for instante, "explode" or something XD
};

#endif // KART_HPP_INCLUDED
