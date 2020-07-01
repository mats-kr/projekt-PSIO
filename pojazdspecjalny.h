#ifndef POJAZDSPECJALNY_H
#define POJAZDSPECJALNY_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>
#include <string>
#include <ctime>
#include"sprite.h"
class pojazdspecjalny:public sprite
{
    std::string texturePath = "policja.PNG";

public:
   explicit pojazdspecjalny(const sf::Vector2f &position);
    void Start();
    void lvl(sf::RenderWindow&wind) final;
    void lvl2() final;
    void tex();
    void New_Position()final;

    void Animate()final;//const int& h,const int& w);

};

#endif // POJAZDSPECJALNY_H
