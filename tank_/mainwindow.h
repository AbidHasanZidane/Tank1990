#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QList>
#include <QTimer>
#include <QtDebug>
#include <QKeyEvent>
#include "mytank.h"
#include "bullet.h"
#include "enemy.h"
#include "building.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void keyPressEvent(QKeyEvent* event);  // 键盘按下事件处理

    void BulletShoot();  // 发射子弹

    void CreatEnemy();  // 创建敌人

    void EnemyBoom();  // 敌人爆炸效果

    void EnemyMove();  // 敌人移动

    void myTankCollide();  // 我方坦克与敌人碰撞处理

    void BuildingCreate(int x, int y, int kind);  // 创建建筑物

    void BuildingCollide();  // 建筑物与子弹碰撞处理

    void BuildingCollide2();  // 建筑物与我方坦克碰撞处理

    void BuildingCollide3();  // 建筑物与敌人碰撞处理

    void MapCreate();  // 创建地图

private:
    Ui::MainWindow *ui;

    QGraphicsView mGameView;  // 游戏视图

    QGraphicsScene mScene;  // 游戏场景

    QGraphicsPixmapItem mBackGround;  // 背景图片

    MyTank mTank;  // 我方坦克对象

    QTimer* BulletTime;  // 子弹定时器

    QTimer* Time;  // 敌人动作定时器

    QTimer* Time2;  // 建筑物碰撞处理定时器

    QList<Bullet*> mBullet;  // 子弹列表

    QList<Enemy*> mEnemy;  // 敌人列表

    QList<Building*> mBuilding;  // 建筑物列表

    int map1[18][32]={
            {3,0,3,0,	0,	1,	0,	0,	0,	1,	0,	0,	0,	1,	1,	0,	1,	1,	1,1,0,0,1,1,0,0,0,0,0,1,1,1},
            {0,0,0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	1,	1,	0,	1,	1,	1,	1,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	1},
            {3,0,0,	1,	1,	1,	1,	1,	1,	0,	1,	0,	0,	1,	1,	0,	0,	1,	1,	1,	0,	1,	0,	1,	1,	1,	1,	1,	1,	0,	0,	1},
            {0,0,0,	2,	2,	2,	2,	2,	2,	0,	0,	0,	0,	1,	1,	0,	0,	0,	1,	1,	0,	0,	0,	2,	2,	2,	2,	2,	2,	0,	0,	1},
            {0,0,0,	0,	0,	0,	0,	4,	0,	0,	0,	0,	0,	1,	1,	0,	0,	0,	1,	1,	0,	0,	0,	0,	0,	0,	0,	4,	0,	0,	0,	1},
            {0,0,0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
            {0,0,0,	0,	0,	0,	0,	4,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	4,	0,	0,	0,	0},
            {0,0,0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
            {0,0,0,	0,	0,	0,	0,	4,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	4,	0,	0,	0,	0},
            {0,0,0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
            {3,0,0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
            {0,0,0,	0,	0,	0,	0,	0,	0,	0,	2,	0,	0,	0,	0,	0,	0,	0,	0,	0,	2,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
            {0,0,0,	0,	0,	0,	0,	0,	0,	0,	0,	2,	2,	2,	2,	2,	2,	2,	2,	2,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
            {0,0,0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
            {0,0,0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
            {},
            {}
        };//地图数组

};

#endif // MAINWINDOW_H
