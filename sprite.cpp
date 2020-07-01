#include "sprite.h"
#include <SFML/Audio.hpp>


sprite::sprite(const sf::Vector2f &position)
{
    setPosition(position);
}
void sprite::Size(int x, int y)
{
    // setSize(sf::Vector2f(x,y));
}

void sprite::time_r()
{
        time.restart();;
}
void sprite::Color(sf::Color (col))
{
    setColor(col);
}


void sprite::loadTexture(const std::string &path)
{
    texture.loadFromFile(path);
    setTexture(texture);
}
bool sprite::ObjectCollision(const sf::Sprite &object,const sf::RenderWindow&wind)
{
    return getGlobalBounds().intersects(object.getGlobalBounds());
}

void sprite::Theme()
{


}
void sprite::Set_Speed(const int &speed_x, const int &speed_y)
{
    speed.x= speed_x;
    speed.y = speed_y;
}
void sprite::Set_Bounds(const int &left, const int &right, const int &top, const int &bottom)
{
    left_bound = left;
    right_bound = right;
    top_bound = top;
    bottom_bound = bottom;
}
sf::FloatRect sprite::Give_Bounds()
{
    sf::FloatRect bound = getGlobalBounds();
    return bound;
}
