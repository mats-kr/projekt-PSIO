#ifndef SCENELABELS_H
#define SCENELABELS_H

#include"sceneelements.h"

class SceneLabels:public SceneElements
{
private:
    sf::Text text3;
    sf::Font font;
    void LoadFont();
public:
    explicit SceneLabels(sf::RenderWindow&wind ,const std::string &path,const int& posX,sf::Color(fillcolor)
                         ,const int& posY,const int & rectY ,const bool & check,const int &x);;
    void DisplayInstructions(sf::RenderWindow&wind);
    void MoveInfo(sf::RenderWindow&wind);
    void DrawObject(sf::RenderWindow &wind, sf::Text &tex);
    void RenderInfo(sf::RenderWindow &wind) final;
    void RestartTime();
    void Render(sf::RenderWindow &wind) final;

};

#endif // SCENELABELS_H
