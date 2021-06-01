#include "Camera.hpp"

Camera::Camera( float eyeX, float eyeY, float eyeZ,
                float dirX, float dirY, float dirZ,
                float upX, float upY, float upZ,
                float step, float rots)
{
    set(eyeX,eyeY,eyeZ,dirX,dirY,dirZ,upX,upY,upZ);
    s_magnitude = step;
    r_magnitude = rots;
}

Camera::Camera()
{
    set(0.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f,1.0f,0.0f);
    s_magnitude = r_magnitude = 1.0f;
}

Camera::~Camera(){}

//intuitive formula as seen in class
void Camera::updateCenter()
{
    centerX = eyeX + dirX;
    centerY = eyeY + dirY;
    centerZ = eyeZ + dirZ;
}

void Camera::specialUpdateCenter()
{
    float rads = Util::degToRad(theta);
    //std::cout << theta << std::endl;

    //Directions must be included just in case one of them is (-1)
    dirX = cos(rads);
    dirZ = sin(rads);
    centerX = eyeX + dirX;
    centerZ = eyeZ + dirZ;
}

void Camera::set(float eyeX, float eyeY, float eyeZ,
                 float dirX, float dirY, float dirZ,
                 float upX, float upY, float upZ)
{
    this->eyeX = eyeX; this->eyeY = eyeY; this->eyeZ = eyeZ;
    this->dirX = dirX; this->dirY = dirY; this->dirZ = dirZ;
    centerX = eyeX + dirX; centerY = eyeY + dirY; centerZ = eyeZ + dirZ;
    this->upX = upX; this->upY = upY; this->upZ = upZ;

    theta = Util::getAngle(dirX,dirZ);
    //std::cout << theta << std::endl;
}

/*
I think that the center has to update every time we
update the eye, but just for the specified axis.
*/
void Camera::setEyeX(float eyeX)
{
    this->eyeX = eyeX;
    centerX = eyeX + dirX;
}

void Camera::setEyeY(float eyeY)
{
    this->eyeY = eyeY;
    centerY = eyeY + dirY;
}

void Camera::setEyeZ(float eyeZ)
{
    this->eyeZ = eyeZ;
    centerY = eyeZ + dirZ;
}

void Camera::setEye(float eyeX, float eyeY, float eyeZ)
{
    this->eyeX = eyeX; this->eyeY = eyeY; this->eyeZ = eyeZ;
    updateCenter();
}

/*
If the direction is updated, then the center must also be updated to make
it look like we're heading towards that specific direction. I think that
the center must only be updated to the specified axis.
*/
void Camera::setDirX(float dirX)
{
    this->dirX = dirX;
    centerX = eyeX + dirX;
}

void Camera::setDirY(float dirY)
{
    this->dirY = dirY;
    centerY = eyeY + dirY;
}

void Camera::setDirZ(float dirZ)
{
    this->dirZ = dirZ;
    centerZ = eyeZ + dirZ;
}

void Camera::setDir(float dirX, float dirY, float dirZ)
{
    this->dirX = dirX; this->dirY = dirY; this->dirZ = dirZ;
    updateCenter();
}

void Camera::setStepMagnitude(float m)
{
    s_magnitude = m;
}

void Camera::setRotMagnitude(float m)
{
    r_magnitude = m;
}

float Camera::getEyeX(){return eyeX;}
float Camera::getEyeY(){return eyeY;}
float Camera::getEyeZ(){return eyeZ;}

float Camera::getCenterX(){return centerX;}
float Camera::getCenterY(){return centerY;}
float Camera::getCenterZ(){return centerZ;}

float Camera::getDirX(){return dirX;}
float Camera::getDirY(){return dirY;}
float Camera::getDirZ(){return dirZ;}

float Camera::getStepMagnitude(){return s_magnitude;}
float Camera::getRotMagnitude(){return r_magnitude;}

void Camera::moveForward()
{
    eyeX += (s_magnitude * dirX);
    eyeY += (s_magnitude * dirY);
    eyeZ += (s_magnitude * dirZ);
    updateCenter();
}

void Camera::moveBackward()
{
    eyeX -= (s_magnitude * dirX);
    eyeY -= (s_magnitude * dirY);
    eyeZ -= (s_magnitude * dirZ);
    updateCenter();
}

void Camera::moveLeft()
{
    theta -= r_magnitude;
    //std::cout << theta << std::endl;
    theta = (theta < 0.0f) ? theta+360.0f : theta;
    specialUpdateCenter();
}

void Camera::moveRight()
{
    theta += r_magnitude;
    //std::cout << theta << std::endl;
    theta = (theta >= 360.0f) ? theta-360.0f : theta;
    specialUpdateCenter();
}

void Camera::display()
{
    gluLookAt(eyeX,eyeY,eyeZ,centerX,centerY,centerZ,upX,upY,upZ);
}
