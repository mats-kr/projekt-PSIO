#ifndef POLICECAR_H
#define POLICECAR_H

#include"vehicle.h"

class PoliceCar:public Vehicle
{
private:
    std::string texturePath = "policja.PNG";
public:
    explicit PoliceCar(const sf::Vector2f &position,const int&ac,const int&start);
    void Animate(const sf::Time &elapsed)final;

};

#endif // POLICECAR_H
