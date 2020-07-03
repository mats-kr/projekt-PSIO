#ifndef POJAZDSPECJALNY2_H
#define POJAZDSPECJALNY2_H




#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>
#include <string>
#include <ctime>
#include"sprite.h"
class DhlCar:public Sprite
{
    std::string texturePath = "DHL.PNG";
    sf::Vector2f speed;
    int speedx;

public:
   explicit DhlCar(const sf::Vector2f &position);
    void Start()final;
    void Lvl(sf::RenderWindow&wind) final;

    void Animate(const sf::Time &elapsed)final;//const int& h,const int& w);

};



#endif // POJAZDSPECJALNY2_H
