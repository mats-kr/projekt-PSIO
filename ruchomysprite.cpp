#include "sprite.h"

sprite::sprite(const sf::Vector2f &position)
{
    setPosition(position);
}
void sprite::Size(int x, int y)
{
    setSize(sf::Vector2f(x,y));
}
void sprite::Color(sf::Color (col))
{
    setFillColor(col);
}
void sprite::Animate()
{

}
void sprite::lvl()
{
    std::abs(speed.x++);
    std::cout<<speed.x<<" gora"<<std::endl;
}
void sprite::lvl2()
{
    std::abs(speed.x--);
    std::cout<<speed.x<<" dol"<<std::endl;
}

//void sprite::InitFont()
//{
//    font.loadFromFile("Fonts/Metropolian-Display.ttf");

//}

//void sprite::InitText()
//{
//    text.setFont(font);

//}
void sprite::Set_Speed(const int &speed_x, const int &speed_y)
{
    speed.x= speed_x;
    speed.y = speed_y;
}
void sprite::Set_Bounds(const int &left, const int &right, const int &top, const int &bottom)
{
    left_bound = left;
    right_bound = right;
    top_bound = top;
    bottom_bound = bottom;
}
sf::FloatRect sprite::Give_Bounds()
{
    sf::FloatRect bound = getGlobalBounds();
    return bound;
}
