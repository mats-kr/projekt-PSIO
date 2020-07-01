#ifndef POJAZD2_H
#define POJAZD2_H


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>
#include <string>
#include <ctime>
#include"sprite.h"
class Pojazd2: public sprite
{
    std::string texturePath = "redcar.PNG";

public:
   explicit Pojazd2(const sf::Vector2f &position);
    void lvl(sf::RenderWindow&wind) final;
    void lvl2() final;
    void New_Position()final;
    void Animate()final;//const int& h,const int& w);



};

#endif // POJAZD2_H
