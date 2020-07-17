#ifndef SCENEELEMENTS_H
#define SCENEELEMENTS_H

#include"sprite.h"

class SceneElements:public sf::Sprite
{
protected:
    sf::Text livesCounter;
    sf::Text lvl;
    sf::Text description;
    sf::Texture texture;
    sf::Vector2f speed;
    sf::Sprite roadSprite;
    sf::Sprite sprite;
    sf::Texture back;
    sf::Clock time;
    sf::Texture roadTexture;
    void loadTexture(const std::string &path);
public:
    explicit SceneElements(sf::RenderWindow&wind ,const std::string &path,const int& posX,const int& posY,const int & rectY ,const bool & check,const int &x);
    virtual void Render(sf::RenderWindow&wind)=0;
    virtual void RenderInfo(sf::RenderWindow&wind)=0;
    virtual void Draw(sf::RenderWindow&wind,sf::Sprite&obj);
    void RestartTime();


};

#endif // SCENEELEMENTS_H
