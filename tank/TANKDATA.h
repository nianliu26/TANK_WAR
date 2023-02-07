#ifndef TANKDATA_H
#define TANKDATA_H

#include <QString>
#include <QVector>

class TD {
public:
    //static const QString mapDir; //地图资源文件夹
    static const int unitSize = 66; //每个地图单元的边长
    static const int shellSize = 10; //炮弹的半径
    static const int shellSpeed = 11; //炮弹速度
    static const int moveSpeed = 3; //移动的速度，在本项目中取地图单元边长的1/3
    static const int fullHP = 3; //坦克满血血量
    static const int tankCD = 20; //坦克开火cd
    static int dir[4][2];

    //保存坦克图标，表示不同移动方向
    static QString PlayerIcon[4];
    //保存npc坦克的图标，行表示不同的移动方向，列表示不同的血量
    static QString NpcIcon[4][3];
};


#endif // TANKDATA_H
