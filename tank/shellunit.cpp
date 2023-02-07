#include "shellunit.h"

ShellUnit::ShellUnit()
{

}


ShellUnit::ShellUnit(int x, int y, int dir):
    shell_x(x + 2 * TD::shellSize * TD::dir[dir][1]),
    shell_y(y + 2 * TD::shellSize * TD::dir[dir][0]),
    shell_speed(TD::shellSpeed), shell_r(TD::shellSize), shell_direction(dir){}

int ShellUnit::getX() {
    return this->shell_x;
}
int ShellUnit::getY() {
    return this->shell_y;
}
int ShellUnit::getR() {
    return this->shell_r;
}
int ShellUnit::getSpeed() {
    return this->shell_speed;
}

void ShellUnit::move() {
    shell_x += shell_speed * TD::dir[shell_direction][1];
    shell_y += shell_speed * TD::dir[shell_direction][0];
}
