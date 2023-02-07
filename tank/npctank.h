#ifndef NPCTANK_H
#define NPCTANK_H

#include "TANKDATA.h"
#include "shellunit.h"

#include <QString>

class NPCTank
{
private:
    //坦克坐标
    int tank_x;
    int tank_y;
    //坦克图标
    QString tank_icon;
    //坦克速度
    int tank_speed;
    //坦克方向，范围0~3，分别表示从上顺时针方向到左四个方向
    int tank_direction;
    //坦克血量，血量为负数坦克被摧毁
    int HP;
    //开火CD
    int CD;


public:
    NPCTank();
    NPCTank(int x, int y);

    int getX();
    int getY();
    QString getIcon();
    int getSpeed();
    int getDirection();
    int getHP();
    void setPoint(int x, int y);
    void setPiont(int x, int y);
    void changeDirection(int dir);
    void changeMoveStatus(int s);
    void move();
    void reductionHP();
    ShellUnit fire();
    void reduceCD();
    int getCD();
};

#endif // NPCTANK_H
