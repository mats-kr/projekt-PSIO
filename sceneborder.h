#ifndef SCENEBORDER_H
#define SCENEBORDER_H

#include"sceneelements.h"
class SceneBorder:public SceneElements
{
public:
    SceneBorder(sf::RenderWindow&wind ,const std::string &path,const int& posX,const int& posY,const int & rectY ,const bool & check,const int &x);
    void Render(sf::RenderWindow&wind)final;
    void RenderInfo(sf::RenderWindow&wind)final;
};

#endif // SCENEBORDER_H
