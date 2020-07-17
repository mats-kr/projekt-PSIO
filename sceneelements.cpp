#include "sceneelements.h"

SceneElements::SceneElements(sf::RenderWindow&wind ,const std::string &path,const int& posX,const int& posY,const int & rectY ,const bool & check,const int &x)
{
    loadTexture(path);
}
void SceneElements::Draw(sf::RenderWindow &wind,sf::Sprite&object)
{
    wind.draw(object);
}
void SceneElements::loadTexture(const std::string &path)
{
    texture.loadFromFile(path);
    setTexture(texture);
}
void SceneElements::RestartTime()
{
    time.restart();
}
