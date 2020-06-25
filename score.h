#ifndef SCORE_H
#define SCORE_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>
#include <string>
#include <ctime>
#include"sprite.h"

class score:public sprite
{
    sf::Font font;

public:
    explicit score(const sf::Vector2f &position);
    void loadfont();
};

#endif // SCORE_H
