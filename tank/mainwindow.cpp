#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QKeyEvent>
#include"mytank.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(1000,800);

    mGameView.setSceneRect(QRect(0,0,1000,800));

    mScene.setSceneRect(QRect(0,0,1000,800));

    mBackGround.setPixmap(QPixmap("://F:/90_tank/start/1(1).png"));

    mScene.addItem(&mBackGround);

    mScene.addItem(&mTank);

    mGameView.setScene(&mScene);

    mGameView.setParent(this);

    mGameView.show();

}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::keyPressEvent(QKeyEvent *event){
     mTank.setTransformOriginPoint(mTank.boundingRect().center());
     switch(event->key()){
     case Qt::Key_W:
     {
         mTank.setRotation(0);
         mTank.moveBy(0,-mTank.mTankSpeed);
         break;
     }
     case Qt::Key_S:
    {
        mTank.setRotation(180);
        mTank.moveBy(0,+mTank.mTankSpeed);
        break;
    }
    case Qt::Key_A:
    {
        mTank.setRotation(270);
        mTank.moveBy(-mTank.mTankSpeed,0);
        break;
    }
    case Qt::Key_D:
    {
        mTank.setRotation(90);
        mTank.moveBy(+mTank.mTankSpeed,0);
        break;
    }
    case Qt::Key_J:{
     BulletShoot();
     }
     };
}

void MainWindow::BulletShoot()
{
   QPixmap bulletImg("://F:/90_tank/player_tank/girls_preview.png");
   QPoint pos(mTank.x(),mTank.y());
   Bullet* bullet=new Bullet(pos,bulletImg);

   mScene.addItem(bullet);
}

