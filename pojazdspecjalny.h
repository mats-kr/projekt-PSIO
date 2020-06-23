#ifndef POJAZDSPECJALNY_H
#define POJAZDSPECJALNY_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>
#include <string>
#include <ctime>
class pojazdspecjalny:public sf::RectangleShape
{
    sf::Vector2f speed;
    bool is_selected_ = false;
    int left_bound;
    int right_bound;
    int top_bound;
    int bottom_bound;
    sf::Clock time;
public:
    pojazdspecjalny(const sf::Vector2f &position);
    void Set_Bounds(const int& left,const int& right,const int& top,const int& bottom);
    void Set_Speed( const int& speedY, const int& speedX);
    void New_Position(const int& w);
    void Size(int x,int y);
    void lvl();
    void lvl2();
    void Color(sf::Color(col));
    void Animate();//const int& h,const int& w);
    sf::FloatRect Give_Bounds();

};

#endif // POJAZDSPECJALNY_H
