#ifndef WIDGET_H
#define WIDGET_H



#include "tankmap.h"
#include "TANKDATA.h"
#include "playertank.h"
#include "npctank.h"

#include <QComboBox>
#include <QFile>
#include <QMovie>
#include <QSize>
#include <QDebug>
#include <QWidget>
#include <QVector>
#include <TANKDATA.h>
#include <QEvent>
#include <QPaintEvent>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

//const QString mapListPath = "../src/map/mapList.txt";
const QString mapDir = "../src/map/"; //地图资源文件夹
const QString mapListPath = mapDir + "mapList.txt";


//TankMap tankMap;

class Widget : public QWidget
{
    Q_OBJECT

public:

    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void keyPressEvent(QKeyEvent* e);
    //bool eventFilter(QObject *watched, QEvent *event);

private slots:
    void on_btnSingleMode_clicked();

    void on_btnComeBackToMainMenu_clicked();

    void on_btnStartGame_clicked();

    void on_btnComeBackToChooseMap_clicked();

    void gameOver(QString str);

    void on_btnGameOver_clicked();

private:
    Ui::Widget *ui;

    TankMap tankMap;
    QVector<NPCTank> npcTank;

    void initWindow();
    QVector<int> strToIntArray(QString const str);
    bool arrayIsIlleage(int x, int y, QVector<QVector<int>>& array);
    void startGame();
};
#endif // WIDGET_H
