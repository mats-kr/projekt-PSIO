#include <iostream>

using namespace std;

class hero
{

public:

    hero(const sf::Vector2f &size,const sf::Vector2f &position);

    void setSpeed(int speed_x,int speed_y);
    void animate();
    void collision();
    void setBounds(const int &left,const int &right,const int& top,const int &bottom);




private:

    int speedX;
    int speedY;
    int left_bound=0.0;
    int right_bound=800.0;
    int top_bound=0.0 ;
    int bottom_bound=600.0;





};

class car
{


    public:

        hero(const sf::Vector2f &size,const sf::Vector2f &position);

        void setSpeed(int speed_x);
        void move();
        void collision();
        void setBounds(const int &left,const int &right,const int& top,const int &bottom);




    private:

        int speedX;
        int left_bound=0.0;
        int right_bound=800.0;
        int top_bound=0.0 ;
        int bottom_bound=600.0;





    };

