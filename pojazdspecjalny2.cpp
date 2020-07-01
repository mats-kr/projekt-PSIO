#include "pojazdspecjalny2.h"
#include"sprite.h"

pojazdspecjalny2::pojazdspecjalny2(const sf::Vector2f &position):sprite(position)
{
    loadTexture(texturePath);
}

void pojazdspecjalny2::Start()
{

}

void pojazdspecjalny2::lvl(sf::RenderWindow &wind)
{
    std::abs(speed.x+=2);

}

void pojazdspecjalny2::lvl2()
{

}

void pojazdspecjalny2::tex()
{

}

void pojazdspecjalny2::New_Position()//const int &w)
{

}





void pojazdspecjalny2::Animate()
{

    move(-speed.x,0);
    sf::FloatRect rectangle_bounds = getGlobalBounds();


        if(rectangle_bounds.left <=-100.0)
        {
              setPosition(std::rand()%300+900,std::rand()%350+550);
              //std::cout<<getPosition().x<<std::endl;
        }




}
