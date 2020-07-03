#include "dhlcar.h"
#include"sprite.h"

DhlCar::DhlCar(const sf::Vector2f &position):Sprite(position)
{
    loadTexture(texturePath);
}

void DhlCar::Start()
{
    std::abs(speed.x=200);

}

void DhlCar::Lvl(sf::RenderWindow &wind)
{
    std::abs(speed.x+=150);

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
