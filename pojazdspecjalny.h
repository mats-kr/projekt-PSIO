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

public:
   explicit pojazdspecjalny(const sf::Vector2f &position);
    void New_Position()final;

    void Animate()final;//const int& h,const int& w);


};

#endif // POJAZDSPECJALNY_H
