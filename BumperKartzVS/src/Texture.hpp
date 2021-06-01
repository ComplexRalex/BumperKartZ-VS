#ifndef TEXTURE_HPP_INCLUDED
#define TEXTURE_HPP_INCLUDED

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>
#include "../util/RgbImage.hpp"
/*SE CREA UN OBJETO TEXTURA PARA CADA FIGURA */
class Texture{
    private:
        RgbImage* rgbImage;
        const void* image;
        long width, height;
        GLuint texture;
    public:
        Texture();
        ~Texture();
        void loadTexture(std::string);    //carga las texturas
        void bind();
        void unbind();
};

#endif // TEXTURE_HPP_INCLUDED
