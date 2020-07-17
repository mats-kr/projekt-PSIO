#include "scenelabels.h"

SceneLabels::SceneLabels(sf::RenderWindow&wind ,const std::string &path,const int& posX
                         ,sf::Color(fillcolor),const int& posY,const int & rectY ,const bool & check,const int &x)
    :SceneElements(wind,path,posX,posY,rectY,check,x)
{
    LoadFont();
    lvl.setFont(font);
    lvl.setString(path);
    lvl.setPosition(posX,posY);
    lvl.setCharacterSize(rectY);
    lvl.setFillColor(sf::Color(fillcolor));
    lvl.setOutlineThickness(10);
    lvl.setOutlineColor(sf::Color::Black);
}

void SceneLabels::LoadFont()
{
    font.loadFromFile("Fonts/I-pixel-u.ttf");
}
void SceneLabels::DisplayInstructions(sf::RenderWindow &wind)
{
    description.setFont(font);
    description.setPosition(30,50);
    description.setCharacterSize(40);
    description.setOutlineThickness(10);
    description.setString("\n DABGEROUS ROAD \n"
                          " GRACZ MUSI PRZEJSC NA DRUGA \n"
                          " STRONE AUTOSTRADY UNIKAJAC \n"
                          " KOLIZJI Z INNYMI POJZDAMI. \n"
                          " KOLIZJA Z POJAZDEM ZWYKLYM \n"
                          " (CZERWONY LUB ZIELONY \n SAMOCHOD)"
                          " POWODUJE UTRATE \n JEDNEGO ZYCIA "
                          " ORAZ COFNIECIE \n NA MIEJSCE STARTU "
                          " LUB PAS \n BEZPIECZENSTWA.\n"
                          " KOLIZJA Z POJAZDEM SPECJALNYM\n"
                          " POWODUJE POWRÓT NA MIEJSCE \n STARTU"
                          " ORAZ UTRATE 5 ZYC \n  "
                          " \n \n ABY ROZPOCZAC GRE WCISNIJ { P }");
    wind.draw(description);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
    {
        description.setFillColor(sf::Color::Transparent);
        description.setOutlineColor(sf::Color::Transparent);
    }
}
void SceneLabels::MoveInfo(sf::RenderWindow&wind)
{
    text3.setFont(font);
    text3.setPosition(100,450);
    text3.setCharacterSize(50);
    if(time.getElapsedTime().asSeconds()>10.0&&time.getElapsedTime().asSeconds()<12.5)
    {
        text3.setString("ODWROCONE STEROWANIE");
        text3.setFillColor(sf::Color::Red);
        text3.setOutlineThickness(10);
        text3.setOutlineColor(sf::Color::Black);
        wind.draw(text3);
    }
    if(time.getElapsedTime().asSeconds()>15)
    {
        text3.setString("NORMALNE STEROWANIE");
        text3.setFillColor(sf::Color::Blue);
        text3.setOutlineThickness(10);
        text3.setOutlineColor(sf::Color::Black);
        wind.draw(text3);
    }
    if(time.getElapsedTime().asSeconds()>17)
    {
        time.restart();
    }
}
void SceneLabels::DrawObject(sf::RenderWindow &wind, sf::Text &tex)
{
    wind.draw(tex);
}
void SceneLabels::RenderInfo(sf::RenderWindow &wind)
{
    DisplayInstructions(wind);
}
void SceneLabels::Render(sf::RenderWindow &wind)
{
    MoveInfo(wind);
    DrawObject(wind,lvl);
}

