#ifndef SPRITE_H
#define SPRITE_H


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>
#include <string>
#include <ctime>

class sprite: public sf::RectangleShape
{
protected:
    sf::Vector2f speed;
    int left_bound;
    int right_bound;
    int top_bound;
    int bottom_bound;
    sf::Clock time;

    sf::Event event;

public:
    explicit sprite(const sf::Vector2f &position);
    void Set_Bounds(const int& left,const int& right,const int& top,const int& bottom);
    void Set_Speed( const int& speed_x, const int& speed_y);
    void New_Position(const int& w);
    void Size(int x,int y);
    void lvl();
    void lvl2();
    void InitFont();
    void InitText();
    void Color(sf::Color(col));
    sf::FloatRect Give_Bounds();
    void Animate();


};

#endif // SPRITE_H
