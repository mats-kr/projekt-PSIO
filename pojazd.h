#ifndef POJAZD_H
#define POJAZD_H


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>
#include <string>
#include <ctime>
#include"sprite.h"
class Pojazd: public sprite
{
private:
    std::string texturePath = "car_2.PNG";

    int Y;
public:
    Pojazd(const sf::Vector2f &position);
    void Start();
    void lvl(sf::RenderWindow&wind) final;
    void lvl2() final;
    void tex();
    void New_Position()final;

    void Animate()final;//const int& h,const int& w);


};

#endif // POJAZD_H
