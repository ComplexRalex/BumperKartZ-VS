#ifndef CAMERA_HPP
#define CAMERA_HPP
#define PI_ 3.14159f

#include <math.h>
#include <GL/glut.h>
#include "../util/Utilities.hpp"


class Camera
{
    private:
        float eyeX, eyeY, eyeZ;
        float centerX, centerY, centerZ;
        float dirX, dirY, dirZ;
        float upX, upY, upZ;
        float s_magnitude, r_magnitude;
        float theta;

        void updateCenter();
        void specialUpdateCenter();
    public:
        Camera(float, float, float, float, float, float, float, float, float, float, float);
        Camera();
        ~Camera();

        void set(float, float, float, float, float, float, float, float, float);
        void setEyeX(float);
        void setEyeY(float);
        void setEyeZ(float);//I don't really think we'll use methods for the Y axis
        void setEye(float, float, float);
        void setCenterX(float);
        void setCenterY(float);
        void setCenterZ(float);
        void setCenter(float, float, float);
        void setDirX(float);
        void setDirY(float);
        void setDirZ(float);
        void setDir(float, float, float);
        void setStepMagnitude(float);
        void setRotMagnitude(float);

        float getEyeX();
        float getEyeY();
        float getEyeZ();
        float getCenterX();
        float getCenterY();
        float getCenterZ();
        float getDirX();
        float getDirY();
        float getDirZ();
        float getStepMagnitude();
        float getRotMagnitude();

        void moveForward();
        void moveBackward();
        void moveRight();
        void moveLeft();
        void display();
};

#endif // CAMERA_HPP
