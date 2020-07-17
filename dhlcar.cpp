#include "dhlcar.h"

DhlCar::DhlCar(const sf::Vector2f &position,const int&accelero,const int&start):Vehicle(position,accelero,start)
{
   LoadTexture(texturePath);
   acceleration=accelero;
}
void DhlCar::Animate(const sf::Time &elapsed)
{
    move(-speed.x*elapsed.asSeconds(),0);
    sf::FloatRect rectangle_bounds = getGlobalBounds();
    if(rectangle_bounds.left <=-100.0)
    {
        setPosition(std::rand()%300+900,std::rand()%350+550);
    }
}

