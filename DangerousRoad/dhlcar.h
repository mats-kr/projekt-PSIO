#ifndef DHLCAR_H
#define DHLCAR_H

#include"vehicle.h"

class DhlCar: public Vehicle
{
private:
    std::string texturePath = "DHL.PNG";
public:
    explicit DhlCar(const sf::Vector2f &position,const int&ac,const int&start);
    void Animate(const sf::Time &elapsed);
};



#endif // DHLCAR_H
