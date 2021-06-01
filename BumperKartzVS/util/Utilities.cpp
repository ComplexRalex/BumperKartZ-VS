#include "Utilities.hpp"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

float Util::degToRad(float degrees)
{
      return (float)((degrees*M_PI)/180.0f);
}

float Util::radToDeg(float radians)
{
      return (float)(radians*180.0/M_PI);
}

float Util::getAngle(float dirX, float dirZ)
{
    float theta;

    if(dirX != 0.0f)
    {
        if(dirX > 0.0f && dirZ >= 0.0f)                 // Cuadrante 1
            theta = radToDeg(atan(dirZ/dirX));
        else if(dirX < 0.0f)                            // Cuadrante 2 & 3
            theta = 180.0f+radToDeg(atan(dirZ/dirX));
        else if(dirX > 0.0f && dirZ < 0.0f)             // Cuadrante 4
            theta = 360.0f+radToDeg(atan(dirZ/dirX));
    }
    else
    {
        theta = (dirZ >= 0.0f ? 90.0f : 270.0f);
    }

    return theta;
}

float Util::pointDistance(float x1, float y1, float z1, float x2, float y2, float z2)
{
    float x = (x2 - x1), y = (y2 - y1), z = (z2 - z1);
    return std::sqrt((x * x) + (y * y) + (z * z));
}

float Util::QuakeInverseSqrt(float number)
{
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	y  = number;
	i  = * ( long * ) &y;                       // evil floating point bit level hacking
	i  = 0x5f3759df - ( i >> 1 );               // what the fuck?
	y  = * ( float * ) &i;
	y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
//	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

	return y;
}
