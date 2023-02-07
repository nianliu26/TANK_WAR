#include "widget.h"
#include "ui_widget.h"

#define cout qDebug() << "[" << __FILE__ << " : " << __LINE__ << "]"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    initWindow();

}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent* e) {
    //cout << "进入父窗口键盘响应事件";
    ui->widgetGame->keyEve(e);
    e->ignore();
}


/**
 * @brief Widget::initWindow 初始化窗口，设置各个页面的风格
 */
void Widget::initWindow() {

    //设置窗口风格
    this->setWindowTitle("坦克大战");
    this->setStyleSheet("QWidget{background: black;}");
    this->setFixedSize(700, 500); //设置固定大小
    ui->stackedWidget->setFixedSize(700, 500);

    //设置默认页面
    ui->stackedWidget->setCurrentWidget(ui->pageMainMenu);

    //第一页主菜单页风格设置
    ui->labTitle->setStyleSheet("QLabel{color : red;}");
    ui->btnSingleMode->setStyleSheet("QPushButton{background : red;}");

    //第二页地图选择页风格设置
    ui->labChooseMap->setStyleSheet("QLabel{color : red;}");
    ui->btnStartGame->setStyleSheet("QPushButton{background : red;}");
    ui->mapList->setStyleSheet("QComboBox{background : white;}"
                               "QComboBox QAbstractItemView{background : white;}");
    ui->btnComeBackToMainMenu->setStyleSheet("QPushButton{background : rgb(190,190,190);}");

    //第三页加载页风格设置
    ui->pageLoading->setStyleSheet("QLabel{color : red;}");

    QSize si(ui->labLoading->width(), ui->labLoading->height());
    QMovie* movie = new QMovie(":/img/loading.gif");
    movie->setScaledSize(si);

    ui->labLoading->setMovie(movie);
    movie->start();
    ui->btnComeBackToChooseMap->setStyleSheet("QPushButton{background : rgb(190,190,190);}");

    //设置游戏页的风格
    //ui->widgetGame->setStyleSheet("Widget{background : blue;}");

    //第五页结束页风格设置
    ui->labGameOver->setStyleSheet("QLabel{color : red;}");
    ui->btnGameOver->setStyleSheet("QPushButton{background : red;}");

    //连接游戏结束信号
    connect(ui->widgetGame, &GameWidget::gameOver, this, &Widget::gameOver);
}


/**
 * @brief Widget::strToIntArray 将字符串类型的整数数据转换为一个整形数组
 * @param str 一串只含有空格和数字的字符串
 * @return 返回字符串中数字组成的数组
 */
QVector<int> Widget::strToIntArray(QString const str) {
    int left = 0, right = 0;
    QVector<int> result;

    while (right < str.size() && left <= right) {
        while (left == right && left < str.size() && str[left] == ' ') {
            left++;
            right++;
        }
        while (right < str.size() && str[right] != ' ') {
            right++;
        }

        int re = str.sliced(left, right-left).toInt();
        //cout << re;
        result.push_back(re);
        left = right;
    }

    return result;
}

/**
 * @brief Widget::arrayIsIlleage 判断地图数组是否合法，并创建坦克
 * @return 非法返回true，合法返回false
 */
bool Widget::arrayIsIlleage(int x, int y, QVector<QVector<int>>& array){
    //先判断地图高度是否合法
    if (y != array.size() * TD::unitSize) return true;
    for (int i = 0; i < array.size(); i++) {
        if (x != array[i].size() * TD::unitSize) return true;
        for (int j = 0; j < array[i].size(); j++) {
            //对数据进行处理，遇到表示坦克的数据就增加坦克，并将数据置0
            if (array[i][j] == 1) {
                array[i][j] = 0;
                //表示玩家坦克
                PlayerTank::setPiont(j * TD::unitSize, i * TD::unitSize);
            } else if (array[i][j] == 2) {
                array[i][j] = 0;
                //表示npc坦克
                NPCTank nTank(j * TD::unitSize, i * TD::unitSize);

                npcTank.push_back(nTank);
            }
        }
    }

    return false;
}


void Widget::startGame() {
    //调整窗口大小
    this->setFixedSize(tankMap.getX(), tankMap.getY());
    ui->stackedWidget->setFixedSize(tankMap.getX(), tankMap.getY());
    ui->widgetGame->setFixedSize(tankMap.getX(), tankMap.getY());
    //设置数据
    ui->widgetGame->setMap(tankMap);
    ui->widgetGame->setTanks(npcTank);
    //跳转到游戏页面
    ui->stackedWidget->setCurrentWidget(ui->pageGame);

    GameWidget::gameBegan = true;
}

void Widget::on_btnSingleMode_clicked()
{
    //先将下拉框数据清空
    ui->mapList->clear();

    //读取地图列表的信息
    QString path(mapListPath);
    QFile mapList(path);
    //打开地图列表
    if (mapList.open(QIODeviceBase::ReadOnly)) {
        QStringList list;
        QByteArray array;
        while (!mapList.atEnd()) {
            array = mapList.readLine();
            //cout << array.data();
            list << QString(array).trimmed();
        }

        //给下拉框设置数据
        ui->mapList->addItems(list);

        ui->stackedWidget->setCurrentWidget(ui->pageChooseMap);
    }

}

void Widget::on_btnComeBackToMainMenu_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageMainMenu);
}

void Widget::on_btnStartGame_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageLoading);
    //读取选择的地图资源文件
    //cout << ui->mapList->currentText();
    QString map_name = ui->mapList->currentText();
    QFile map(mapDir+map_name+".txt");
    if (map.open(QIODeviceBase::ReadOnly)) {
        QByteArray str;
        int count = 0;
        int x, y;
        QVector<QVector<int>> map_array;

        while (!map.atEnd()) {
            str = map.readLine().trimmed();
            //cout << QString(str);
            QVector<int> array = strToIntArray(QString(str));
            if (count == 0) {
                x = array[0];
                count++;
            } else if (count == 1) {
                y = array[0];
                count++;
            } else {
                map_array.push_back(array);
                count++;
            }
        }

        if(!arrayIsIlleage(x, y, map_array)) {
            tankMap = TankMap(x, y, map_array);
            startGame();
        } else {

            cout << "地图数据有误";
        }


        map.close();

    } else {
        cout << "没有该文件";
    }

}

void Widget::on_btnComeBackToChooseMap_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageChooseMap);
}

void Widget::gameOver(QString str) {
    ui->labGameOver->setText(str);
    ui->stackedWidget->setCurrentWidget(ui->pageGameOver);

    ui->stackedWidget->setFixedSize(700, 500);
}


void Widget::on_btnGameOver_clicked()
{
    this->setFixedSize(700, 500); //设置固定大小
    ui->stackedWidget->setCurrentWidget(ui->pageMainMenu);
}

