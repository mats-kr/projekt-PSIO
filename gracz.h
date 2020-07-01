#ifndef GRACZ_H
#define GRACZ_H
#include<iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include"sprite.h"
class gracz :public sprite
{
    int zycia=10;

    std::string texturePath = "PIX.PNG";
    std::string texturePath2 = "CJ2.PNG";



public:
    explicit gracz(const sf::Vector2f &position);

    //    void setposition();
    void kolizja_dol(sf::RectangleShape obiekt,sf::RenderWindow &wind);
    void kolizja_gora(sf::RectangleShape obiekt,sf::RenderWindow &wind);
    void  kolizja_specjalny(sf::RectangleShape obiekt);
    void Animate() final;
    void checkCollision(sf::Sprite &object,sf::RenderWindow &wind);

    void lvl(sf::RenderWindow&wind) final;
    void New_Position()final;
    void move(sf::RenderWindow&wind);
    void info(sf::RenderWindow&wind);
    void time_r();
    void LVL_(sf::RenderWindow&window);
    void lvl2() final;
    void Zycia(sf::RenderWindow &wind);
    void Lives(sf::RenderWindow &wind);
    void sound();
    void ReverseMove();
};

#endif // GRACZ_H
