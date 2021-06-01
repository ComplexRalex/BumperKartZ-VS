#ifndef UTILITIES_HPP_INCLUDED
#define UTILITIES_HPP_INCLUDED

#include <cmath>

class Util
{
    public:
        static float degToRad(float);
        static float radToDeg(float);
        static float getAngle(float,float);
        static float pointDistance(float, float, float, float, float ,float);
        static float QuakeInverseSqrt(float);
};

#endif // UTILITIES_HPP_INCLUDED
