#ifndef ELEMENTYSCENY_H
#define ELEMENTYSCENY_H


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
class elementysceny:public sf::RectangleShape
{
public:
    elementysceny(const sf::Vector2f &position);
    void Size(int x,int y);
    void Color(sf::Color(col));
    void Bounds(const int &left, const int& right, const int& top,const int& bottom);

    sf::FloatRect Give_Bounds();
};

#endif // ELEMENTYSCENY_H
