#ifndef SPRITE_H
#define SPRITE_H


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<iostream>
#include <string>
#include <ctime>

class Sprite: public sf::Sprite
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
     void loadTexture(const std::string &path);


public:
    explicit Sprite(const sf::Vector2f &position);
    void SetBounds(const int& left,const int& right,const int& top,const int& bottom);
    virtual void SetSpeed( const int& speed_x, const int& speed_y);    virtual void Lvl(sf::RenderWindow&wind)=0;
    void TimeReset();
    sf::FloatRect Give_Bounds();
    bool ObjectCollision(const sf::Sprite &object,const sf::RenderWindow &wind);
    virtual void Animate(const sf::Time &elapsed)=0;
    virtual void Start()=0;


};

#endif // SPRITE_H
