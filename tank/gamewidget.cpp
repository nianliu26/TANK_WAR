#include "gamewidget.h"

bool GameWidget::gameBegan = false;


GameWidget::GameWidget(QWidget *parent)
    : QWidget{parent}
{
    //parent = (Widget*) parentWidget();
    timeID = this->startTimer(50);

}

GameWidget::GameWidget(QWidget *parent, TankMap map, QVector<NPCTank> n)
    : QWidget{parent}, tankMap(map), nTank(n)
{

}

GameWidget::~GameWidget(){
    this->killTimer(timeID);
}


void GameWidget::setMap(TankMap map) {
    tankMap = map;
}
void GameWidget::setTanks(QVector<NPCTank> n) {
    nTank = n;
}



void GameWidget::timerEvent(QTimerEvent *e) {
    //移动
//    if (!isMovableInThisDir()) PlayerTank::changeMoveStatus(0);
//    else PlayerTank::changeMoveStatus(1);
//    PlayerTank::move();
    //减玩家开火CD和移动CD
    PlayerTank::reduceCD();
    PlayerTank::reduceMoveCD();

    //炮弹移动
    typedef QVector<ShellUnit>::iterator SIT;
    SIT sit = shell.begin();
    while (sit != shell.end() ) {
        if (!isMovableInThisDir(*sit)) {
            sit = shell.erase(sit);
        } else {
            (*sit).move();
            sit++;
        }
    }

    //npc移动
    typedef QVector<NPCTank>::iterator TIT;
    for (TIT tit = nTank.begin(); tit != nTank.end(); tit++) {
        //遍历到此npc，cd就减少
        (*tit).reduceCD();

        //检测转向之后，前方是否有玩家
        //获取玩家的中心位置
        int p_x = PlayerTank::getX() + TD::unitSize / 2;
        int p_y = PlayerTank::getY() + TD::unitSize / 2;

        //获取npc坦克的中心位置
        int n_x = (*tit).getX() + TD::unitSize / 2;
        int n_y = (*tit).getY() + TD::unitSize / 2;

        if (abs(p_x - n_x) < TD::unitSize / 2 && (p_y - n_y) * TD::dir[(*tit).getDirection()][0] > 0 ||
                abs(p_y - n_y) < TD::unitSize / 2 && (p_x - n_x) * TD::dir[(*tit).getDirection()][0] >= 0) {
            if ((*tit).getCD() == 0) {

                shell.push_back((*tit).fire());
            }
        } else {

        }

        //如果当前刚好在空白地图单元上，就做随机转向
        if ((*tit).getX() % TD::unitSize == 0 && (*tit).getY() % TD::unitSize == 0) {
            //srand((int)time(0));
            int dirc = random(4);
            (*tit).changeDirection(dirc);

        }

        if (!isMovableInThisDir((*tit))) {
            //不停止，而是右转
            int dirc = (*tit).getDirection() + 1;
            (*tit).changeDirection(dirc);
        }
        else {
            (*tit).move();
        }



    }
    //刷新地图
    this->update();

    if (GameWidget::gameBegan && PlayerTank::getHP() < 0) {
        gameBegan = false;
        emit gameOver("DEFEAT");
    } else if (GameWidget::gameBegan && nTank.size() == 0) {
        gameBegan = false;
        emit gameOver("WIN");
    }
}


void GameWidget::paintEvent(QPaintEvent* e) {
    //cout << "开始绘图...";
    //地图刷新
    QPainter painter;
    painter.begin(this);

    //cout << "开始游戏页面绘图";
    QPixmap pm("../mapimg.png");
    pm.scaled(tankMap.getX(), tankMap.getY());
    painter.drawPixmap(0, 0, pm);


    //设置坦克
    //绘制玩家坦克
    QPixmap tk(PlayerTank::getPlayerIcon());
    tk.scaled(TD::unitSize, TD::unitSize);
    painter.drawPixmap(PlayerTank::getX(), PlayerTank::getY(), tk);

    //绘制npc坦克
    for (int i = 0; i < nTank.size(); i++) {
        //cout << "npc:" <<nTank[i].getIcon();

        QPixmap k(nTank[i].getIcon());
        k.scaled(TD::unitSize, TD::unitSize);
        painter.drawPixmap(nTank[i].getX(), nTank[i].getY(), k);
    }

    //绘制炮弹
    typedef QVector<ShellUnit>::iterator SIT;
    //cout << "要画 " << shell.size() << "个炮弹";
    for (SIT sit = shell.begin(); sit != shell.end(); sit++) {
        QBrush brush;
        brush.setColor(Qt::white);
        brush.setStyle(Qt::SolidPattern);
        painter.setBrush(brush);

        int x = (*sit).getX();
        int y = (*sit).getY();

        painter.drawEllipse(x, y, TD::shellSize, TD::shellSize);
    }


    painter.end();
    //cout << "绘图结束";
}

/*
void GameWidget::keyPressEvent(QKeyEvent* e) {
    int dir = PlayerTank::getDirection();
    cout << "按下了按键";
    switch(e->key()) {
        case Qt::Key_W:
        cout << "按下了W";
            //向上移动
            dir = 0; break;
        case Qt::Key_A:
        cout << "按下了A";
            //向左移动
            dir = 3; break;
        case Qt::Key_S:
        cout << "按下了S";
            //向下移动
            dir = 2; break;
        case Qt::Key_D:
        cout << "按下了D";
            //向右移动
            dir = 1; break;
    }

    //改变方向
    PlayerTank::changeDirection(dir);
    //移动
    if (!isMovableInThisDir()) PlayerTank::changeMoveStatus(0);
    else PlayerTank::changeMoveStatus(1);
    if (PlayerTank::getMoveCD() == 0) {

        PlayerTank::move();
    }

    if (e->key() == Qt::Key_J && PlayerTank::getCD() == 0) {
        shell.push_back(PlayerTank::fire());
    }

}
*/

void GameWidget::keyEve(QKeyEvent *e) {
    int dir = PlayerTank::getDirection();
    //cout << "按下了按键";

    if (e->key() == Qt::Key_J && PlayerTank::getCD() == 0) {
        shell.push_back(PlayerTank::fire());
    } else if (e->key() == Qt::Key_W || e->key() == Qt::Key_A ||
               e->key() == Qt::Key_S || e->key() == Qt::Key_D){
        switch(e->key()) {
            case Qt::Key_W:
                //向上移动
                dir = 0; break;
            case Qt::Key_A:
                //向左移动
                dir = 3; break;
            case Qt::Key_S:
                //向下移动
                dir = 2; break;
            case Qt::Key_D:
                //向右移动
                dir = 1; break;
        }

        //改变方向
        PlayerTank::changeDirection(dir);
        //移动
//        if (!isMovableInThisDir()) PlayerTank::changeMoveStatus(0);
//        else PlayerTank::changeMoveStatus(1);
        if (isMovableInThisDir() && PlayerTank::getMoveCD() == 0) {

            PlayerTank::move();
        }
    }

}

//判断当前方向是否可以移动，即做碰撞判断
//有三个重载方法，分别用于玩家、npc、炮弹
bool GameWidget::isMovableInThisDir() {
    //计算进行下一次移动后，四个点的坐标是否在墙里
    int x = PlayerTank::getX() + PlayerTank::getSpeed() * TD::dir[PlayerTank::getDirection()][1];
    int y = PlayerTank::getY() + PlayerTank::getSpeed() * TD::dir[PlayerTank::getDirection()][0];
    int point_x = x + TD::unitSize - 1;
    int point_y = y + TD::unitSize - 1;

    if (pointIsInWall(x, y) || pointIsInWall(point_x, y) || pointIsInWall(x, point_y) || pointIsInWall(point_x, point_y)) {
        //撞墙
        //cout << "撞墙";
        return false;
    }

    //判断是否会与npc坦克相撞
    typedef QVector<NPCTank>::iterator NIT;
    for (NIT nit = nTank.begin(); nit != nTank.end(); nit++) {
        int n_x = (*nit).getX();
        int n_y = (*nit).getY();

        if (abs(x - n_x) < TD::unitSize && abs(y - n_y) < TD::unitSize) {
            return false;
        }
    }

    return true;
}
bool GameWidget::isMovableInThisDir(NPCTank tank) {
    //cout << "当前坐标: (" << tank.getX() << ", " << tank.getY() << ")";

    //计算进行下一次移动后，四个点的坐标是否在墙里
    int x = tank.getX() + tank.getSpeed() * TD::dir[tank.getDirection()][1];
    int y = tank.getY() + tank.getSpeed() * TD::dir[tank.getDirection()][0];
    int point_x = x + TD::unitSize - 1;
    int point_y = y + TD::unitSize - 1;

    if (pointIsInWall(x, y) || pointIsInWall(point_x, y) || pointIsInWall(x, point_y) || pointIsInWall(point_x, point_y)) {
        //cout << "撞墙: " << "(" << x << ", " << y << ")";
        return false;
    }

    //是否会与玩家坦克相撞
    int p_x = PlayerTank::getX();
    int p_y = PlayerTank::getY();

    if (abs(x - p_x) < TD::unitSize && abs(y - p_y) < TD::unitSize) {
        //cout << "撞玩家";
        return false;
    }

    //判断是否会与其他npc坦克相撞
    typedef QVector<NPCTank>::iterator NIT;
    for (NIT nit = nTank.begin(); nit != nTank.end(); nit++) {
        int n_x = (*nit).getX();
        int n_y = (*nit).getY();
        if (n_x == tank.getX() && n_y == tank.getY()) {
            //说明是自身，继续循环
            continue;
        }

        if (abs(x - n_x) < TD::unitSize && abs(y - n_y) < TD::unitSize) {
            //cout << "撞npc";
            return false;
        }
    }

    return true;
}
bool GameWidget::isMovableInThisDir(ShellUnit shell) {
    int x = shell.getX();
    int y = shell.getY();
    //先判断炮弹是否打在了墙上
    if (pointIsInWall(x, y)) {
            return false;
    }
    //判断是否打在了玩家上，如果是将玩家HP减一
    int p_x = PlayerTank::getX();
    int p_y = PlayerTank::getY();

    int point_x = p_x + TD::unitSize;
    int point_y = p_y + TD::unitSize;

    if (x >= p_x && x <= point_x && y >= p_y && y <= point_y) {
        //击中玩家
        PlayerTank::reductionHP(); //血量减一
        //TODO 血量为0结束游戏
        return false;
    }

    //判断是否打在了npc上
    typedef QVector<NPCTank>::iterator NIT;
    NIT nit = nTank.begin();
    while (nit != nTank.end() ) {
        int n_x = (*nit).getX();
        int n_y = (*nit).getY();

        int npoint_x = n_x + TD::unitSize;
        int npoint_y = n_y + TD::unitSize;

        if (x >= n_x && x <= npoint_x && y >= n_y && y <= npoint_y) {
            //击中npc
            (*nit).reductionHP(); //血量减一
            if ((*nit).getHP() < 0 ) {
                nit = nTank.erase(nit);
            } else {
                nit++;
            }
            return false;
        } else {
            nit++;
        }
    }

    return true;
}

bool GameWidget::pointIsInWall(int x, int y) {
    int i = y / TD::unitSize;
    int j = x / TD::unitSize;

    //cout << "i :" << i << "; j :" << j;

    QVector<QVector<int>> array = tankMap.getArray();

    if (x <= 0 || y <= 0 || x >= tankMap.getX() || y >= tankMap.getY() ) {
        //cout << "出界";
        return true;
    }
    if (array[i][j] == -1) {
        //cout << "撞墙";
        return true;
    }
    return false;
}




