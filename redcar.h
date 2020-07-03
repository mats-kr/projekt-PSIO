#ifndef POJAZD2_H
#define POJAZD2_H


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>
#include <string>
#include <ctime>
#include"sprite.h"
class RedCar: public Sprite
{
    std::string texturePath = "redcar.PNG";
    sf::Vector2f speed;


public:
   explicit RedCar(const sf::Vector2f &position);
    void Lvl(sf::RenderWindow&wind) final;
    void Start() final;
    void Animate(const sf::Time &elapsed)final;//const int& h,const int& w);



};

#endif // POJAZD2_H
