#include "redcar.h"

#include"sprite.h"

RedCar::RedCar(const sf::Vector2f &position):Sprite(position)
{
    loadTexture(texturePath);
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




void RedCar::Lvl(sf::RenderWindow&wind)
{
    std::abs(speed.x+=100);

}


void RedCar::Start()
{
    std::abs(speed.x=100);
}


