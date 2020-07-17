#include "vehicle.h"

Vehicle::Vehicle(const sf::Vector2f &position,const int&acceleratio,const int&start):Sprite(position)
{
    acceleration=acceleratio;
    startSpeed=start;
}
void Vehicle::Start()
{
    std::abs(speed.x=startSpeed);
}
void Vehicle::Lvl(sf::RenderWindow &wind)
{
    std::abs(speed.x+=acceleration);
}








