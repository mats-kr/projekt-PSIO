#ifndef REDCAR_H
#define REDCAR_H

#include"vehicle.h"

class RedCar: public Vehicle
{
private:
    std::string texturePath = "redcar.PNG";
public:
    explicit RedCar(const sf::Vector2f &position,const int&ac,const int&start);
    void Animate(const sf::Time &elapsed)final;

};

#endif // REDCAR_H
