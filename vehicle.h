#ifndef VEHICLE_H
#define VEHICLE_H

#include"sprite.h"

class Vehicle:public Sprite
{
protected:
    sf::Vector2f speed;
    sf::Texture texture;
    int acceleration;
    int startSpeed;
public:
   explicit Vehicle(const sf::Vector2f &position,const int&acceleratio,const int&start);
   void Lvl(sf::RenderWindow&wind)override ;
   void Start() override;

};


#endif // VEHICLE_H
