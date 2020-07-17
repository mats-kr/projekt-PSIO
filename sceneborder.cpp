#include "sceneborder.h"

SceneBorder::SceneBorder(sf::RenderWindow&wind ,const std::string &path,const int& posX,const int& posY,
                         const int & rectY ,const bool & check,const int &x)
                                                                                    :SceneElements(wind,path,posX,posY,rectY,check,x)
{
    loadTexture(path);
    texture.loadFromFile(path);
    texture.setRepeated(check);
    sprite.setPosition(sf::Vector2f(posX,wind.getSize().y-posY));
    sprite.setTextureRect(sf::IntRect(0, 0, wind.getSize().x-x,rectY));
    sprite.setTexture(texture);
}
void SceneBorder::Render(sf::RenderWindow &wind)
{
    Draw(wind,sprite);
}
void SceneBorder::RenderInfo(sf::RenderWindow &wind)
{

}
