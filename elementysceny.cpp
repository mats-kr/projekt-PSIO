#include "elementysceny.h"
elementysceny::elementysceny(const sf::Vector2f &position):sprite(position)
{
    setPosition(position);
}
//void elementysceny::Size(int x, int y)
//{
//    setSize(sf::Vector2f(x,y));
//}
//void elementysceny::Color(sf::Color (col))
//{
//    setFillColor(col);
//}
void elementysceny::lvl(sf::RenderWindow&wind)
{
    std::abs(speed.x++);
    std::cout<<speed.x<<" gora"<<std::endl;
}
void elementysceny::lvl2()
{
    std::abs(speed.x--);
    std::cout<<speed.x<<" dol"<<std::endl;
}
void elementysceny::Animate()
{

}





void elementysceny::New_Position()//const int &w)
{

}
//void elementysceny::Set_Bounds(const int& top,const int& bottom ,const int &left ,const  int& right)
//{
//    left_bound = left;
//    right_bound = right;
//    top_bound = top;
//    bottom_bound = bottom;
//}
//sf::FloatRect elementysceny::Give_Bounds()
//{
//    sf::FloatRect bound = getGlobalBounds();
//    return bound;
//}
