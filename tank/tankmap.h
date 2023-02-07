#ifndef TANKMAP_H
#define TANKMAP_H

#include <QVector>
#include <QImage>
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QString>
#include <QSize>
#include <QPixmap>
#include <QDebug>

#include "TANKDATA.h"

class TankMap
{
private:
    int map_x;
    int map_y;
    QVector<QVector<int> > map_array;
    QImage map_img;
public:
    TankMap();
    TankMap(int x, int y, QVector<QVector<int> > array);
    int getX();
    int getY();
    QImage getImg();
    QVector<QVector<int>> getArray();
};

#endif // TANKMAP_H
