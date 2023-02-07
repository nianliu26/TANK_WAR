#ifndef PLAYERTANK_H
#define PLAYERTANK_H

#include <QString>
#include <QDebug>

#include "TANKDATA.h"
#include "shellunit.h"


class PlayerTank
{
private:
    //坦克坐标
    int tank_x;
    int tank_y;
    //坦克图标
    QString tank_icon;
    //坦克速度
    int tank_speed;
    //坦克方向，范围0~3，分别表示从上顺时针到左四个方向
    int tank_direction;
    //坦克血量
    int HP;
    //开火CD
    int CD;
    //移动CD
    int moveCD;
    //坦克对象，实现单例模式
    static PlayerTank* tank;

    PlayerTank();
    PlayerTank(int x, int y);
    PlayerTank(const PlayerTank& other);
    PlayerTank& operator= (const PlayerTank& other);

public:
    static PlayerTank* getPlayerTank(){
        if (tank == NULL) {
            tank = new PlayerTank();
        }

        return tank;
    }

    static int getX() {
        return tank->tank_x;
    }

    static int getY() {
        return tank->tank_y;
    }

    static QString getPlayerIcon() {
        return tank->tank_icon;
    }

    static int getDirection() {
        return tank->tank_direction;
    }

    static int getHP() {
        return tank->HP;
    }

    static int getSpeed() {
        return tank->tank_speed;
    }

    static ShellUnit fire() {
        //开火设置CD
        tank->CD = TD::tankCD / 2;

        //求坦克中心点坐标
        int mid_x = tank->tank_x + TD::unitSize / 2;
        int mid_y = tank->tank_y + TD::unitSize / 2;
        //炮弹生成位置为坦克中心坐标加上方向乘地图单元边长的一半
        int s_x = mid_x + TD::dir[tank->tank_direction][1] * TD::unitSize / 2;
        int s_y = mid_y + TD::dir[tank->tank_direction][0] * TD::unitSize / 2;

        return ShellUnit(s_x, s_y, tank->tank_direction);
    }

    static void reduceCD() {
        if (tank->CD > 0) {
            tank->CD--;
        }
    }

    static int getCD() {
        return tank->CD;
    }

    static void reduceMoveCD() {
        if (tank->moveCD > 0) {
            tank->moveCD--;
        }
    }

    static int getMoveCD() {
        return tank->moveCD;
    }


    /**
     * @brief setPiont 设置坦克坐标
     * @param x
     * @param y
     */
    static void setPiont(int x, int y) {
        tank->tank_x = x;
        tank->tank_y = y;
    }

    /**
     * @brief changeDirection 坦克改变移动方向
     * @param dir
     */
    static void changeDirection(int dir) {
        dir = dir % 4; //确保方向在0~3内
        tank->tank_direction = dir;
        tank->tank_icon = TD::PlayerIcon[dir];
    }

    /**
     * @brief changeMoveStatus 坦克改变移动状态
     */
    static void changeMoveStatus(int s) {
        if (s == 1) tank->tank_speed = TD::moveSpeed;
        else tank->tank_speed = 0;
    }

    /**
     * @brief move 坦克移动方法，注意在调用此方法之前一定要进行碰撞判断
     */
    static void move() {
        //tank->moveCD = 1;
        tank->tank_x += tank->tank_speed * TD::dir[tank->tank_direction][1];
        tank->tank_y += tank->tank_speed * TD::dir[tank->tank_direction][0];
    }

    /**
     * @brief reductionHP 坦克血量减一
     */
    static void reductionHP() {
        tank->HP -= 1;
    }
};

//

#endif // PLAYERTANK_H
