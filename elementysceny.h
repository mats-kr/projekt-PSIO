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
     void lvl(sf::RenderWindow&wind);
    void lvl2();
     void Animate();
     void New_Position()final;




};

#endif // ELEMENTYSCENY_H
