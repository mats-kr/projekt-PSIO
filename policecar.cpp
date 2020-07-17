#include "policecar.h"

PoliceCar::PoliceCar(const sf::Vector2f &position,const int&ac,const int&start):Vehicle(position,ac,start)
{
    LoadTexture(texturePath);
}
void PoliceCar::Animate(const sf::Time &elapsed)
{
    move(speed.x*elapsed.asSeconds(),0);
    sf::FloatRect rectangle_bounds = getGlobalBounds();
    if(rectangle_bounds.left+rectangle_bounds.width >= 1000.0)
    {
        setPosition(-(std::rand()%600+0),std::rand()%300+100);
    }
}


