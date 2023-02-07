#include "playertank.h"

#define cout qDebug() << "[" << __FILE__ << " : " << __LINE__ << "]"


int TD::dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

QString TD::PlayerIcon[4] = {
    "../src/img/p1tankU.png", "../src/img/p1tankR.png", "../src/img/p1tankD.png", "../src/img/p1tankL.png"
};

PlayerTank::PlayerTank():
    tank_icon(TD::PlayerIcon[0]), tank_direction(0),
    tank_speed(TD::moveSpeed ), HP(2), CD(0), moveCD(0){}

PlayerTank::PlayerTank(int x, int y):
    tank_x(x), tank_y(y), tank_icon(TD::PlayerIcon[0]){}

PlayerTank* PlayerTank::tank = new PlayerTank();
