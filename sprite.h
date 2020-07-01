#ifndef SPRITE_H
#define SPRITE_H


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include<iostream>
#include <string>
#include <ctime>

class sprite: public sf::Sprite
{
protected:
    int LVL=1;

    sf::Vector2f speed;
    int left_bound;
    int right_bound;
    int top_bound;
    int bottom_bound;
    sf::Clock time;
    sf::Texture texture;
    sf::Event event;
    sf::Font font;
    sf::Text text;
    sf::Music ms;

    void loadTexture(const std::string &path);


public:
    explicit sprite(const sf::Vector2f &position);
    void Set_Bounds(const int& left,const int& right,const int& top,const int& bottom);
    virtual void Set_Speed( const int& speed_x, const int& speed_y);
    virtual void New_Position()=0;
    void Size(int x,int y);
    virtual void lvl(sf::RenderWindow&wind)=0;
    virtual void lvl2()=0;
    //    virtual void InitFont();
    //    virtual void InitText();
    void time_r();
    virtual void Color(sf::Color(col));
    sf::FloatRect Give_Bounds();
    bool ObjectCollision(const sf::Sprite &object,const sf::RenderWindow &wind);
void Theme();
    virtual void Animate()=0;
    //    virtual void ReverseMove();


};

#endif // SPRITE_H
