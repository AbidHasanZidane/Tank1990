#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QWidget>
#include<QGraphicsPixmapItem>
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QList>
#include<QTimer>
#include<QtDebug>
#include<QKeyEvent>
#include"mytank.h"
#include"bullet.h"
#include"enemy.h"
#include"building.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void keyPressEvent(QKeyEvent* event);

    void BulletShoot();

    void CreatEnemy();

    void EnemyBoom();

    void EnemyMove();

    void myTankCollide();

    void BuildingCreate(int x,int y,int kind);

    void BuildingCollide();

    void BuildingCollide2();

    void BuildingCollide3();

    void MapCreate();

private:
    Ui::MainWindow *ui;

    QGraphicsView mGameView;

    QGraphicsScene mScene;

    QGraphicsPixmapItem mBackGround;

    MyTank mTank;

    QTimer* BulletTime;

    QTimer* Time;

    QTimer* Time2;

    QList<Bullet*>mBullet;

    QList<Enemy*>mEnemy;

    QList<Building*>mBuilding;

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
        {},
        {},
        {0,0,0,	0,	0,	0,	0,	0,	0,	0,	2,	0,	0,	0,	0,	0,	0,	0,	0,	0,	2,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
        {0,0,0,	0,	0,	0,	0,	0,	0,	0,	0,	2,	2,	2,	2,	2,	2,	2,	2,	2,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
        {0,0,0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
        {0,0,0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0}
    };

};


#endif // MAINWINDOW_H

