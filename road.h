#ifndef ROAD_H
#define ROAD_H

#include"sceneelements.h"

class Road:public SceneElements
{
public:
    explicit Road(sf::RenderWindow&wind ,const std::string &path,const int& posX,const int& posY,const int & rectY ,const bool & check,const int &x);
    void Render(sf::RenderWindow&wind)final;
    void RenderInfo(sf::RenderWindow&wind)final;
};

#endif // ROAD_H
