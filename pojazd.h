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
    sf::Vector2f speed;
    bool is_selected_ = false;
    int left_bound;
    int right_bound;
    int top_bound;
    int bottom_bound;
    sf::Clock time;
public:
    Pojazd(const sf::Vector2f &position);
    void lvl();
    void Start();
    void lvl2();
    void Animate();//const int& h,const int& w);


};

#endif // POJAZD_H
