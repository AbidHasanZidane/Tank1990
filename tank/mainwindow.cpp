#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(1280,720);

    mGameView.setSceneRect(QRect(0,0,1280,720));

    mScene.setSceneRect(QRect(0,0,1280,720));

    mBackGround.setPixmap(QPixmap("://90Tank/start/8114UVRG{SC5(IMLK}5XH3D.png"));

    mScene.addItem(&mBackGround);

    mScene.addItem(&mTank);

    mGameView.setScene(&mScene);

    mGameView.setParent(this);

    setCentralWidget(&mGameView);

    mGameView.show();

    EnemyBoom();

    EnemyMove();

    myTankCollide();

    BuildingCollide();

    BuildingCollide2();

    BuildingCollide3();

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
        MapCreate();
        break;
     }
     };
     if(mTank.x()<0){
         mTank.setX(0);
     }
     if(mTank.y()<0){
         mTank.setY(0);
     }
     if((mTank.x()+mTank.pixmap().width())>1280){
         mTank.setX(1280-mTank.pixmap().width());
     }
     if(mTank.y()+mTank.pixmap().height()>720){
         mTank.setY(720-mTank.pixmap().height());
     }
}

void MainWindow::BulletShoot()
{
   QPixmap bulletImg("://90Tank/player_tank/girls_preview.png");
   if(mTank.rotation()==0){
       QPoint pos(mTank.x()+mTank.pixmap().width()/2-1,mTank.y());
       Bullet* bullet=new Bullet(pos,bulletImg,'N');
       bullet->setRotation(0);
       mScene.addItem(bullet);
       mBullet.append(bullet);
   }

   if(mTank.rotation()==180){
       QPoint pos(mTank.x()+mTank.pixmap().width()/2+1,mTank.y()+mTank.pixmap().height());
       Bullet* bullet=new Bullet(pos,bulletImg,'S');
       bullet->setRotation(180);
       mScene.addItem(bullet);
       mBullet.append(bullet);
   }

   if(mTank.rotation()==90){
       QPoint pos(mTank.x()+mTank.pixmap().width(),mTank.y()+mTank.pixmap().height()/2-1);
       Bullet* bullet=new Bullet(pos,bulletImg,'E');
       bullet->setRotation(90);
       mScene.addItem(bullet);
       mBullet.append(bullet);
   }

   if(mTank.rotation()==270){
       QPoint pos(mTank.x(),mTank.y()+mTank.pixmap().height()/2+3);
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
               mBullet.removeOne(bullet);
               bullet->deleteLater();
               mEnemy.removeOne(enemy);
               enemy->setPixmap(QPixmap("://90Tank/boom/insect_sprite.png"));
               QTimer::singleShot(50,this,[=](){
               enemy->setPixmap(QPixmap("://90Tank/boom/insect_sprite2.png"));
               });
               QTimer::singleShot(100,this,[=](){
               enemy->setPixmap(QPixmap("://90Tank/boom/insect_sprite3.png"));
               });
               QTimer::singleShot(150,this,[=](){
               enemy->setPixmap(QPixmap("://90Tank/boom/insect_sprite4.png"));
               });
               QTimer::singleShot(200,this,[=](){
               enemy->setPixmap(QPixmap("://90Tank/boom/insect_sprite5.png"));
               });
               QTimer::singleShot(200,this,[=](){
               enemy->deleteLater();
               });
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
       if(enemy->x()+enemy->pixmap().width()>1280){
           enemy->setX(1280-enemy->pixmap().width());
       }
       if(enemy->y()+enemy->pixmap().height()>720){
           enemy->setY(720-enemy->pixmap().height());
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
                mTank.setPixmap(QPixmap("://90Tank/boom/insect_sprite.png"));
                QTimer::singleShot(50,this,[=](){
                mTank.setPixmap(QPixmap("://90Tank/boom/insect_sprite2.png"));
                });
                QTimer::singleShot(100,this,[=](){
                mTank.setPixmap(QPixmap("://90Tank/boom/insect_sprite3.png"));
                });
                QTimer::singleShot(150,this,[=](){
                mTank.setPixmap(QPixmap("://90Tank/boom/insect_sprite4.png"));
                });
                QTimer::singleShot(200,this,[=](){
                mTank.setPixmap(QPixmap("://90Tank/boom/insect_sprite5.png"));
                });
                QTimer::singleShot(250,this,[=](){
                mTank.setPixmap(QPixmap("://90Tank/player_tank/mTank.png"));
                mTank.setX(200);
                mTank.setY(200);
                mTank.mTankSpeed=10;
                });
            }
        }
    });
}

void MainWindow::BuildingCreate(int y,int x,int kind)
{
    Building* building=new Building(y,x,kind);
    mScene.addItem(building);
    mBuilding.append(building);
}

void MainWindow::BuildingCollide()
{
    Time =new QTimer (this);
    Time->start(10);
    connect(Time,&QTimer::timeout,[this](){
        for(auto building : mBuilding)
        for(auto bullet : mBullet){
            if(building->collidesWithItem(bullet)){
            if(building->kind==1){
                mBullet.removeOne(bullet);
                bullet->deleteLater();
                mBuilding.removeOne(building);
                building->deleteLater();
            }
            if(building->kind==2){
                mBullet.removeOne(bullet);
                bullet->deleteLater();
            }
            if(building->kind==3){
                mScene.removeItem(building);
                mScene.addItem(building);
            }

            }
        }
    });
}

void MainWindow::BuildingCollide2()
{
    Time =new QTimer (this);
    Time->start(1);
    connect(Time,&QTimer::timeout,[this](){
        for(auto building : mBuilding){
            if(mTank.collidesWithItem(building)){
                if(building->kind!=3){
                   if(mTank.rotation()==0){
                      mTank.setY(building->y()+building->pixmap().height());
                      mTank.setX(mTank.x());
                   }
                   if(mTank.rotation()==180){
                      mTank.setY(building->y()-mTank.pixmap().height());
                      mTank.setX(mTank.x());
                   }
                   if(mTank.rotation()==90){
                      mTank.setY(mTank.y());
                      mTank.setX(building->x()-mTank.pixmap().width());
                   }
                   if(mTank.rotation()==270){
                      mTank.setY(mTank.y());
                      mTank.setX(building->x()+building->pixmap().width());
                   }
                }
            }
        }
    });
}

void MainWindow::BuildingCollide3()
{
    Time =new QTimer (this);
    Time->start(1);
    connect(Time,&QTimer::timeout,[this](){
        for(auto building : mBuilding)
        for(auto enemy : mEnemy){
            if(enemy->collidesWithItem(building)){
                if(building->kind!=3){
                   if(enemy->rotation()==0){
                      enemy->setY(building->y()+building->pixmap().height());
                      enemy->setX(enemy->x());
                   }
                   if(enemy->rotation()==180){
                      enemy->setY(building->y()-enemy->pixmap().height());
                      enemy->setX(enemy->x());
                   }
                   if(enemy->rotation()==90){
                      enemy->setY(enemy->y());
                      enemy->setX(building->x()-enemy->pixmap().width());
                   }
                   if(enemy->rotation()==270){
                      enemy->setY(enemy->y());
                      enemy->setX(building->x()+building->pixmap().width());
                   }
                }
                if(building->kind==3){
                    mScene.removeItem(building);
                    mScene.addItem(building);
                }
            }
        }
    });
}

void MainWindow::MapCreate()
{
    for(int i=0;i<32;i++){
        for(int j=0;j<18;j++){
            if(map1[j][i]!=0){
                BuildingCreate(j,i,map1[j][i]);
            }
        }
    }
}
