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

int main()
{



    sf::Font font;
    sf::Text opis;
    sf::RenderWindow window(sf::VideoMode(900, 1000),"sfd");

    Player hero(sf::Vector2f(window.getSize().x/2,950));
    hero.SetBounds(0,window.getSize().x,0,window.getSize().y);

    int y_1=0;
    int y_3=0;
    int y_2=(window.getSize().y/2);
    int y_4=(window.getSize().y/2);


    std::vector<std::shared_ptr<Sprite>> sprites;


    for (int i = 0; i < 8; i++)
    {
        y_1+=50;
        sprites.push_back(std::make_shared<GreenCar>(sf::Vector2f(std::rand() % (window.getSize().x),y_1)));
    }
    for (int i = 0; i < 8; i++)
    {
        y_2+=50;
        sprites.push_back(std::make_shared<RedCar>(sf::Vector2f(std::rand() % (window.getSize().x),y_2)));
    }
    for (int i = 0; i < 3; i++)
    {
        y_3+=100;
        sprites.push_back(std::make_shared<PoliceCar>(sf::Vector2f(std::rand() % (window.getSize().x),y_3)));
    }
    for (int i = 0; i < 3; i++)
    {
        y_4+=100;
        sprites.push_back(std::make_shared<DhlCar>(sf::Vector2f(std::rand() % (window.getSize().x),y_4)));
    }
    for (auto &sprite:sprites)
    {
        sprite->SetBounds(0, window.getSize().x, 0, window.getSize().y);

    }

    SceneElements GameStart(sf::Vector2f(0,window.getSize().y-50));
    GameStart.renderStart(window);

    SceneElements GameEnd(sf::Vector2f(0,window.getSize().y-50));
    GameEnd.renderEnd(window);

    SceneElements SafetyRoad(sf::Vector2f(0,(window.getSize().y/2)-50));
    SafetyRoad.renderLaine(window);

    SceneElements Entrace(sf::Vector2f(0,(window.getSize().y/2)-50));
    Entrace.renderEnter(window);

    SceneElements Exit(sf::Vector2f(0,(window.getSize().y/2)-50));
    Exit.renderExit(window);

    SceneElements End(sf::Vector2f(0,0));
    End.renderScreenEnd(window);

    SceneElements Road(sf::Vector2f(window.getSize().x,window.getSize().y));

    SceneElements LivesCounter(sf::Vector2f(750,20));

    SceneElements LvlCounter(sf::Vector2f(23,20));



    SceneElements info(sf::Vector2f(window.getSize().x/2,100));





    sf::Clock clock;
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();
        std::cout<<elapsed.asSeconds()<<std::endl;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed||sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                window.close();
        }





        window.clear(sf::Color::Black);
        Road.renderRoad(window);
        window.draw(GameStart);
        window.draw(SafetyRoad);
        window.draw(Entrace);
        window.draw(Exit);
        window.draw(End);
        hero.move(window,elapsed);
        hero.info(window);
        hero.Lives(window);
        window.draw(hero);


        for (auto &sprit:sprites)
        {
            window.draw(*sprit);
            sprit->Animate(elapsed);
            hero.checkCollision(*sprit,window);

        }

        if(hero.Give_Bounds().intersects(GameEnd.getGlobalBounds()))
        {

            hero.LVL_(window);
            for(auto &sprite:sprites)
            {

                hero.movesound();
                hero.nextlvlsound();
                sprite->Lvl(window);
            }

        }
        window.draw(GameEnd);
        hero.LVL_Counter(window);
        LivesCounter.renderLivesString(window);
        LvlCounter.renderLvlString(window);
        info.displayInfo(window);
        if(event.key.code==sf::Keyboard::P==true)
        {
             for(auto &sprit:sprites)
            {
                sprit->Start();
                hero.Start();
                hero.TimeReset();
            }
        }


        window.display();
    }


    return 0;
}
