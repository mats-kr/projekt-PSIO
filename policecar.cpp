#include "policecar.h"
#include"sprite.h"

PoliceCar::PoliceCar(const sf::Vector2f &position):Sprite(position)
{
    loadTexture(texturePath);
}

void PoliceCar::Start()
{
    std::abs(speed.x=200);

}

void PoliceCar::Lvl(sf::RenderWindow &wind)
{
    std::abs(speed.x+=150);

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
