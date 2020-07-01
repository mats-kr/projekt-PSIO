#include "pojazdspecjalny.h"
#include"sprite.h"

pojazdspecjalny::pojazdspecjalny(const sf::Vector2f &position):sprite(position)
{
    loadTexture(texturePath);
}

void pojazdspecjalny::Start()
{

}

void pojazdspecjalny::lvl(sf::RenderWindow &wind)
{
    std::abs(speed.x+=2);

}

void pojazdspecjalny::lvl2()
{

}

void pojazdspecjalny::tex()
{

}

void pojazdspecjalny::New_Position()//const int &w)
{

}





void pojazdspecjalny::Animate()
{

    move(speed.x,0);
    sf::FloatRect rectangle_bounds = getGlobalBounds();

    if(rectangle_bounds.left+rectangle_bounds.width >= 1000.0)
    {
        setPosition(-(std::rand()%600+0),std::rand()%300+100);
//        setPosition(-(std::rand()%400+0),getPosition().y);


    }

}
