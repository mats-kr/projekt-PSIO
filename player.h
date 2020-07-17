#ifndef PLAYER_H
#define PLAYER_H

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
    sf::Sound nextLvlSound;
    int lvl=1;
    int moveX;
    int moveY;
    sf::Music theme;
public:
    explicit Player(const sf::Vector2f &position);
    void Animate(const sf::Time &elapsed) final;
    void checkCollision(sf::Sprite &object,sf::RenderWindow &wind);
    void Start()final;
    void Lvl(sf::RenderWindow&wind) final;
    void LvlCounter(sf::RenderWindow&wind);
    void Move(sf::RenderWindow&wind,const sf::Time &elapsed);
    void LvlUpdate(sf::RenderWindow&window);
    void Zycia(sf::RenderWindow &wind);
    void Lives(sf::RenderWindow &wind);
    void ReverseAnimate(const sf::Time &elapsed);
    void Draw(sf::RenderWindow&window,sf::Text&obj);
};

#endif // PLAYER_H
