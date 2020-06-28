#include "pojazd2.h"

#include"sprite.h"

Pojazd2::Pojazd2(const sf::Vector2f &position):sprite(position)
{
    loadTexture(texturePath);
}
void Pojazd2::Animate()
{

    move(speed.x,0);
    sf::FloatRect rectangle_bounds = getGlobalBounds();
    if(rectangle_bounds.left <=0.0)
    {
          setPosition(std::rand()%300+900,getPosition().y);
          //std::cout<<getPosition().x<<std::endl;
    }


}




void Pojazd2::lvl(sf::RenderWindow&wind)
{

}
void Pojazd2::lvl2()
{
    std::abs(speed.x--);
    std::cout<<speed.x<<" gora"<<std::endl;
}

void Pojazd2::New_Position()//const int &w)
{

}
