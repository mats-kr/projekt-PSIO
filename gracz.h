#ifndef GRACZ_H
#define GRACZ_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
class gracz:public sf::RectangleShape
{
    sf::Vector2f speed;
    sf::Texture tex;
    int left_bound;
    int right_bound;
    int top_bound;
    int bottom_bound;
public:
    gracz(const sf::Vector2f &position);
//    void move();
    void Animate();
    void Set_Speed(const int& speed_x,const int& speed_y);
//    void setposition();
    void Size(int x,int y);
    void Color(sf::Color(col));
    void Bounds(const int &left, const int& right, const int& top,const int& bottom);

    sf::FloatRect Give_Bounds();
    void reversemove();
};

#endif // GRACZ_H
