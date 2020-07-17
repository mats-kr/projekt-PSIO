#include "redcar.h"

RedCar::RedCar(const sf::Vector2f &position,const int&ac,const int&start):Vehicle(position,ac,start)
{
    LoadTexture(texturePath);
}
void RedCar::Animate(const sf::Time &elapsed)
{
    move(-speed.x*elapsed.asSeconds(),0);
    sf::FloatRect rectangle_bounds = getGlobalBounds();
    if(rectangle_bounds.left <=-100.0)
    {
          setPosition(std::rand()%300+900,getPosition().y);
    }
}


