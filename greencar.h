#ifndef POJAZD_H
#define POJAZD_H


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>
#include <string>
#include <ctime>
#include"sprite.h"
class GreenCar: public Sprite
{
private:
    std::string texturePath = "greencar.PNG";
    sf::Vector2f speed;
public:
    GreenCar(const sf::Vector2f &position);
    void Start() final;
    void Lvl(sf::RenderWindow&wind) final;

    void Animate(const sf::Time &elapsed)final;//const int& h,const int& w);


};

#endif // POJAZD_H
