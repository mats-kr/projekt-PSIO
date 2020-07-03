#ifndef GRACZ_H
#define GRACZ_H
#include<iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include"sprite.h"
class Player :public Sprite
{
    int lives=10;

    std::string texturePath = "PIX2.PNG";
    sf::SoundBuffer mov;
    sf::Sound moveSound;
    sf::SoundBuffer ht;
    sf::Sound hitSound;
    sf::SoundBuffer nextlvl;
    sf::Sound nextlvlSound;
    int LVL=1;
    int X;
    int Y;
    sf::Music theme;


public:
    explicit Player(const sf::Vector2f &position);
    void Animate(const sf::Time &elapsed) final;
    void checkCollision(sf::Sprite &object,sf::RenderWindow &wind);
    void Start()final;

    void Lvl(sf::RenderWindow&wind) final;
    void LVL_Counter(sf::RenderWindow&wind);
    void move(sf::RenderWindow&wind,const sf::Time &elapsed);
    void info(sf::RenderWindow&wind);
    void TimeReset();
    void Themesog(const std::string& filename);
    void ThemeSongPlay();
    void LVL_(sf::RenderWindow&window);
    void Zycia(sf::RenderWindow &wind);
    void Lives(sf::RenderWindow &wind);
    void movesound();
    void hitsound();
    void nextlvlsound();
    void ReverseMove(const sf::Time &elapsed);
};

#endif // GRACZ_H
