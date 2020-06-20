#include "gracz.h"

gracz::gracz(const sf::Vector2f &position)
{
    setPosition(position);
}
void gracz::Set_Speed(const int &speed_x, const int& speed_y)
{
    speed.x= speed_x;
    speed.y = speed_y;
}
void gracz::Size(int x, int y)
{
    setSize(sf::Vector2f(x,y));
}
void gracz::Color(sf::Color (col))
{
    setFillColor(col);
}
void gracz::Bounds(const int& top,const int& bottom ,const int &left ,const  int& right)
{
    left_bound = left;
    right_bound = right;
    top_bound = top;
    bottom_bound = bottom;
}

sf::FloatRect gracz::Give_Bounds()
{
    sf::FloatRect bound = getGlobalBounds();
    return bound;
}
void gracz::Animate()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)||sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        if(Give_Bounds().top >= top_bound){move(0,(-speed.y));}  
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)||sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        if(Give_Bounds().left >= left_bound){move(-speed.x,0);}
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)||sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if(Give_Bounds().top+Give_Bounds().height<=bottom_bound ){move(0, speed.y);}
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)||sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        if(Give_Bounds().left+Give_Bounds().width<=right_bound){move(speed.x,0);}
    }

}
