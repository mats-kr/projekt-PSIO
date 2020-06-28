#include "pojazd.h"
#include"sprite.h"

Pojazd::Pojazd(const sf::Vector2f &position):sprite(position)
{
    loadTexture(texturePath);
}




void Pojazd::Animate()
{

    move(speed.x,0);
    sf::FloatRect rectangle_bounds = getGlobalBounds();

    if(rectangle_bounds.left+rectangle_bounds.width >= 900.0)
    {
        setPosition(-(std::rand()%400+0),getPosition().y);
        std::cout<<getPosition().x<<std::endl;

    }

}
void Pojazd::lvl(sf::RenderWindow&wind)
{

    std::abs(speed.x++);
    std::cout<<speed.x<<" gora"<<std::endl;
}
void Pojazd::lvl2()
{

}




void Pojazd::New_Position()//sf::RenderWindow&wind)
{









}
