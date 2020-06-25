#ifndef ELEMENTYSCENY_H
#define ELEMENTYSCENY_H


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include"sprite.h"
class elementysceny:public sprite
{

public:
   explicit elementysceny(const sf::Vector2f &position);
    void Size(int x,int y);
    void Color(sf::Color(col));
    sf::FloatRect Give_Bounds();

    //    void setposition()
    void Set_Bounds(const int& left,const int& right,const int& top,const int& bottom);
    void New_Position(const int& w);

};

#endif // ELEMENTYSCENY_H
