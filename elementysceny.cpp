#include "elementysceny.h"

elementysceny::elementysceny(const sf::Vector2f &position)
{
    setPosition(position);
}
void elementysceny::Size(int x, int y)
{
    setSize(sf::Vector2f(x,y));
}
void elementysceny::Color(sf::Color (col))
{
    setFillColor(col);
}
