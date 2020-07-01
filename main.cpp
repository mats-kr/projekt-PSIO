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
#include"pojazdspecjalny2.h"
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
    text.setFillColor(sf::Color::Black);
    sf::Text poziom;
    poziom.setFont(font);
    poziom.setString("POZIOM:");
    poziom.setPosition(23,20);
    poziom.setCharacterSize(24);
    poziom.setFillColor(sf::Color::Black);
    sf::Text licznikzyc;
    licznikzyc.setFont(font);
    licznikzyc.setString("ZYCIA:");
    licznikzyc.setPosition(750,20);
    licznikzyc.setCharacterSize(24);
    licznikzyc.setFillColor(sf::Color::Black);




    gracz hero(sf::Vector2f(window.getSize().x/2,950));
    hero.Set_Speed(10,10);
    hero.Set_Bounds(0,window.getSize().x,0,window.getSize().y);

    int speedX=0;
    int y=0;
    int y_3=0;
    int y_2=(window.getSize().y/2);
    int y_4=(window.getSize().y/2);

    std::vector<Pojazd>pojazd;
    std::vector<Pojazd>pojazd2;
    std::vector<std::shared_ptr<sprite>> sprites;


    sf::Texture end;
    end.loadFromFile("END.PNG");

    //    sf::RectangleShape koniec_gry;
    ////    koniec_gry.setSize(sf::Vector2f(40,40));
    ////    koniec_gry.setFillColor(sf::Color::Transparent);
    //    koniec_gry.setPosition(window.getSize().x/2-40,10);
    //    koniec_gry.setTexture(&end);


    //
    sf::Music theme;
    if(!theme.openFromFile("sfmlgame.wav"))
    {
        std::cout<<"!!!!!!!!!!!!!!"<<std::endl;
    }
    theme.setLoop(true);
    sf::SoundBuffer nextlvl;
    if (!nextlvl.loadFromFile("lvl.wav"))
        return EXIT_FAILURE;
    sf::Sound nexlvlSound(nextlvl);

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
    for (int i = 0; i < 3; i++)
    {
        y_3+=100;
        sprites.push_back(std::make_shared<pojazdspecjalny>(sf::Vector2f(std::rand() % (window.getSize().x),y_3)));
    }
    for (int i = 0; i < 3; i++)
    {
        y_4+=100;
        sprites.push_back(std::make_shared<pojazdspecjalny2>(sf::Vector2f(std::rand() % (window.getSize().x),y_4)));
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
    sf::Texture texture2;
    if (!texture2.loadFromFile("droga4.PNG")){ return 1; }
    texture2.setRepeated(true);
    sf::Sprite sprite2;
    sprite2.setTexture(texture2);
    sprite2.setTextureRect(sf::IntRect(0, 3, 900, 1000));

    sf::Texture wejscie;
    if (!wejscie.loadFromFile("wejscie.PNG")){ return 1; }

    sf::Texture wyjscie;
    wyjscie.loadFromFile("wyjscie.PNG");

    sf::Texture koniec;
    koniec.loadFromFile("koniecekranu.PNG");
    koniec.setRepeated(true);




    sf::Texture pas;
    if (!pas.loadFromFile("pas.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }
    pas.setRepeated(true);
    sf::Sprite sprite;
    sprite.setTexture(pas);


    elementysceny start(sf::Vector2f(0,window.getSize().y-50));
    start.setPosition(sf::Vector2f(0,window.getSize().y-50));
    start.setTextureRect(sf::IntRect(0, 0, window.getSize().x,100));
    start.setTexture(pas);

    elementysceny koniec_gry(sf::Vector2f(0,window.getSize().y-50));
    //    koniec_gry.setSize(sf::Vector2f(40,40));
    //    koniec_gry.setFillColor(sf::Color::Transparent);
    koniec_gry.setPosition(window.getSize().x/2-40,-69);
    koniec_gry.setTexture(end);

    elementysceny pas_bezpieczenstwa(sf::Vector2f(0,(window.getSize().y/2)-50));
    pas_bezpieczenstwa.setPosition(sf::Vector2f(0,(window.getSize().y/2)-50));
    pas_bezpieczenstwa.setTextureRect(sf::IntRect(0, 0, window.getSize().x,100));
    pas_bezpieczenstwa.setTexture(pas);

    elementysceny Wejscie(sf::Vector2f(0,(window.getSize().y/2)-50));
    Wejscie.setPosition(sf::Vector2f(window.getSize().x/2-90,(window.getSize().y/2)-50));
    // Wejscie.setTextureRect(sf::IntRect(0, 0, window.getSize().x,100));
    Wejscie.setTexture(wejscie);

    elementysceny Wyjscie(sf::Vector2f(0,(window.getSize().y/2)-50));
    Wyjscie.setPosition(sf::Vector2f(240,window.getSize().y/2-50));
    Wyjscie.setTexture(wyjscie);

    elementysceny Koniec(sf::Vector2f(0,0));
    Koniec.setPosition(sf::Vector2f(0,0));
    Koniec.setTextureRect(sf::IntRect(0, 0, window.getSize().x,50));
    Koniec.setTexture(pas);
    Koniec.setTexture(koniec);



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
        if(event.key.code==sf::Keyboard::P)
        {
            theme.play();
            if(event.key.code==sf::Keyboard::Down)
            {
                theme.setVolume(theme.getVolume()-10);
            }
        }

        std::string s=std::to_string(LVL);
        text.setString(s);


        window.clear(sf::Color::Black);

        window.draw(sprite2);

        window.draw(start);
        window.draw(pas_bezpieczenstwa);
        window.draw(Wejscie);
        window.draw(Wyjscie);
        window.draw(Koniec);
        hero.move(window);
        hero.info(window);
        hero.Lives(window);
        window.draw(hero);


        for (auto &sprit:sprites)
        {
            window.draw(*sprit);
            sprit->Animate();
            sprit->Theme();
            hero.checkCollision(*sprit,window);

        }

        if(hero.Give_Bounds().intersects(koniec_gry.getGlobalBounds()))
        {
            LVL++;

            hero.LVL_(window);
            nexlvlSound.play();
            for(auto &p:sprites)
            {
                p->lvl(window);
                p->lvl2();
                //  p->time_r();
            }

        }
        window.draw(koniec_gry);
        window.draw(text);
        window.draw(poziom);
        window.draw(licznikzyc);

        window.display();
    }
    //    }
    //        break;
    //    case 2:
    //    {



    return 0;
}
