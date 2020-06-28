#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <iostream>
#include<sstream>
#include<memory>

#include<memory.h>
#include"pojazd2.h"
#include"gracz.h"
#include"pojazd.h"
#include"pojazdspecjalny.h"
#include"elementysceny.h"

int main()
{
    //    sf::RenderWindow window1(sf::VideoMode(900, 900),"sfd");


    //    std::string texturePath = "monster.PNG";

    //    sf::Texture texture;
    //    if (!texture.loadFromFile("monster.PNG"))
    //    {
    //        std::cerr << "Could not load texture" << std::endl;
    //        return 1;
    //    }
    //    sf::Sprite sprite;
    //    sprite.setTexture(texture);
    //    window1.setFramerateLimit(60);

    //    int sl;
    //    std::cin>>sl;
    //    switch (sl)
    //    {
    //    case 1:
    //    {
    sf::RenderWindow window(sf::VideoMode(900, 1000),"sfd");
    int LVL=1;

    sf::Font font;
    font.loadFromFile("Fonts/I-pixel-u.ttf");
    std::string s = std::to_string(LVL);

    sf::Text text;
    text.setFont(font);
    text.setPosition(150,20);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Green);
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


    gracz hero(sf::Vector2f(window.getSize().x/2,950));
    hero.Set_Speed(10,10);
    hero.Set_Bounds(0,window.getSize().y,0,window.getSize().x);
//    hero.Size(50,50);
   // hero.Color(sf::Color::Blue);
    int speedX=0;
    int y=0;
    int y_3=0;
    int y_2=(window.getSize().y/2);
    std::vector<Pojazd>pojazd;
    std::vector<Pojazd>pojazd2;
    std::vector<std::shared_ptr<sprite>> sprites;

    std::vector<pojazdspecjalny>pojazd_spec1;



    sf::RectangleShape koniec_gry;
    koniec_gry.setSize(sf::Vector2f(40,40));
    koniec_gry.setOutlineThickness(10);
    koniec_gry.setFillColor(sf::Color::Transparent);
    koniec_gry.setOutlineColor(sf::Color::Red);
    koniec_gry.setPosition(window.getSize().x/2-40,10);




    for (int i = 0; i < 8; i++)
    {
        y+=50;
        sprites.push_back(std::make_shared<Pojazd>(sf::Vector2f(std::rand() % (window.getSize().x),y)));
    }
    for (int i = 0; i < 8; i++)
    {
        y_2+=50;
        sprites.push_back(std::make_shared<Pojazd2>(sf::Vector2f(std::rand() % (window.getSize().x),y_2)));
    }
//    for (int i = 0; i < 3; i++)
//    {
//        y_3+=400;
//        sprites.push_back(std::make_shared<elementysceny>(sf::Vector2f(std::rand() % (window.getSize().x),y_3)));
//    }
//    for (int i = 0; i < 5; i++)
//    {
//        sprites.push_back(std::make_shared<Pojazd2>(sf::Vector2f(std::rand() % (window.getSize().x),std::rand() % (window.getSize().y))));
//    }
    for (auto &sprite:sprites)
    {
        sprite->Set_Speed(speedX,0);
        sprite->Size(50,50);
        sprite->Set_Bounds(0, window.getSize().x, 0, window.getSize().y);

    }

    sf::Texture texture;
    if (!texture.loadFromFile("wall.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    texture.setRepeated(true);
    sf::Sprite sprite;
    sprite.setTexture(texture);

    elementysceny start(sf::Vector2f(0,window.getSize().y-50));
    start.setPosition(sf::Vector2f(0,window.getSize().y-50));
    start.setTextureRect(sf::IntRect(0, 0, window.getSize().x,100));
    start.setTexture(texture);

    elementysceny pas_bezpieczenstwa(sf::Vector2f(0,(window.getSize().y/2)-50));
    pas_bezpieczenstwa.setPosition(sf::Vector2f(0,(window.getSize().y/2)-50));
    pas_bezpieczenstwa.setTextureRect(sf::IntRect(0, 0, window.getSize().x,100));
    pas_bezpieczenstwa.setTexture(texture);

    elementysceny koniec(sf::Vector2f(0,0));
    koniec.setPosition(sf::Vector2f(0,0));
    koniec.setTextureRect(sf::IntRect(0, 0, window.getSize().x,50));
    koniec.setTexture(texture);



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

        for (auto &sprit:sprites)
        {
            window.draw(*sprit);
            sprit->Animate();
            hero.checkCollision(*sprit,window);

        }
                if(hero.Give_Bounds().intersects(koniec_gry.getGlobalBounds()))
                {
                    LVL++;
                    hero.setPosition(sf::Vector2f(window.getSize().x/2,window.getSize().y-50));
                    for(auto &p:sprites)
                    {
                        p->lvl(window);
                        p->lvl2();
                    }

                }
        window.draw(koniec_gry);
        window.draw(text);
        window.draw(text2);
        window.draw(text3);
        window.display();
    }
    //    }
    //        break;
    //    case 2:
    //    {



    return 0;
}
