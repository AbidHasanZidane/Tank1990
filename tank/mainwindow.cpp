#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QKeyEvent>

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

    EnemyBoom();

    EnemyMove();

    myTankCollide();

    BulletTime =new QTimer (this);
    BulletTime->start(50);
    connect(BulletTime,&QTimer::timeout,[this](){
        for(auto bullet:mBullet){
            bullet->BulletMove();
        }
    });

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
        break;
     }
     case Qt::Key_K:{
        CreatEnemy();
        break;
     }
     case Qt::Key_L:{
        break;
     }
     };
     if(mTank.x()<0){
         mTank.setX(0);
     }
     if(mTank.y()<0){
         mTank.setY(0);
     }
     if((mTank.x()+mTank.pixmap().width())>1000){
         mTank.setX(1000-mTank.pixmap().width());
     }
     if(mTank.y()+mTank.pixmap().height()>800){
         mTank.setY(800-mTank.pixmap().height());
     }
}

void MainWindow::BulletShoot()
{
   QPixmap bulletImg("://F:/90_tank/player_tank/girls_preview.png");
   if(mTank.rotation()==0){
       QPoint pos(mTank.x()+mTank.pixmap().width()/2,mTank.y());
       Bullet* bullet=new Bullet(pos,bulletImg,'N');
       bullet->setRotation(0);
       mScene.addItem(bullet);
       mBullet.append(bullet);
   }

   if(mTank.rotation()==180){
       QPoint pos(mTank.x()+mTank.pixmap().width()/2,mTank.y()+mTank.pixmap().height());
       Bullet* bullet=new Bullet(pos,bulletImg,'S');
       bullet->setRotation(180);
       mScene.addItem(bullet);
       mBullet.append(bullet);
   }

   if(mTank.rotation()==90){
       QPoint pos(mTank.x()+mTank.pixmap().width(),mTank.y()+mTank.pixmap().height()/2);
       Bullet* bullet=new Bullet(pos,bulletImg,'E');
       bullet->setRotation(90);
       mScene.addItem(bullet);
       mBullet.append(bullet);
   }

   if(mTank.rotation()==270){
       QPoint pos(mTank.x(),mTank.y()+mTank.pixmap().height()/2);
       Bullet* bullet=new Bullet(pos,bulletImg,'W');
       bullet->setRotation(270);
       mScene.addItem(bullet);
       mBullet.append(bullet);
   }
}

void MainWindow::CreatEnemy()
{
    Enemy* enemy=new Enemy();
    mScene.addItem(enemy);
    mEnemy.append(enemy);
}

void MainWindow::EnemyBoom()
{
    Time =new QTimer (this);
    Time->start(10);
    connect(Time,&QTimer::timeout,[this](){
       for(auto enemy : mEnemy)
       for(auto bullet : mBullet)
       {
           if(bullet->collidesWithItem(enemy)){
               mEnemy.removeOne(enemy);
               enemy->setPixmap(QPixmap("://F:/90_tank/boom/insect_sprite.png"));
               QTimer::singleShot(50,this,[=](){
               enemy->setPixmap(QPixmap("://F:/90_tank/boom/insect_sprite2.png"));
               });
               QTimer::singleShot(100,this,[=](){
               enemy->setPixmap(QPixmap("://F:/90_tank/boom/insect_sprite3.png"));
               });
               QTimer::singleShot(150,this,[=](){
               enemy->setPixmap(QPixmap("://F:/90_tank/boom/insect_sprite4.png"));
               });
               QTimer::singleShot(200,this,[=](){
               enemy->setPixmap(QPixmap("://F:/90_tank/boom/insect_sprite5.png"));
               });
               QTimer::singleShot(200,this,[=](){
               enemy->deleteLater();
               });
               mBullet.removeOne(bullet);
               bullet->deleteLater();
           }
       }
    });

}

void MainWindow::EnemyMove()
{
    Time =new QTimer (this);
    Time->start(50);
    connect(Time,&QTimer::timeout,[this](){
       for(auto enemy:mEnemy){
       enemy->setTransformOriginPoint(enemy->boundingRect().center());
       int dir=rand()%4;
       if(dir==0){
       enemy->setRotation(0);
       enemy->moveBy(0,-10);
       }
       if(dir==1){
       enemy->setRotation(180);
       enemy->moveBy(0,+10);
       }
       if(dir==2){
       enemy->setRotation(90);
       enemy->moveBy(10,0);
       }
       if(dir==3){
       enemy->setRotation(270);
       enemy->moveBy(-10,0);
       }
       if(enemy->x()<0){
           enemy->setX(0);
       }
       if(enemy->y()<0){
           enemy->setY(0);
       }
       if(enemy->x()+enemy->pixmap().width()>1000){
           enemy->setX(1000-enemy->pixmap().width());
       }
       if(enemy->y()+enemy->pixmap().height()>800){
           enemy->setY(800-enemy->pixmap().height());
       }
       }
    });
}

void MainWindow::myTankCollide()
{
    Time =new QTimer (this);
    Time->start(10);
    connect(Time,&QTimer::timeout,[this](){
        for(auto enemy : mEnemy){
            if(mTank.collidesWithItem(enemy)){
                mTank.mTankSpeed=0;
                mTank.setPixmap(QPixmap("://F:/90_tank/boom/insect_sprite.png"));
                QTimer::singleShot(50,this,[=](){
                mTank.setPixmap(QPixmap("://F:/90_tank/boom/insect_sprite2.png"));
                });
                QTimer::singleShot(100,this,[=](){
                mTank.setPixmap(QPixmap("://F:/90_tank/boom/insect_sprite3.png"));
                });
                QTimer::singleShot(150,this,[=](){
                mTank.setPixmap(QPixmap("://F:/90_tank/boom/insect_sprite4.png"));
                });
                QTimer::singleShot(200,this,[=](){
                mTank.setPixmap(QPixmap("://F:/90_tank/boom/insect_sprite5.png"));
                });
                QTimer::singleShot(250,this,[=](){
                mTank.setPixmap(QPixmap("://F:/90_tank/player_tank/Icon-hdpi.png"));
                mTank.setX(200);
                mTank.setY(200);
                mTank.mTankSpeed=10;
                });
            }
        }
    });
}
