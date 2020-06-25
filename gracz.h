#ifndef GRACZ_H
#define GRACZ_H
#include<iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include"sprite.h"
class gracz :public sprite
{
    sf::Texture tex;
    int zycia=10;
    sf::Font font;
    sf::Text text;

public:
    gracz(const sf::Vector2f &position);
    void Animate();
    //    void setposition();
    void kolizja_dol(sf::RectangleShape obiekt,sf::RenderWindow &wind);
    void kolizja_gora(sf::RectangleShape obiekt,sf::RenderWindow &wind);
    void  kolizja_specjalny(sf::RectangleShape obiekt);
    void Zycia(sf::RenderWindow &wind);
    void Lives(sf::RenderWindow &wind);
    void reversemove();
};

#endif // GRACZ_H
