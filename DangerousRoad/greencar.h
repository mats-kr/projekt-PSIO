#ifndef GREENCAR_H
#define GREENCAR_H

#include"vehicle.h"

class GreenCar: public Vehicle
{
private:
    std::string texturePath = "greencar.PNG";
public:
    explicit GreenCar(const sf::Vector2f &position,const int&ac,const int&start);
    void Animate(const sf::Time &elapsed)final;
};

#endif // GREENCAR_H
