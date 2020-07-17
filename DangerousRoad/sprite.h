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
    int leftBound;
    int rightBound;
    int topBound;
    int bottomBound;
    sf::SoundBuffer mov;
    sf::Sound moveSound;
    sf::SoundBuffer ht;
    sf::Sound hitSound;
    sf::SoundBuffer nextlvl;
    sf::Sound nextlvlSound;
    sf::Clock time;
    sf::Texture texture;
    sf::Event event;
    sf::Font font;
    sf::Text text;
    void LoadTexture(const std::string &path);
public:
    explicit Sprite(const sf::Vector2f &position);
    virtual void Animate(const sf::Time &elapsed)=0;
    virtual void Start()=0;
    virtual void Lvl(sf::RenderWindow&wind)=0;
    void SetBounds(const int& left,const int& right,const int& top,const int& bottom);
    void TimeReset();
    sf::FloatRect GiveBounds();
    void Movesound();
    void Hitsound();
    void Nextlvlsound();
    bool ObjectCollision(const sf::Sprite &object,const sf::RenderWindow &wind);

};

#endif // SPRITE_H
