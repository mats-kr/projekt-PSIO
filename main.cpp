#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <iostream>
#include"gracz.h"
#include"pojazd.h"
#include"elementysceny.h"

int main()
{

    sf::RenderWindow window(sf::VideoMode(900, 800),"sfd");
    gracz hero(sf::Vector2f(window.getSize().x/2,750));
    hero.Set_Speed(10,10);
    hero.Bounds(0,window.getSize().y,0,window.getSize().x);
    hero.Size(50,50);
    hero.Color(sf::Color::Blue);

    int y=0;
    int y_2=(window.getSize().y/2);
    std::vector<Pojazd>pojazd;
    std::vector<Pojazd>pojazd2;

    for (int i=0; i<6; i++)
    {
        y+=50;
        y_2+=50;
        pojazd.emplace_back(Pojazd(sf::Vector2f(std::rand() % (window.getSize().x),y)));
        pojazd2.emplace_back(Pojazd(sf::Vector2f(std::rand() % (window.getSize().x),y_2)));

    }
    for (auto &rec : pojazd)
    {
        rec.Set_Speed(7,0);
        rec.Set_Bounds(0, window.getSize().x, 0, window.getSize().y);
        rec.Size(50,50);
        rec.Color(sf::Color::Cyan);
    }
    for (auto &rec : pojazd2)
    {
        rec.Set_Speed(-7,0);
        rec.Set_Bounds(0, window.getSize().x, 0, window.getSize().y);
        rec.Size(50,50);
    }
\

    elementysceny start(sf::Vector2f(0,window.getSize().y-50));
    start.Size(window.getSize().x,50);
    start.Color(sf::Color::Yellow);

    elementysceny pas_bezpieczenstwa(sf::Vector2f(0,(window.getSize().y/2)-50));
    pas_bezpieczenstwa.Size(window.getSize().x,100);
    pas_bezpieczenstwa.Color(sf::Color::Yellow);

    elementysceny koniec(sf::Vector2f(0,0));
    koniec.Size(window.getSize().x,50);
    koniec.Color(sf::Color::Yellow);



    sf::Clock clock;
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed||sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                window.close();
        }
        window.clear(sf::Color::Black);
        window.draw(start);
        window.draw(pas_bezpieczenstwa);
        window.draw(koniec);

        hero.Animate();
        window.draw(hero);

        for(auto &d:pojazd)
        {
            window.draw(d);
            d.Animate();
        }
        for(auto &d:pojazd2)
        {
            window.draw(d);
            d.Animate();
        }
//        p1.Animate();
//        window.draw(p1);
        window.display();
    }

    return 0;
}


