#include "tankmap.h"

#define cout qDebug() << "[" << __FILE__ << " : " << __LINE__ << "]"

const QString map_wall = ":/img/1_1.png";

TankMap::TankMap(){}

TankMap::TankMap(int x, int y, QVector<QVector<int> > array):
    map_x(x), map_y(y), map_array(array){
    //在map的构造方法中绘制地图
    map_img = QImage(map_x, map_y, QImage::Format_ARGB32);
    QPainter painter;

    painter.begin(&map_img);

    QBrush brush;
    brush.setColor(Qt::black);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);


    for (int i = 0; i < map_array.size(); i++) {
        //cout << map_array[i];
        for (int j = 0; j < map_array[i].size(); j++) {
            if (map_array[i][j] == -1) {
                QSize si(TD::unitSize, TD::unitSize);
                QPixmap pm(map_wall);
                pm.scaled(TD::unitSize, TD::unitSize);
                painter.drawPixmap(j * TD::unitSize, i * TD::unitSize, TD::unitSize, TD::unitSize, pm);
            } else {
                //画黑色矩形
                painter.drawRect(j * TD::unitSize, i * TD::unitSize, TD::unitSize, TD::unitSize);
            }
        }
    }
    map_img.save("../mapImg.png");

    painter.end();
}

int TankMap::getX() {
    return this->map_x;
}
int TankMap::getY() {
    return this->map_y;
}
QImage TankMap::getImg() {
    return this->map_img;
}

QVector<QVector<int>> TankMap::getArray() {
    return this->map_array;
}
