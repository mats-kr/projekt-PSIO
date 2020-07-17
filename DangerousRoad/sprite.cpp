#include "sprite.h"
#include <SFML/Audio.hpp>

Sprite::Sprite(const sf::Vector2f &position)
{
    setPosition(position);
}
void Sprite::TimeReset()
{
        time.restart();
}
void Sprite::LoadTexture(const std::string &path)
{
    texture.loadFromFile(path);
    setTexture(texture);
}
bool Sprite::ObjectCollision(const sf::Sprite &object,const sf::RenderWindow&wind)
{
    return getGlobalBounds().intersects(object.getGlobalBounds());
}
void Sprite::SetBounds(const int &left, const int &right, const int &top, const int &bottom)
{
    leftBound = left;
    rightBound = right;
    topBound = top;
    bottomBound = bottom;
}
sf::FloatRect Sprite::GiveBounds()
{
    sf::FloatRect bound = getGlobalBounds();
    return bound;
}
void Sprite::Movesound()
{
    if (!mov.loadFromFile("move.wav"))
    {
        std::cout<<"!!!!!!!!"<<std::endl;
    }
    moveSound.setBuffer(mov);
    moveSound.play();
}
void Sprite::Hitsound()
{
    if (!ht.loadFromFile("hit.wav"))
    {
        std::cout<<"!!!!!!!!"<<std::endl;
    }
    hitSound.setBuffer(ht);
    hitSound.play();
}
void Sprite::Nextlvlsound()
{
    if (!nextlvl.loadFromFile("lvl.wav"))
    {
        std::cout<<"!!!!!!!!"<<std::endl;
    }
    nextlvlSound.setBuffer(nextlvl);
    nextlvlSound.play();
}
