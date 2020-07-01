#include "gracz.h"
#include"pojazd.h"
#include"pojazd2.h"
#include"pojazdspecjalny.h"
gracz::gracz(const sf::Vector2f &position):sprite(position)
{
    loadTexture(texturePath);
}

void gracz::Zycia(sf::RenderWindow &wind)
{
    zycia--;

    if(zycia<=0)
    {
        wind.close();
        std::cout<<"KONIEC GRY"<<std::endl;
    }


}
void gracz::lvl(sf::RenderWindow&wind)
{

}

void gracz::New_Position()//const int &w)
{

}

void gracz::move(sf::RenderWindow&wind)
{
    if(time.getElapsedTime().asSeconds()>10&&time.getElapsedTime().asSeconds()<15)
    {
        ReverseMove();
    }

    else
    {
        Animate();
    }
    if(time.getElapsedTime().asSeconds()>15)
    {
        time.restart();
    }
   // std::cout<<time.getElapsedTime().asSeconds()<<std::endl;
    std::cout<<getPosition().y<<std::endl;
}
void gracz::lvl2()
{

}

void gracz::Lives(sf::RenderWindow &wind)
{
    font.loadFromFile("Fonts/I-pixel-u.ttf");

    std::string s = std::to_string(zycia);
    text.setString(s);
    text.setFont(font);

    text.setPosition(850,20);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    if(zycia<=3)
    {
        text.setFillColor(sf::Color::Red);
    }
    wind.draw(text);
}

void gracz::sound()
{
    sf::SoundBuffer mov;
    if (!mov.loadFromFile("move.wav"))
    {
        std::cout<<"!!!!!!!!"<<std::endl;
    }
    sf::Sound moveSound(mov);
    moveSound.play();
}

void gracz::checkCollision(sf::Sprite &object, sf::RenderWindow &wind)
{
    if (ObjectCollision(object,wind))
    {
        if (typeid(object) == typeid(Pojazd))
        {
            sound();
            // loadTexture(texturePath2);
            zycia--;

            setPosition(wind.getSize().x/2,wind.getSize().y/2-20);
        }
        if(typeid (object)==typeid (pojazdspecjalny))
        {

            zycia-=5;
            setPosition(wind.getSize().x/2,wind.getSize().y-50);

        }
        else if (typeid(object) == typeid(Pojazd2))
        {
            zycia--;

            setPosition(wind.getSize().x/2,wind.getSize().y-50);
        }
        //        std::cout<<lives<<" ZYC"<<std::endl;
        //        std::cout<<points<<" PUNKTOW"<<std::endl;
    }
}



void gracz::Animate()
{
    sf::Music th;
    if(!th.openFromFile("move.wav"))
    {
        std::cout<<"!!!!!!!!!!!!!!"<<std::endl;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        if(Give_Bounds().top >= top_bound)
        {
            //            move(0,(-speed.y));
            setPosition(getPosition().x,getPosition().y-7);
            th.play();


        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        if(Give_Bounds().left >= left_bound)
        {
            //            move(-speed.x,0);
            setPosition(getPosition().x-7,getPosition().y);

        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if(Give_Bounds().top+Give_Bounds().height<=bottom_bound)
        {
            //            move(0, speed.y);
            setPosition(getPosition().x,getPosition().y+7);

        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        if(Give_Bounds().left+Give_Bounds().width<=right_bound)
        {
            //            move(speed.x,0);
            setPosition(getPosition().x+7,getPosition().y);

        }
    }
    // std::cout<<getPosition().y<<std::endl;
}




void gracz::info(sf::RenderWindow&wind)
{
    font.loadFromFile("Fonts/I-pixel-u.ttf");
    sf::Text text3;
    text3.setFont(font);
    text3.setPosition(100,450);
    text3.setCharacterSize(50);
    if(time.getElapsedTime().asSeconds()>9&&time.getElapsedTime().asSeconds()<11)
    {


        text3.setString("ODWROCONE STEROWANIE");

        text3.setFillColor(sf::Color::Red);
        wind.draw(text3);
    }
    if(time.getElapsedTime().asSeconds()>14)//&&time.getElapsedTime().asSeconds()<12)
    {
        text3.setString("NORMALNE STEROWANIE");

        text3.setFillColor(sf::Color::Blue);
        wind.draw(text3);
    }


}

void gracz::time_r()
{
    time.restart();
}

void gracz::LVL_(sf::RenderWindow&window)
{
    LVL++;
    setPosition(sf::Vector2f(window.getSize().x/2,window.getSize().y-50));
    time_r();
}

void gracz::ReverseMove()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        if(Give_Bounds().top >= top_bound&&Give_Bounds().top+Give_Bounds().height<=bottom_bound)
        {
            setPosition(getPosition().x,getPosition().y+7);
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        if(Give_Bounds().left >= left_bound)
        {
            setPosition(getPosition().x+7,getPosition().y);
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if(Give_Bounds().top+Give_Bounds().height<=bottom_bound &&Give_Bounds().top >= top_bound)
        {
            setPosition(getPosition().x,getPosition().y-7);
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        if(Give_Bounds().left+Give_Bounds().width<=right_bound)
        {
            setPosition(getPosition().x-7,getPosition().y);
        }
    }
}
