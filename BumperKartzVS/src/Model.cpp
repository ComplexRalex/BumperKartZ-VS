#include "Model.hpp"

ModelX::ModelX():Kart()
{
    initTextures();
}
ModelX::~ModelX(){}

void ModelX::initTextures()
{
    texUp.loadTexture("res/upX.bmp");
    texDown.loadTexture("res/baseX.bmp");
}

//Model Y
ModelY::ModelY():Kart()
{
    initTextures();
}
ModelY::~ModelY(){}

void ModelY::initTextures()
{
    texUp.loadTexture("res/upY.bmp");
    texDown.loadTexture("res/baseY.bmp");
}
