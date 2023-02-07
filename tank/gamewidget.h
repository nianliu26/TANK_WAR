#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QVector>
#include <QPixmap>
#include <cmath>
#include <ctime>

#include "tankmap.h"
#include "npctank.h"
#include "TANKDATA.h"
#include "playertank.h"
#include "widget.h"
#include "shellunit.h"

#define random(x) rand()%(x)
#define cout qDebug() << "[" << __FILE__ << " : " << __LINE__ << "]"

class GameWidget : public QWidget
{
    Q_OBJECT
public:

    static bool gameBegan;

    explicit GameWidget(QWidget *parent = nullptr);
    ~GameWidget();
    GameWidget(QWidget* parent, TankMap map, QVector<NPCTank> n);
    void setMap(TankMap map);
    void setTanks(QVector<NPCTank> n);
    bool isMovableInThisDir();
    bool isMovableInThisDir(NPCTank tank);
    bool isMovableInThisDir(ShellUnit shell);
    bool pointIsInWall(int x, int y);
    void keyEve(QKeyEvent* e);

private:
    TankMap tankMap;
    QVector<NPCTank> nTank;
    QVector<ShellUnit> shell;
    int timeID;
    //Widget* parent;

protected:
    void paintEvent(QPaintEvent* e)override;
    void timerEvent(QTimerEvent* e);
    //void keyPressEvent(QKeyEvent* e);


signals:
    void gameOver(QString str);

};

#endif // GAMEWIDGET_H
