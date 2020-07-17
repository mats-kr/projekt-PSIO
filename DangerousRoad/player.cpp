#include "player.h"
#include"greencar.h"
#include"redcar.h"
#include"policecar.h"
#include"dhlcar.h"
Player::Player(const sf::Vector2f &position):Sprite(position)
{
    LoadTexture(texturePath);
}
void Player::Zycia(sf::RenderWindow &wind)
{
    lives--;
    if(lives<=0)
    {
        wind.close();
        std::cout<<"KONIEC GRY"<<std::endl;
    }
}
void Player::Lvl(sf::RenderWindow&wind)
{
    LvlUpdate(wind);
}
void Player::LvlCounter(sf::RenderWindow&wind)
{
    font.loadFromFile("Fonts/I-pixel-u.ttf");
    std::string s = std::to_string(lvl);
    text.setFont(font);
    text.setPosition(150,10);
    text.setCharacterSize(35);
    text.setFillColor(sf::Color::White);
    text.setOutlineThickness(10);
    text.setOutlineColor(sf::Color::Black);
    text.setString(s);
    wind.draw(text);
}
void Player::Move(sf::RenderWindow&wind,const sf::Time &elapsed)
{
    if(time.getElapsedTime().asSeconds()>10&&time.getElapsedTime().asSeconds()<15)
    {
        ReverseAnimate(elapsed);
    }
    else
    {
        Animate(elapsed);
    }
    if(time.getElapsedTime().asSeconds()>17)
    {
        time.restart();
    }
}
void Player::Lives(sf::RenderWindow &wind)
{
    font.loadFromFile("Fonts/I-pixel-u.ttf");
    std::string s = std::to_string(lives);
    text.setString(s);
    text.setFont(font);
    text.setPosition(850,10);
    text.setCharacterSize(35);
    text.setFillColor(sf::Color::White);
    text.setOutlineThickness(10);
    text.setOutlineColor(sf::Color::Black);
    if(lives<=3)
    {
        text.setFillColor(sf::Color::Red);
    }
    wind.draw(text);
    if(lives<=0)
    {
        wind.close();
    }
}
void Player::checkCollision(sf::Sprite &object, sf::RenderWindow &wind)
{
    if (ObjectCollision(object,wind))
    {
        if (typeid(object) == typeid(GreenCar))
        {
            Hitsound();
            lives--;
            setPosition(wind.getSize().x/2,wind.getSize().y/2-20);
        }
        if(typeid (object)==typeid (PoliceCar)||typeid (object)==typeid (DhlCar))
        {
            Hitsound();
            lives-=5;
            setPosition(wind.getSize().x/2,wind.getSize().y-50);
        }
        else if (typeid(object) == typeid(RedCar))
        {
            lives--;
            Hitsound();
            setPosition(wind.getSize().x/2,wind.getSize().y-50);
        }
    }
}
void Player::Start()
{
    moveX=6;
    moveY=6;
}
void Player::Animate(const sf::Time &elapsed)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        if(GiveBounds().top >= topBound-10)
        {
            setPosition(getPosition().x,getPosition().y-moveY);
            Movesound();
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        if(GiveBounds().left >= leftBound)
        {
            setPosition(getPosition().x-moveX,getPosition().y);
            Movesound();
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if(GiveBounds().top+GiveBounds().height<=bottomBound)
        {
            setPosition(getPosition().x,getPosition().y+moveY);
            Movesound();
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        if(GiveBounds().left+GiveBounds().width<=rightBound)
        {
            setPosition(getPosition().x+moveX,getPosition().y);
            Movesound();
        }
    }
}
void Player::LvlUpdate(sf::RenderWindow&window)
{
    lvl++;
    setPosition(sf::Vector2f(window.getSize().x/2,window.getSize().y-50));
    TimeReset();
}
void Player::ReverseAnimate(const sf::Time &elapsed)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        if(GiveBounds().top >= topBound-10&&GiveBounds().top+GiveBounds().height<bottomBound)
        {
            setPosition(getPosition().x,getPosition().y+moveY);
            Movesound();
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        if(GiveBounds().left >= leftBound)
        {
            setPosition(getPosition().x+moveX,getPosition().y);
            Movesound();
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if(GiveBounds().top+GiveBounds().height<=bottomBound+50 &&GiveBounds().top >= topBound)
        {
            setPosition(getPosition().x,getPosition().y-moveY);
            Movesound();
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        if(GiveBounds().left+GiveBounds().width<=rightBound)
        {
            setPosition(getPosition().x-moveX,getPosition().y);
            Movesound();
        }
    }
}
void Player::Draw(sf::RenderWindow &window,sf::Text&obj)
{
    window.draw(obj);
}
