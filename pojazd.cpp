#include "pojazd.h"
#include"sprite.h"

Pojazd::Pojazd(const sf::Vector2f &position):sprite(position)
{
    setPosition(position);
}


void Pojazd::lvl()
{

    std::abs(speed.x++);
    std::cout<<speed.x<<" gora"<<std::endl;
}
void Pojazd::lvl2()
{

    std::abs(speed.x--);
    std::cout<<speed.x<<" dol"<<std::endl;
}
void Pojazd::Start()
{
    if(event.type==sf::Keyboard::isKeyPressed(sf::Keyboard::P))
    {
        speed.x--;
    }
}
void Pojazd::Animate()
{

    move(speed.x,0);
    sf::FloatRect rectangle_bounds = getGlobalBounds();
    if(rectangle_bounds.left <=0.0)
    {
        setPosition(800.0,getPosition().y);
    }
    if(rectangle_bounds.left+rectangle_bounds.width >= 900.0)
    {
        setPosition(0.0,getPosition().y);

    }

}
