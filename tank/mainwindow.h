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

    void BulletDestroy();

    void EnemyBoom();

private:
    Ui::MainWindow *ui;

    QGraphicsView mGameView;

    QGraphicsScene mScene;

    QGraphicsPixmapItem mBackGround;

    MyTank mTank;

    Enemy enemy;

    QTimer* BulletTime;

    QList<Bullet*>mBullet;

};


#endif // MAINWINDOW_H

