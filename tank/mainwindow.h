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

    void BuildingCreate();

    void BuildingCollide();

    void BuildingCollide2();

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

};


#endif // MAINWINDOW_H

