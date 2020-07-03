#include "greencar.h"
#include"sprite.h"

GreenCar::GreenCar(const sf::Vector2f &position):Sprite(position)
{
    loadTexture(texturePath);
}

void GreenCar::Start()
{
    std::abs(speed.x=100);

}




void GreenCar::Animate(const sf::Time &elapsed)
{

    move(speed.x*elapsed.asSeconds(),0);
    sf::FloatRect rectangle_bounds = getGlobalBounds();

    if(rectangle_bounds.left+rectangle_bounds.width >= 1000.0)
    {
        setPosition(-(std::rand()%600+0),getPosition().y);

    }

}
void GreenCar::Lvl(sf::RenderWindow&wind)
{
    std::abs(speed.x+=100);
}








