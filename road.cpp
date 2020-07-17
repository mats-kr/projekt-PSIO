#include "road.h"

Road::Road(sf::RenderWindow&wind ,const std::string &path,const int& posX,const int& posY,const int & rectY ,const bool & check,const int &x)
    :SceneElements(wind,path,posX,posY,rectY,check,x)
{
    roadTexture.loadFromFile(path);
    roadTexture.setRepeated(check);
    roadSprite.setTexture(roadTexture);
    roadSprite.setTextureRect(sf::IntRect(0, 3, wind.getSize().x-x,rectY));
}
void Road::Render(sf::RenderWindow &wind)
{
    Draw(wind,roadSprite);
}
void Road::RenderInfo(sf::RenderWindow &wind)
{

}
