#include "pojazdspecjalny.h"
#include"sprite.h"

pojazdspecjalny::pojazdspecjalny(const sf::Vector2f &position):sprite(position)
{
    setPosition(position);
}

void pojazdspecjalny::New_Position()//const int &w)
{

}





void pojazdspecjalny::Animate()
{

    move(speed.x,0);
    sf::FloatRect rectangle_bounds = getGlobalBounds();
    if(rectangle_bounds.left <=0.0)
    {
      //  setPosition(800.0,getPosition().y);
    }
    if(rectangle_bounds.left+rectangle_bounds.width >= 900.0)
    {
        setPosition(0.0,getPosition().y);

    }

}
