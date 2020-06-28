#include "gracz.h"
#include"pojazd.h"
#include"pojazd2.h"
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
    wind.draw(text);
}

void gracz::checkCollision(sf::Sprite &object, sf::RenderWindow &wind)
{
    if (ObjectCollision(object,wind))
    {
        if (typeid(object) == typeid(Pojazd))
        {
            setPosition(wind.getSize().x/2,wind.getSize().y/2-20);
        }
        else if (typeid(object) == typeid(Pojazd2))
        {
            setPosition(wind.getSize().x/2,wind.getSize().y-50);
        }
        //        std::cout<<lives<<" ZYC"<<std::endl;
        //        std::cout<<points<<" PUNKTOW"<<std::endl;
    }
}



void gracz::Animate()
{

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)||sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        if(Give_Bounds().top >= top_bound)
        {
            //            move(0,(-speed.y));
            setPosition(getPosition().x,getPosition().y-7);

        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)||sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        if(Give_Bounds().left >= left_bound)
        {
            //            move(-speed.x,0);
            setPosition(getPosition().x-7,getPosition().y);

        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)||sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if(Give_Bounds().top+Give_Bounds().height<=bottom_bound )
        {
            //            move(0, speed.y);
            setPosition(getPosition().x,getPosition().y+7);

        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)||sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        if(Give_Bounds().left+Give_Bounds().width<=right_bound)
        {
            //            move(speed.x,0);
            setPosition(getPosition().x+7,getPosition().y);

        }
    }
    std::cout<<getPosition().y<<std::endl;
}






//void sprite::ReverseMove()
//{
//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)||sf::Keyboard::isKeyPressed(sf::Keyboard::W))
//    {
//        if(Give_Bounds().top >= top_bound)
//        {
//            //            move(0,(-speed.y));
//            setPosition(getPosition().x,getPosition().y+7);

//        }
//    }
//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)||sf::Keyboard::isKeyPressed(sf::Keyboard::A))
//    {
//        if(Give_Bounds().left >= left_bound)
//        {
//            //            move(-speed.x,0);
//            setPosition(getPosition().x+7,getPosition().y);

//        }
//    }
//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)||sf::Keyboard::isKeyPressed(sf::Keyboard::S))
//    {
//        if(Give_Bounds().top+Give_Bounds().height<=bottom_bound )
//        {
//            //            move(0, speed.y);
//            setPosition(getPosition().x,getPosition().y-7);

//        }
//    }
//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)||sf::Keyboard::isKeyPressed(sf::Keyboard::D))
//    {
//        if(Give_Bounds().left+Give_Bounds().width<=right_bound)
//        {
//            //            move(speed.x,0);
//            setPosition(getPosition().x-7,getPosition().y);

//        }
//    }
//}
