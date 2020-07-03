#ifndef POJAZDSPECJALNY_H
#define POJAZDSPECJALNY_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>
#include <string>
#include <ctime>
#include"sprite.h"
class PoliceCar:public Sprite
{
    sf::Vector2f speed;
    std::string texturePath = "policja.PNG";

public:
   explicit PoliceCar(const sf::Vector2f &position);
    void Start()final;
    void Lvl(sf::RenderWindow&wind) final;


    void Animate(const sf::Time &elapsed)final;//const int& h,const int& w);

};

#endif // POJAZDSPECJALNY_H
