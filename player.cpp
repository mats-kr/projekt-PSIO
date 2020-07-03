#include "player.h"
#include"greencar.h"
#include"redcar.h"
#include"policecar.h"
#include"dhlcar.h"
Player::Player(const sf::Vector2f &position):Sprite(position)
{
    loadTexture(texturePath);
}

void Player::Zycia(sf::RenderWindow &wind)
{
    lives--;

    if(lives<=0)
    {
        wind.close();
        std::cout<<"KONIEC GRY"<<std::endl;
    }


}
void Player::Lvl(sf::RenderWindow&wind)
{

}

void Player::LVL_Counter(sf::RenderWindow&wind)
{
    font.loadFromFile("Fonts/I-pixel-u.ttf");
    std::string s = std::to_string(LVL);
    text.setFont(font);
    text.setPosition(150,10);
    text.setCharacterSize(35);
    text.setFillColor(sf::Color::White);
    text.setOutlineThickness(10);
    text.setOutlineColor(sf::Color::Black);
    text.setString(s);
    wind.draw(text);
}



void Player::move(sf::RenderWindow&wind,const sf::Time &elapsed)
{
    if(time.getElapsedTime().asSeconds()>10&&time.getElapsedTime().asSeconds()<15)
    {
        ReverseMove(elapsed);
    }

    else
    {
        Animate(elapsed);

    }
    if(time.getElapsedTime().asSeconds()>15.5)
    {
        time.restart();
    }
}


void Player::Lives(sf::RenderWindow &wind)
{
    font.loadFromFile("Fonts/I-pixel-u.ttf");

    std::string s = std::to_string(lives);
    text.setString(s);
    text.setFont(font);

    text.setPosition(850,10);
    text.setCharacterSize(35);
    text.setFillColor(sf::Color::White);
    text.setOutlineThickness(10);
    text.setOutlineColor(sf::Color::Black);
    if(lives<=3)
    {
        text.setFillColor(sf::Color::Red);
    }
    wind.draw(text);
    if(lives<=0)
    {
        //wind.close();
    }
}

void Player::movesound()
{
    if (!mov.loadFromFile("move.wav"))
    {
        std::cout<<"!!!!!!!!"<<std::endl;
    }
    moveSound.setBuffer(mov);
    moveSound.play();

}

void Player::hitsound()
{
    if (!ht.loadFromFile("hit.wav"))
    {
        std::cout<<"!!!!!!!!"<<std::endl;
    }
    hitSound.setBuffer(ht);
    hitSound.play();
}

void Player::nextlvlsound()
{
    if (!nextlvl.loadFromFile("lvl.wav"))
    {
        std::cout<<"!!!!!!!!"<<std::endl;
    }
    nextlvlSound.setBuffer(nextlvl);
    nextlvlSound.play();
}

void Player::checkCollision(sf::Sprite &object, sf::RenderWindow &wind)
{
    if (ObjectCollision(object,wind))
    {
        if (typeid(object) == typeid(GreenCar))
        {
            hitsound();
            lives--;
            setPosition(wind.getSize().x/2,wind.getSize().y/2-20);
        }
        if(typeid (object)==typeid (PoliceCar)||typeid (object)==typeid (DhlCar))
        {
            hitsound();
            lives-=5;
            setPosition(wind.getSize().x/2,wind.getSize().y-50);

        }
        else if (typeid(object) == typeid(RedCar))
        {
            lives--;
            hitsound();
            setPosition(wind.getSize().x/2,wind.getSize().y-50);
        }

    }
}

void Player::Start()
{
X=6;
Y=6;
}



void Player::Animate(const sf::Time &elapsed)
{


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {


        if(Give_Bounds().top >= top_bound-10)
        {
            setPosition(getPosition().x,getPosition().y-Y);
            movesound();

        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        if(Give_Bounds().left >= left_bound)
        {
            setPosition(getPosition().x-X,getPosition().y);
            movesound();

        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if(Give_Bounds().top+Give_Bounds().height<=bottom_bound)
        {
            setPosition(getPosition().x,getPosition().y+Y);
            movesound();

        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        if(Give_Bounds().left+Give_Bounds().width<=right_bound)
        {
            setPosition(getPosition().x+X,getPosition().y);
            movesound();

        }
    }

}




void Player::info(sf::RenderWindow&wind)
{
    font.loadFromFile("Fonts/I-pixel-u.ttf");
    sf::Text text3;
    text3.setFont(font);
    text3.setPosition(100,450);
    text3.setCharacterSize(50);
    if(time.getElapsedTime().asSeconds()>9&&time.getElapsedTime().asSeconds()<12)
    {


        text3.setString("ODWROCONE STEROWANIE");

        text3.setFillColor(sf::Color::Red);
        text3.setOutlineThickness(10);
        text3.setOutlineColor(sf::Color::Black);
        wind.draw(text3);

    }
    if(time.getElapsedTime().asSeconds()>14)
    {
        text3.setString("NORMALNE STEROWANIE");
        text3.setFillColor(sf::Color::Blue);
        text3.setOutlineThickness(10);
        text3.setOutlineColor(sf::Color::Black);
        wind.draw(text3);
    }


}

void Player::TimeReset()
{
    time.restart();
}


void Player::LVL_(sf::RenderWindow&window)
{
    LVL++;
    setPosition(sf::Vector2f(window.getSize().x/2,window.getSize().y-50));
    TimeReset();
}

void Player::ReverseMove(const sf::Time &elapsed)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        if(Give_Bounds().top >= top_bound-10&&Give_Bounds().top+Give_Bounds().height<bottom_bound)
        {
            setPosition(getPosition().x,getPosition().y+Y);
            movesound();

        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        if(Give_Bounds().left >= left_bound)
        {
            setPosition(getPosition().x+X,getPosition().y);
            movesound();

        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if(Give_Bounds().top+Give_Bounds().height<=bottom_bound+50 &&Give_Bounds().top >= top_bound)
        {
            setPosition(getPosition().x,getPosition().y-Y);
            movesound();

        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        if(Give_Bounds().left+Give_Bounds().width<=right_bound)
        {
            setPosition(getPosition().x-X,getPosition().y);
            movesound();

        }
    }
}
