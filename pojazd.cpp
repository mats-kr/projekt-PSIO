#include "pojazd.h"

Pojazd::Pojazd(const sf::Vector2f &position)
{
    setPosition(position);
}
void Pojazd::Set_Speed( const int &speed_x,const   int& speed_y)
{
    speed.x= speed_x;
    speed.y = speed_y;
}
void Pojazd::Size(int x, int y)
{
    setSize(sf::Vector2f(x,y));
}
void Pojazd::Color(sf::Color (col))
{
    setFillColor(col);
}
void Pojazd::Set_Bounds(const int& top,const int& bottom ,const int &left ,const  int& right)
{
    left_bound = left;
    right_bound = right;
    top_bound = top;
    bottom_bound = bottom;
}

sf::FloatRect Pojazd::Give_Bounds()
{
    sf::FloatRect bound = getGlobalBounds();
    return bound;
}
void Pojazd::lvl()
{
    std::abs(speed.x++);
    std::cout<<speed.x<<" gora"<<std::endl;
}
void Pojazd::lvl2()
{
    std::abs(speed.x--);
    std::cout<<speed.x<<" dol"<<std::endl;
}
void Pojazd::Animate()
{

    move(speed.x,0);
    sf::FloatRect rectangle_bounds = getGlobalBounds();
    if(rectangle_bounds.left <=0.0)
    {
        setPosition(800.0,getPosition().y);
    }
    if(rectangle_bounds.left+rectangle_bounds.width >= 900.0)
    {
        setPosition(0.0,std::rand()%300);//getPosition().y);

    }

}
