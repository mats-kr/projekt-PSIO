#include "sprite.h"
#include <SFML/Audio.hpp>


Sprite::Sprite(const sf::Vector2f &position)
{
    setPosition(position);
}


void Sprite::TimeReset()
{
        time.restart();;
}


void Sprite::loadTexture(const std::string &path)
{
    texture.loadFromFile(path);
    setTexture(texture);
}
bool Sprite::ObjectCollision(const sf::Sprite &object,const sf::RenderWindow&wind)
{
    return getGlobalBounds().intersects(object.getGlobalBounds());
}


void Sprite::SetSpeed(const int &speed_x, const int &speed_y)
{
    speed.x= speed_x;
    speed.y = speed_y;
}
void Sprite::SetBounds(const int &left, const int &right, const int &top, const int &bottom)
{
    left_bound = left;
    right_bound = right;
    top_bound = top;
    bottom_bound = bottom;
}
sf::FloatRect Sprite::Give_Bounds()
{
    sf::FloatRect bound = getGlobalBounds();
    return bound;
}
