#include "npctank.h"
#include <QDebug>

#define cout qDebug() << "[" << __FILE__ << " : " << __LINE__ << "]"

//int TD::dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

QString TD::NpcIcon[4][3] = {
    {"../src/img/enemy2U.png", "../src/img/enemy1U.png", "../src/img/enemy3U.png"},
    {"../src/img/enemy2R.png", "../src/img/enemy1R.png", "../src/img/enemy3R.png"},
    {"../src/img/enemy2D.png", "../src/img/enemy1D.png", "../src/img/enemy3D.png"},
    {"../src/img/enemy2L.png", "../src/img/enemy1L.png", "../src/img/enemy3L.png"}
};


NPCTank::NPCTank(){}

NPCTank::NPCTank(int x, int y):
    tank_x(x), tank_y(y), tank_direction(1), HP(2), CD(0),
    tank_icon(TD::NpcIcon[1][2]), tank_speed(TD::moveSpeed){}

int NPCTank::getX() {
    return this->tank_x;
}

int NPCTank::getY() {
    return this->tank_y;
}


QString NPCTank::getIcon() {
    this->tank_icon = TD::NpcIcon[this->tank_direction][this->HP];
    return this->tank_icon;
}

int NPCTank::getSpeed() {
    return this->tank_speed;
}

int NPCTank::getDirection() {
    return this->tank_direction;
}
int NPCTank::getHP() {
    return this->HP;
}

ShellUnit NPCTank::fire() {
    //开火进入cd
    this->CD = TD::tankCD;

    //求坦克中心点坐标
    int mid_x = tank_x + TD::unitSize / 2;
    int mid_y = tank_y + TD::unitSize / 2;
    //炮弹生成位置为坦克中心坐标加上方向乘地图单元边长的一半
    int s_x = mid_x + TD::dir[tank_direction][1] * TD::unitSize / 2;
    int s_y = mid_y + TD::dir[tank_direction][0] * TD::unitSize / 2;

    return ShellUnit(s_x, s_y, this->tank_direction);
}

void NPCTank::reduceCD() {
    if (this->CD > 0) {
        this->CD--;
    }
}

int NPCTank::getCD() {
    return this->CD;
}

/**
 * @brief setPiont 设置坦克坐标
 * @param x
 * @param y
 */
void NPCTank::setPiont(int x, int y) {
    this->tank_x = x;
    this->tank_y = y;
}

/**
 * @brief changeDirection 坦克改变移动方向
 * @param dir
 */
void NPCTank::changeDirection(int dirc) {
    dirc = dirc % 4; //确保方向在0~3内
    this->tank_direction = dirc;
    //cout << "改变方向为：" << dirc;
    this->tank_icon = TD::NpcIcon[dirc][this->HP];
}

/**
 * @brief changeMoveStatus 坦克改变移动状态
 */
void NPCTank::changeMoveStatus(int s) {
    if (s == 1) this->tank_speed = TD::moveSpeed;
    else this->tank_speed = 0;
}

/**
 * @brief move 坦克移动方法，注意在调用此方法之前一定要进行碰撞判断
 */
void NPCTank::move() {

//    cout << "当前移动方向 : (" << TD::dir[this->tank_direction][1] << ", "
//         << TD::dir[this->tank_direction][0] << ")";
    this->tank_x += this->tank_speed * TD::dir[this->tank_direction][1];
    this->tank_y += this->tank_speed * TD::dir[this->tank_direction][0];
}

/**
 * @brief NPCTank::reductionHP 坦克血量减一
 */
void NPCTank::reductionHP() {
    this->HP -= 1;
}
