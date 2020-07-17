#ifndef SCENE_H
#define SCENE_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <iostream>
#include <sstream>
#include <memory>
#include <memory.h>
#include <ctime>
#include "redcar.h"
#include "player.h"
#include "greencar.h"
#include "policecar.h"
#include "dhlcar.h"
#include "sceneelements.h"
#include"scenelabels.h"
#include"vehicle.h"
#include"sceneborder.h"
#include"road.h"

class Scene
{
private:
    sf::RenderWindow window;
    std::vector<std::shared_ptr<Vehicle>> Vehicles;
    std::vector<std::shared_ptr<SceneElements>> Elements;
    int y1=0;
    int y3=0;
    int y2=(window.getSize().y/2);
    int y4=(window.getSize().y/2);
    sf::Event event;
    sf::Clock clock;
public:
    Scene();
    void RenderGame();
    void drawObjects(SceneElements&obj1,SceneElements&obj2,SceneElements&obj3,SceneElements&obj4,
                     SceneElements&obj5,SceneElements&obj6,SceneElements&obj7,SceneElements&obj8,SceneElements&obj9);
    void CreateObjects();
    void steeringLoop(Player&object,sf::RectangleShape&object2,sf::Event&event,sf::Time&elapsed);
    void DrawObjects(Player&Hero,sf::RectangleShape&GameEnd);
    void AnimateObjects(Player&Hero,sf::RectangleShape&GameEnd);
};

#endif // SCENE_H
