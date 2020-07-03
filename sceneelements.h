#ifndef ELEMENTYSCENY_H
#define ELEMENTYSCENY_H


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include"sprite.h"
class SceneElements:public Sprite
{
    sf::Texture entrace;
    sf::Texture exit;
    sf::Texture safetyroad;
    sf::Texture end;
    sf::Texture screenend;
    sf::Texture texture2;
    sf::Font font;
    sf::Text livescounter;
    sf::Text lvl;
    sf::Vector2f speed;
    sf::Text opis;
    std::string texturePath2 = "CJ2.PNG";
    sf::Sprite background;
    sf::Texture back;



public:
    explicit SceneElements(const sf::Vector2f &position);
    void Lvl(sf::RenderWindow&wind);
    void Lvl2 ();
    void Animate(const sf::Time &elapsed);
    void renderEnter(sf::RenderWindow&wind);
    void renderExit(sf::RenderWindow&wind);
    void renderLaine(sf::RenderWindow&wind);
    void renderEnd(sf::RenderWindow&wind);
    void renderScreenEnd(sf::RenderWindow&wind);
    void renderStart(sf::RenderWindow&wind);
    void renderRoad(sf::RenderWindow&wind);
    void renderLivesString(sf::RenderWindow&wind);
    void renderLvlString(sf::RenderWindow&wind);
    void displayInfo(sf::RenderWindow&wind);
    void Theme();
    void MenuBackground(sf::RenderWindow &wind);
    void Start()final;
    void loadfont();





};

#endif // ELEMENTYSCENY_H
