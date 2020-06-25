#include "score.h"

score::score(const sf::Vector2f &position):sprite(position)
{
    setPosition(position);
}

void score::loadfont()
{
    font.loadFromFile("Fonts/Metropolian-Display.ttf");

}
