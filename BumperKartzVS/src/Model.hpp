#ifndef MODEL_HPP_INCLUDED
#define MODEL_HPP_INCLUDED

#include "Kart.hpp"
#include "Texture.hpp"

class ModelX: public Kart
{
    private:
        void initTextures();
    public:
        ModelX();
        ~ModelX();
};
class ModelY: public Kart
{
    private:
        void initTextures();
    public:
        ModelY();
        ~ModelY();
};

#endif // MODEL_HPP_INCLUDED
