#include "scene.h"

Scene::Scene():window(sf::VideoMode(900, 1000),"sfd")
{
    window.setFramerateLimit(60);
}
void Scene::RenderGame()
{
    sf::RenderWindow window(sf::VideoMode(900, 1000),"sfd");
    window.setFramerateLimit(60);

    Player Hero(sf::Vector2f(window.getSize().x/2,950));
    Hero.SetBounds(0,window.getSize().x,0,window.getSize().y);

    RenderObjects();

    sf::RectangleShape GameEnd;
    GameEnd.setSize(sf::Vector2f(30,30));
    GameEnd.setPosition(453,10);
    GameEnd.setFillColor(sf::Color::Transparent);

    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed||sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                window.close();
        }

        window.clear(sf::Color::Black);

        for(auto&elements:Elements)
        {
            elements->Render(window);
        }

        Hero.Move(window,elapsed);
        Hero.Lives(window);
        window.draw(Hero);
        window.draw(GameEnd);
        Hero.LvlCounter(window);

        for (auto &sprit:Vehicles)
        {
            window.draw(*sprit);
            sprit->Animate(elapsed);
            Hero.checkCollision(*sprit,window);
        }
        if(Hero.GiveBounds().intersects(GameEnd.getGlobalBounds()))
        {
            Hero.LvlUpdate(window);
            for(auto &sprite:Vehicles)
            {
                Hero.Movesound();
                Hero.Nextlvlsound();
                sprite->Lvl(window);
            }
            for(auto&elements:Elements)
            {
                elements->RestartTime();
            }
        }
        if(event.key.code==sf::Keyboard::P==true)
        {
            for(auto &sprit:Vehicles)
            {
                sprit->Start();
                Hero.Start();
                Hero.TimeReset();
                sprit->TimeReset();
            }
            for(auto&elements:Elements)
            {
                elements->RestartTime();
            }
        }
        for(auto&elements:Elements)
        {
            elements->RenderInfo(window);
        }
        window.display();
    }
}
void Scene::RenderObjects()
{
    for (int i = 0; i < 8; i++)
    {
        y1+=50;
        Vehicles.push_back(std::make_shared<GreenCar>(sf::Vector2f(std::rand() % (window.getSize().x),y1),100,100));
        y2+=50;
        Vehicles.push_back(std::make_shared<RedCar>(sf::Vector2f(std::rand() % (window.getSize().x),y2),100,100));
    }
    for (int i = 0; i < 3; i++)
    {
        y3+=100;
        Vehicles.push_back(std::make_shared<PoliceCar>(sf::Vector2f(std::rand() % (window.getSize().x),y3),200,150));
        y4+=100;
        Vehicles.push_back(std::make_shared<DhlCar>(sf::Vector2f(std::rand() % (window.getSize().x),y4),200,150));
    }
    Elements.push_back(std::make_shared<Road>(window,"droga4.PNG",0,0,1000,true,0));
    Elements.push_back(std::make_shared<SceneBorder>(window,"dolnypas.png",0,50,100,true,0));
    Elements.push_back(std::make_shared<SceneBorder>(window,"pas.png",0,550,100,true,0));
    Elements.push_back(std::make_shared<SceneBorder>(window,"wejscie.PNG",360,550,100,true,800));
    Elements.push_back(std::make_shared<SceneBorder>(window,"wyjscie.PNG",240,550,100,true,800));
    Elements.push_back(std::make_shared<SceneBorder>(window,"koniecekranu.PNG",0,1000,50,true,0));
    Elements.push_back(std::make_shared<SceneBorder>(window,"END.PNG",410,1000,50,true,800));
    Elements.push_back(std::make_shared<SceneLabels>(window,"POZIOM:",7,sf::Color::Cyan,17,27,false,0));
    Elements.push_back(std::make_shared<SceneLabels>(window,"ZYCIA:",710,sf::Color::Green,17,30,false,0));
}

