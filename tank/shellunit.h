#ifndef SHELLUNIT_H
#define SHELLUNIT_H

#include "TANKDATA.h"

class ShellUnit
{
private:
    //炮弹圆心坐标
    int shell_x;
    int shell_y;
    //炮弹半径
    int shell_r;
    //炮弹速度
    int shell_speed;
    //移动方向
    int shell_direction;

public:
    ShellUnit();
    ShellUnit(int x, int y, int dir);
    int getX();
    int getY();
    int getR();
    int getSpeed();
    void move();
};

#endif // SHELLUNIT_H
