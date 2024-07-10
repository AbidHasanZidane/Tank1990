#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(1320,790);

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

    myTankCollide2();

    BuildingCollide();

    BuildingCollide2();

    BuildingCollide3();

    BuildingCollide4();

    BulletTime =new QTimer (this);
    BulletTime->start(50);
    connect(BulletTime,&QTimer::timeout,[this](){
        for(auto bullet:mBullet){
            bullet->BulletMove();
        }
    });

    eBulletShoot();
    Time = new QTimer (this);
    Time->start(100);
    connect(Time,&QTimer::timeout,this,GameOver);
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
        CreatEnemy(100,100);
        break;
     }
     case Qt::Key_L:{
         game1();
        break;
     }
     case Qt::Key_U:{
         game2();
         break;
     }
     case Qt::Key_I:{
         game3();
         break;
     }
     case Qt::Key_O:{
         game4();
         break;
     }
     case Qt::Key_P:{
         game5();
         break;
     }
     case Qt::Key_F:{
         qDebug()<<killnum<<endl;
     }
     case Qt::Key_Escape:{0
         QThread::sleep(2);
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

void MainWindow::EnemyShoot()
{
    QPixmap ebulletImg("://90Tank/enemy/pic_13step.png");
    for(auto enemy : mEnemy){
        if(enemy->rotation()==0){
            QPoint pos(enemy->x()+enemy->pixmap().width()/2,enemy->y());
            enemyBullet* ebullet=new enemyBullet(pos,ebulletImg,'N');
            ebullet->setRotation(0);
            mScene.addItem(ebullet);
            eBullet.append(ebullet);
        }

        if(enemy->rotation()==180){
            QPoint pos(enemy->x()+enemy->pixmap().width()/2,enemy->y()+enemy->pixmap().height());
            enemyBullet* ebullet=new enemyBullet(pos,ebulletImg,'S');
            ebullet->setRotation(180);
            mScene.addItem(ebullet);
            eBullet.append(ebullet);
        }

        if(enemy->rotation()==90){
            QPoint pos(enemy->x()+enemy->pixmap().width(),enemy->y()+enemy->pixmap().height()/2);
            enemyBullet* ebullet=new enemyBullet(pos,ebulletImg,'E');
            ebullet->setRotation(90);
            mScene.addItem(ebullet);
            eBullet.append(ebullet);
        }

        if(enemy->rotation()==270){
            QPoint pos(enemy->x(),enemy->y()+enemy->pixmap().height()/2);
            enemyBullet* ebullet=new enemyBullet(pos,ebulletImg,'W');
            ebullet->setRotation(270);
            mScene.addItem(ebullet);
            eBullet.append(ebullet);
        }
    }
}

void MainWindow::eBulletShoot()
{
    Time = new QTimer (this);
    Time->start(2000);
    connect(Time,&QTimer::timeout,[this](){
        EnemyShoot();
    });
    EnemyShoot();
    Time2 = new QTimer (this);
    Time2->start(50);
    connect(Time2,&QTimer::timeout,[this](){
        for(auto bullet:eBullet){
            bullet->eBulletMove();
        }
    });
}

void MainWindow::CreatEnemy(int x,int y)
{
    Enemy* enemy=new Enemy(x,y);
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
               killnum++;
           }
       }
    });

}

void MainWindow::EnemyMove()
{
    Time2=new QTimer(this);
    Time2->start(1000);
    connect(Time2,&QTimer::timeout,[this](){
    dir=rand();
    });
    Time =new QTimer (this);
    Time->start(100);
    connect(Time,&QTimer::timeout,[this](){
       for(auto enemy:mEnemy){
       enemy->setTransformOriginPoint(enemy->boundingRect().center());
       if(dir%2==1){
       if(mTank.x()>enemy->x()){
       enemy->setRotation(90);
       enemy->moveBy(enemy->enemySpeed,0);
       }
       if(mTank.x()<enemy->x()){
       enemy->setRotation(270);
       enemy->moveBy(-enemy->enemySpeed,0);
       }}
       if(dir%2==0){
       if(mTank.y()<enemy->y()){
       enemy->setRotation(0);
       enemy->moveBy(0,-enemy->enemySpeed);
       }
       if(mTank.y()>enemy->y()){
       enemy->setRotation(180);
       enemy->moveBy(0,enemy->enemySpeed);
       }}
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
                mTank.HP--;
                });
                killnum++;
            }
        }
    });
}

void MainWindow::myTankCollide2()
{
    Time =new QTimer (this);
    Time->start(10);
    connect(Time,&QTimer::timeout,[this](){
       for(auto bullet : eBullet)
       {
           if(bullet->collidesWithItem(&mTank)){
               eBullet.removeOne(bullet);
               bullet->deleteLater();
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
               mTank.HP--;
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
        }
    });
}

void MainWindow::BuildingCollide4()
{
    Time =new QTimer (this);
    Time->start(10);
    connect(Time,&QTimer::timeout,[this](){
        for(auto building : mBuilding)
        for(auto bullet : eBullet){
            if(building->collidesWithItem(bullet)){
            if(building->kind==1){
                eBullet.removeOne(bullet);
                bullet->deleteLater();
                mBuilding.removeOne(building);
                building->deleteLater();
            }
            if(building->kind==2){
                eBullet.removeOne(bullet);
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

void MainWindow::clear()
{
    for(auto building : mBuilding){
        mBuilding.removeOne(building);
        building->deleteLater();
    }
    for(auto enemy : mEnemy){
        mEnemy.removeOne(enemy);
        enemy->deleteLater();
    }
    for(auto bullet : mBullet){
        mBullet.removeOne(bullet);
        bullet->deleteLater();
    }
}

void MainWindow::game1()
{
    clear();
    mTank.setX(560);
    mTank.setY(400);
    for(int j=0;j<18;j++){
        BuildingCreate(j,-2,2);
    }
    for(int j=0;j<18;j++){
        BuildingCreate(j,33,2);
    }
    for(int i=0;i<32;i++){
        BuildingCreate(-1,i,2);
    }
    for(int i=0;i<32;i++){
        BuildingCreate(18,i,2);
    }
    for(int i=0;i<32;i++){
        for(int j=0;j<18;j++){
            if(map1[j][i]!=0){
                BuildingCreate(j,i,map1[j][i]);
            }
        }
    }
    killnum=0;
    for(int i=1;i<=5;i++){
        QTimer::singleShot(5000*i,this,[=](){
        CreatEnemy(100,600);
        });
        QTimer::singleShot(10000*i,this,[=](){
        CreatEnemy(1100,600);
        });
    }
    GTime1 = new QTimer (this);
    GTime1->start(100);
    connect(GTime1,&QTimer::timeout,[this](){
        if(killnum>=10){
            killnum=0;
            game2();
            GTime1->stop();
            //disconnect(Time,&QTimer::timeout,this,nullptr);
        }
    });
}

void MainWindow::game2()
{
    clear();
    mTank.setX(360);
    mTank.setY(400);
    for(int j=0;j<18;j++){
        BuildingCreate(j,-2,2);
    }
    for(int j=0;j<18;j++){
        BuildingCreate(j,33,2);
    }
    for(int i=0;i<32;i++){
        BuildingCreate(-1,i,2);
    }
    for(int i=0;i<32;i++){
        BuildingCreate(18,i,2);
    }
    for(int i=0;i<32;i++){
        for(int j=0;j<18;j++){
            if(map2[j][i]!=0){
                BuildingCreate(j,i,map2[j][i]);
            }
        }
    }
    for(int i=1;i<=5;i++){
        QTimer::singleShot(5000*i,this,[=](){
        CreatEnemy(200,150);
        });
        QTimer::singleShot(10000*i,this,[=](){
        CreatEnemy(760,200);
        });
    }
    GTime2 = new QTimer (this);
    GTime2->start(100);
    connect(GTime2,&QTimer::timeout,[this](){
        if(killnum>=10){
            killnum=0;
            game3();
            GTime2->stop();
        }
    });
}

void MainWindow::game3()
{
    clear();
    mTank.setX(560);
    mTank.setY(400);
    for(int j=0;j<18;j++){
        BuildingCreate(j,-2,2);
    }
    for(int j=0;j<18;j++){
        BuildingCreate(j,33,2);
    }
    for(int i=0;i<32;i++){
        BuildingCreate(-1,i,2);
    }
    for(int i=0;i<32;i++){
        BuildingCreate(18,i,2);
    }
    for(int i=0;i<32;i++){
        for(int j=0;j<18;j++){
            if(map3[j][i]!=0){
                BuildingCreate(j,i,map3[j][i]);
            }
        }
    }
    for(int i=1;i<=5;i++){
        QTimer::singleShot(5000*i,this,[=](){
        CreatEnemy(200,150);
        });
        QTimer::singleShot(10000*i,this,[=](){
        CreatEnemy(760,200);
        });
    }
    GTime3 = new QTimer (this);
    GTime3->start(100);
    connect(GTime3,&QTimer::timeout,[this](){
        if(killnum>=10){
            killnum=0;
            game4();
            GTime3->stop();
        }
    });
}

void MainWindow::game4()
{
    clear();
    mTank.setX(560);
    mTank.setY(400);
    for(int j=0;j<18;j++){
        BuildingCreate(j,-2,2);
    }
    for(int j=0;j<18;j++){
        BuildingCreate(j,33,2);
    }
    for(int i=0;i<32;i++){
        BuildingCreate(-1,i,2);
    }
    for(int i=0;i<32;i++){
        BuildingCreate(18,i,2);
    }
    for(int i=0;i<32;i++){
        for(int j=0;j<18;j++){
            if(map4[j][i]!=0){
                BuildingCreate(j,i,map4[j][i]);
            }
        }
    }
    for(int i=1;i<=5;i++){
        QTimer::singleShot(5000*i,this,[=](){
        CreatEnemy(200,150);
        });
        QTimer::singleShot(10000*i,this,[=](){
        CreatEnemy(760,200);
        });
    }
    GTime4 = new QTimer (this);
    GTime4->start(100);
    connect(GTime4,&QTimer::timeout,[this](){
        if(killnum>=10){
            killnum=0;
            game5();
            GTime4->stop();
        }
    });
}

void MainWindow::game5()
{
    clear();
    mTank.setX(560);
    mTank.setY(400);
    for(int j=0;j<18;j++){
        BuildingCreate(j,-2,2);
    }
    for(int j=0;j<18;j++){
        BuildingCreate(j,33,2);
    }
    for(int i=0;i<32;i++){
        BuildingCreate(-1,i,2);
    }
    for(int i=0;i<32;i++){
        BuildingCreate(18,i,2);
    }
    for(int i=0;i<32;i++){
        for(int j=0;j<18;j++){
            if(map5[j][i]!=0){
                BuildingCreate(j,i,map5[j][i]);
            }
        }
    }
}

void MainWindow::GameOver()
{
    if(mTank.HP<=0){
        qDebug()<<"GameOver"<<endl;
        mTank.HP=3;
    }
}
