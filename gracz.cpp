#include "gracz.h"

gracz::gracz(const sf::Vector2f &position):sprite(position)
{
    setPosition(position);
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
void gracz::kolizja_dol(sf::RectangleShape obiekt,sf::RenderWindow &wind)
{
    if(Give_Bounds().intersects(obiekt.getGlobalBounds()))
    {
        Zycia(wind);
        setPosition(sf::Vector2f(450,900));
    }
}
void gracz::kolizja_gora(sf::RectangleShape obiekt,sf::RenderWindow &wind)
{
    if(Give_Bounds().intersects(obiekt.getGlobalBounds()))
    {
        Zycia(wind);
        setPosition(sf::Vector2f(450,900/2));

    }
}
void gracz::kolizja_specjalny(sf::RectangleShape obiekt)
{
    if(Give_Bounds().intersects(obiekt.getGlobalBounds()))
    {

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)||sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            if(Give_Bounds().top >= top_bound)
            {
                //            move(0,(-speed.y));
                setPosition(getPosition().x,getPosition().y+7);

            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)||sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            if(Give_Bounds().left >= left_bound)
            {
                //            move(-speed.x,0);
                setPosition(getPosition().x+7,getPosition().y);

            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)||sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            if(Give_Bounds().top+Give_Bounds().height<=bottom_bound )
            {
                //            move(0, speed.y);
                setPosition(getPosition().x,getPosition().y-7);

            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)||sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            if(Give_Bounds().left+Give_Bounds().width<=right_bound)
            {
                //            move(speed.x,0);
                setPosition(getPosition().x-7,getPosition().y);

            }
        }
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

}
