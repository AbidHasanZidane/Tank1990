#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QWidget>
#include<QGraphicsPixmapItem>
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QList>
#include"mytank.h"
#include"bullet.h"

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

private:
    Ui::MainWindow *ui;

    QGraphicsView mGameView;

    QGraphicsScene mScene;

    QGraphicsPixmapItem mBackGround;

    MyTank mTank;

    QList<int>mKeyList;

};

#endif // MAINWINDOW_H

