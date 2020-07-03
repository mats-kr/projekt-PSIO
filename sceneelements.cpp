#include "sceneelements.h"
SceneElements::SceneElements(const sf::Vector2f &position):Sprite(position)
{
    setPosition(position);
}

void SceneElements::Lvl(sf::RenderWindow&wind)
{
    std::abs(speed.x++);
    std::cout<<speed.x<<" gora"<<std::endl;
}
void SceneElements::Lvl2()
{
    std::abs(speed.x--);
    std::cout<<speed.x<<" dol"<<std::endl;
}
void SceneElements::Animate(const sf::Time &elapsed)
{

}

void SceneElements::displayInfo(sf::RenderWindow &wind)
{

    font.loadFromFile("Fonts/I-pixel-u.ttf");
    opis.setFont(font);
    opis.setPosition(30,50);
    opis.setCharacterSize(40);
    opis.setOutlineThickness(10);

    opis.setString("\n DABGEROUS ROAD \n"
                   " GRACZ MUSI PRZEJSC NA DRUGA \n"
                   " STRONE AUTOSTRADY UNIKAJAC \n"
                   " KOLIZJI Z INNYMI POJZDAMI. \n"
                   " KOLIZJA Z POJAZDEM ZWYKLYM \n"
                   " (CZERWONY LUB ZIELONY \n SAMOCHOD)"
                   " POWODUJE UTRATE \n JEDNEGO ZYCIA "
                   " ORAZ COFNIECIE \n NA MIEJSCE STARTU "
                   " LUB PAS \n BEZPIECZENSTWA. "
                   " \n \n ABY ROZPOCZAC GRE WCISNIJ { P }");
    wind.draw(opis);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
    {
        opis.setFillColor(sf::Color::Transparent);
        opis.setOutlineColor(sf::Color::Transparent);
        std::cout<<"DZIALA"<<std::endl;

    }

}



void SceneElements::MenuBackground(sf::RenderWindow &wind)
{

    setPosition(sf::Vector2f(20,50));
    if (!back.loadFromFile("wejscie.PNG"))
    {
        std::cout<<"!!!!!"<<std::endl;
    }
    setTexture(back);

}




void SceneElements::renderEnter(sf::RenderWindow&wind)
{
    setPosition(sf::Vector2f(wind.getSize().x/2-90,(wind.getSize().y/2)-50));
    if (!entrace.loadFromFile("wejscie.PNG"))
    {
        std::cout<<"!!!!!"<<std::endl;
    }
    setTexture(entrace);


}

void SceneElements::renderExit(sf::RenderWindow &wind)
{
    setPosition(sf::Vector2f(240,wind.getSize().y/2-50));
    exit.loadFromFile("wyjscie.PNG");
    setTexture(exit);
}

void SceneElements::renderLaine(sf::RenderWindow &wind)
{
    if (!safetyroad.loadFromFile("pas.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
    }
    safetyroad.setRepeated(true);

    setPosition(sf::Vector2f(0,(wind.getSize().y/2)-50));
    setTextureRect(sf::IntRect(0, 0, wind.getSize().x,100));
    setTexture(safetyroad);
}

void SceneElements::renderEnd(sf::RenderWindow &wind)
{

    setPosition(wind.getSize().x/2-40,-69);
    end.loadFromFile("END.PNG");
    setTexture(end);

}

void SceneElements::renderScreenEnd(sf::RenderWindow &wind)
{
    screenend.loadFromFile("koniecekranu.PNG");
    screenend.setRepeated(true);
    setPosition(sf::Vector2f(0,0));
    setTextureRect(sf::IntRect(0, 0, wind.getSize().x,50));
    setTexture(screenend);
}

void SceneElements::renderStart(sf::RenderWindow &wind)
{
    if (!safetyroad.loadFromFile("dolnypas.png"))
    {
        std::cerr << "Could not load texture" << std::endl;
    }
    safetyroad.setRepeated(true);

    setPosition(sf::Vector2f(0,wind.getSize().y-50));
    setTextureRect(sf::IntRect(0, 0, wind.getSize().x,100));
    setTexture(safetyroad);
}

void SceneElements::renderRoad(sf::RenderWindow &wind)
{
    if (!texture2.loadFromFile("droga4.PNG"))
    { std::cout<<"dsd"<<std::endl; }
    texture2.setRepeated(true);
    sf::Sprite sprite2;
    sprite2.setTexture(texture2);
    sprite2.setTextureRect(sf::IntRect(0, 3, 900, 1000));
    wind.draw(sprite2);
}

void SceneElements::renderLivesString(sf::RenderWindow &wind)
{
    font.loadFromFile("Fonts/I-pixel-u.ttf");

    livescounter.setFont(font);
    livescounter.setString("ZYCIA:");
    livescounter.setPosition(745,20);
    livescounter.setCharacterSize(24);
    livescounter.setOutlineThickness(10);
    livescounter.setOutlineColor(sf::Color::Black);
    livescounter.setFillColor(sf::Color::Green);
    wind.draw(livescounter);
}

void SceneElements::renderLvlString(sf::RenderWindow &wind)
{
    font.loadFromFile("Fonts/I-pixel-u.ttf");

    lvl.setFont(font);
    lvl.setString("POZIOM:");
    lvl.setPosition(23,20);
    lvl.setCharacterSize(24);
    lvl.setFillColor(sf::Color::Cyan);
    lvl.setOutlineThickness(10);
    lvl.setOutlineColor(sf::Color::Black);
    wind.draw(lvl);
}

void SceneElements::Start()
{

}

