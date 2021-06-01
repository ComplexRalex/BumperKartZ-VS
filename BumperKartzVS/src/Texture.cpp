#include "Texture.hpp"

Texture::Texture(){}

Texture::~Texture()
{
    rgbImage->Reset();
    delete rgbImage;
}

void Texture::loadTexture(std::string filename)
{
    rgbImage = new RgbImage(filename.c_str());

    image = rgbImage->ImageData();
    width = rgbImage->GetNumCols();
    height = rgbImage->GetNumRows();
}

void Texture::bind()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glShadeModel(GL_FLAT);

    glGenTextures(1,&texture);
    glBindTexture(GL_TEXTURE_2D,texture);

    //controla texture wrapping
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//textura no exacta al tmn del objeto
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, image);
}

void Texture::unbind()
{
    glBindTexture(GL_TEXTURE_2D,0);
    glDeleteTextures(1,&texture);
}