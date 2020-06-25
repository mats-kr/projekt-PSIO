#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <iostream>
#include<sstream>
#include"gracz.h"
#include"pojazd.h"
#include"pojazdspecjalny.h"
#include"elementysceny.h"

int main()
{

    sf::RenderWindow window(sf::VideoMode(900, 900),"sfd");

    int LVL=1;

    sf::Font font;
    font.loadFromFile("Fonts/I-pixel-u.ttf");
    std::string s = std::to_string(LVL);

    sf::Text text;
    text.setFont(font);
    text.setPosition(150,20);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    sf::Text text2;
    text2.setFont(font);
    text2.setString("POZIOM:");
    text2.setPosition(23,20);
    text2.setCharacterSize(24);
    text2.setFillColor(sf::Color::Black);
    sf::Text text3;
    text3.setFont(font);
    text3.setString("ZYCIA:");
    text3.setPosition(750,20);
    text3.setCharacterSize(24);
    text3.setFillColor(sf::Color::Black);


    gracz hero(sf::Vector2f(window.getSize().x/2,850));
    hero.Set_Speed(10,10);
    hero.Set_Bounds(0,window.getSize().y,0,window.getSize().x);
    hero.Size(50,50);
    hero.Color(sf::Color::Blue);
    int speedX=7;
    int y=0;
    int y_2=(window.getSize().y/2);
    std::vector<Pojazd>pojazd;
    std::vector<Pojazd>pojazd2;
    std::vector<pojazdspecjalny>pojazd_spec1;
    //    sf::Texture tex;
    //    tex.loadFromFile("CJ2.png");
    //    hero.setTexture(tex);


    sf::RectangleShape koniec_gry;
    koniec_gry.setSize(sf::Vector2f(40,40));
    koniec_gry.setOutlineThickness(10);
    koniec_gry.setFillColor(sf::Color::Transparent);
    koniec_gry.setOutlineColor(sf::Color::Red);
    koniec_gry.setPosition(window.getSize().x/2-40,10);

    for (int i=0; i<7; i++)
    {
        y+=50;
        y_2+=50;
        pojazd.emplace_back(Pojazd(sf::Vector2f(std::rand() % (window.getSize().x),y)));
        pojazd2.emplace_back(Pojazd(sf::Vector2f(std::rand() % (window.getSize().x),y_2)));

    }
    for(int i=0;i<2;i++)
    {
        y+=150;
        y_2+=50;
        pojazd_spec1.emplace_back(pojazdspecjalny(sf::Vector2f(std::rand() % (window.getSize().x),y)));
        // pojazd2.emplace_back(Pojazd(sf::Vector2f(std::rand() % (window.getSize().x),y_2)));
    }
    for(auto&poj:pojazd_spec1)
    {
        poj.Set_Speed(-speedX*2,0);
        poj.Size(50,50);
        poj.Color(sf::Color::Green);
    }
    for (auto &rec : pojazd)
    {
        rec.Set_Speed(speedX,0);
        rec.Set_Bounds(0, window.getSize().x, 0, window.getSize().y);
        rec.Size(50,50);
        rec.Color(sf::Color::Cyan);
    }
    for (auto &rec : pojazd2)
    {
        rec.Set_Speed(-speedX,0);
        rec.Set_Bounds(0, window.getSize().x, 0, window.getSize().y);
        rec.Size(50,50);
    }


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

        std::string s=std::to_string(LVL);
        text.setString(s);


        window.clear(sf::Color::Black);
        window.draw(start);
        window.draw(pas_bezpieczenstwa);
        window.draw(koniec);
        hero.Animate();
        hero.Lives(window);
        window.draw(hero);
        for(auto &d:pojazd2)
        {
            window.draw(d);
            hero.kolizja_dol(d,window);
            d.Animate();
            d.Start();

        }
        for(auto &d:pojazd)
        {
            window.draw(d);
            hero.kolizja_gora(d,window);
            d.Animate();
        }
        for(auto&d:pojazd_spec1)
        {
            window.draw(d);
            d.Animate();
            hero.kolizja_specjalny(d);
        }
        if(hero.Give_Bounds().intersects(koniec_gry.getGlobalBounds()))
        {
            LVL++;
            hero.setPosition(sf::Vector2f(window.getSize().x/2,850));
            for(auto &p:pojazd)
            {
                p.lvl();
            }
            for(auto &p:pojazd2)
            {
                p.lvl2();
            }
        }


        window.draw(koniec_gry);
        window.draw(text);
        window.draw(text2);
        window.draw(text3);
        window.display();
    }

    return 0;
}

