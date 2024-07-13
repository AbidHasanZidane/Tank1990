#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->main2=new MainWindow2;
    this->main3=new GameOver;
    QFile Hfile("://90Tank/player_tank/HP.txt");
    Hfile.open(QIODevice::ReadOnly);
    QTextStream HtxtInput(&Hfile);
    QString HlineStr;
    while(!HtxtInput.atEnd())
    {
       HlineStr = HtxtInput.readLine();
       hp=HlineStr.toInt();
       mTank.HP=HlineStr.toInt();
    }
    Hfile.close();
    QFile Sfile("://90Tank/player_tank/Speed.txt");
    Sfile.open(QIODevice::ReadOnly );
    QTextStream StxtInput(&Sfile);
    QString SlineStr;
    while(!StxtInput.atEnd())
     {
        SlineStr = StxtInput.readLine();
        mTank.mTankSpeed=SlineStr.toInt();
     }
    Sfile.close();

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

    BossShoot();

    BossMove();

    BossBoom();

    BossCollide();

    myTankCollide1();

    myTankCollide2();

    myTankCollide3();

    BuildingCollide1();

    BuildingCollide2();

    BuildingCollide3();

    BuildingCollide4();

    eBulletShoot();

    bBulletShoot();

    BulletTime =new QTimer (this);
    BulletTime->start(50);
    connect(BulletTime,&QTimer::timeout,[this](){
        for(auto bullet:mBullet){
            bullet->BulletMove();
        }
    });
    game1();
    Time = new QTimer (this);
    Time->start(100);
    connect(Time,&QTimer::timeout,this,&MainWindow::gameOver);
    Time = new QTimer (this);
    Time->start(500);
    connect(Time,&QTimer::timeout,this,&MainWindow::BulletShoot2);
    connect(this->main3,&GameOver::retry,[=](){
        this->main3->close();
     QProcess::startDetached(qApp->applicationFilePath(), QStringList());
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
         BulletMove.append(Qt::Key_J);
         break;
     }
     case Qt::Key_F:{
         qDebug()<<killnum<<endl;
     }
     case Qt::Key_K:{
         game6();
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

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    switch(event->key()){
    case Qt::Key_J:
        BulletMove.removeAll(Qt::Key_J);
        break;
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

void MainWindow::BulletShoot2()
{
    for(int keyCode:BulletMove){
        if(keyCode==Qt::Key_J){
            BulletShoot();
        }
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

void MainWindow::BossShoot()
{
    QPixmap ebulletImg("://90Tank/enemy/animation_sprite_125.png");
    for(auto enemy:mBoss){
        if(enemy->rotation()==0){
            QPoint pos(enemy->x()+enemy->pixmap().width()/2+10,enemy->y());
            QPoint pos2(enemy->x()+enemy->pixmap().width()/2-20,enemy->y());
            QPoint pos3(enemy->x()+30,enemy->y());
            QPoint pos4(enemy->x()+enemy->pixmap().width()-30,enemy->y());
            BossBullet* ebullet=new BossBullet(pos,ebulletImg,'N');
            BossBullet* ebullet2=new BossBullet(pos2,ebulletImg,'N');
            BossBullet* ebullet3=new BossBullet(pos3,ebulletImg,'N');
            BossBullet* ebullet4=new BossBullet(pos4,ebulletImg,'N');
            ebullet->setRotation(0);
            ebullet2->setRotation(0);
            ebullet3->setRotation(0);
            ebullet4->setRotation(0);
            mScene.addItem(ebullet);
            mScene.addItem(ebullet2);
            mScene.addItem(ebullet3);
            mScene.addItem(ebullet4);
            bBullet.append(ebullet);
            bBullet.append(ebullet2);
            bBullet.append(ebullet3);
            bBullet.append(ebullet4);
        }

        if(enemy->rotation()==180){
            QPoint pos(enemy->x()+enemy->pixmap().width()/2+10,enemy->y()+enemy->pixmap().height());
            QPoint pos2(enemy->x()+enemy->pixmap().width()/2-20,enemy->y()+enemy->pixmap().height());
            QPoint pos3(enemy->x()+30,enemy->y()+enemy->pixmap().height());
            QPoint pos4(enemy->x()+enemy->pixmap().width()-30,enemy->y()+enemy->pixmap().height());
            BossBullet* ebullet=new BossBullet(pos,ebulletImg,'S');
            BossBullet* ebullet2=new BossBullet(pos2,ebulletImg,'S');
            BossBullet* ebullet3=new BossBullet(pos3,ebulletImg,'S');
            BossBullet* ebullet4=new BossBullet(pos4,ebulletImg,'S');
            ebullet->setRotation(180);
            ebullet2->setRotation(180);
            ebullet3->setRotation(180);
            ebullet4->setRotation(180);
            mScene.addItem(ebullet);
            mScene.addItem(ebullet2);
            mScene.addItem(ebullet3);
            mScene.addItem(ebullet4);
            bBullet.append(ebullet);
            bBullet.append(ebullet2);
            bBullet.append(ebullet3);
            bBullet.append(ebullet4);
        }

        if(enemy->rotation()==90){
            QPoint pos(enemy->x()+enemy->pixmap().width(),enemy->y()+enemy->pixmap().height()/2+10);
            QPoint pos2(enemy->x()+enemy->pixmap().width(),enemy->y()+enemy->pixmap().height()/2-20);
            QPoint pos3(enemy->x()+enemy->pixmap().width(),enemy->y()+30);
            QPoint pos4(enemy->x()+enemy->pixmap().width(),enemy->y()+enemy->pixmap().height()-30);
            BossBullet* ebullet=new BossBullet(pos,ebulletImg,'E');
            BossBullet* ebullet2=new BossBullet(pos2,ebulletImg,'E');
            BossBullet* ebullet3=new BossBullet(pos3,ebulletImg,'E');
            BossBullet* ebullet4=new BossBullet(pos4,ebulletImg,'E');
            ebullet->setRotation(90);
            ebullet2->setRotation(90);
            ebullet3->setRotation(90);
            ebullet4->setRotation(90);
            mScene.addItem(ebullet);
            mScene.addItem(ebullet2);
            mScene.addItem(ebullet3);
            mScene.addItem(ebullet4);
            bBullet.append(ebullet);
            bBullet.append(ebullet2);
            bBullet.append(ebullet3);
            bBullet.append(ebullet4);
        }

        if(enemy->rotation()==270){
            QPoint pos(enemy->x(),enemy->y()+enemy->pixmap().height()/2+10);
            QPoint pos2(enemy->x(),enemy->y()+enemy->pixmap().height()/2-20);
            QPoint pos3(enemy->x(),enemy->y()+30);
            QPoint pos4(enemy->x(),enemy->y()+enemy->pixmap().height()-30);
            BossBullet* ebullet=new BossBullet(pos,ebulletImg,'W');
            BossBullet* ebullet2=new BossBullet(pos2,ebulletImg,'W');
            BossBullet* ebullet3=new BossBullet(pos3,ebulletImg,'W');
            BossBullet* ebullet4=new BossBullet(pos4,ebulletImg,'W');
            ebullet->setRotation(270);
            ebullet2->setRotation(270);
            ebullet3->setRotation(270);
            ebullet4->setRotation(270);
            mScene.addItem(ebullet);
            mScene.addItem(ebullet2);
            mScene.addItem(ebullet3);
            mScene.addItem(ebullet4);
            bBullet.append(ebullet);
            bBullet.append(ebullet2);
            bBullet.append(ebullet3);
            bBullet.append(ebullet4);
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

void MainWindow::bBulletShoot()
{
    Time = new QTimer (this);
    Time->start(1000);
    connect(Time,&QTimer::timeout,[this](){
        BossShoot();
    });
    BossShoot();
    Time2 = new QTimer (this);
    Time2->start(50);
    connect(Time2,&QTimer::timeout,[this](){
        for(auto bullet:bBullet){
            bullet->BossBulletMove();
        }
    });
}

void MainWindow::CreatEnemy(int x,int y)
{
    Enemy* enemy=new Enemy(x,y);
    mScene.addItem(enemy);
    mEnemy.append(enemy);
}

void MainWindow::CreatBoss(int x, int y)
{
    BOSS* boss=new BOSS(x,y);
    mScene.addItem(boss);
    mBoss.append(boss);
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
               enemy->EHP--;
               if(enemy->EHP<=0){
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
               grade+=100;
               }
           }
       }
    });

}

void MainWindow::BossBoom()
{
    Time =new QTimer (this);
    Time->start(10);
    connect(Time,&QTimer::timeout,[this](){
       for(auto enemy : mBoss)
       for(auto bullet : mBullet)
       {
           if(bullet->collidesWithItem(enemy)){
               mBullet.removeOne(bullet);
               bullet->deleteLater();
               enemy->BossHp--;
               if(enemy->BossHp<=0){
               mBoss.removeOne(enemy);
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
               grade+=10000;
               }
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
       }
       }}
    });
}

void MainWindow::BossMove()
{
    Time2=new QTimer(this);
    Time2->start(1000);
    connect(Time2,&QTimer::timeout,[this](){
    dir=rand();
    });
    Time =new QTimer (this);
    Time->start(100);
    connect(Time,&QTimer::timeout,[this](){
       for(auto enemy:mBoss){
       enemy->setTransformOriginPoint(enemy->boundingRect().center());
       if(dir%2==1){
       if(mTank.x()>enemy->x()){
       enemy->setRotation(90);
       enemy->moveBy(enemy->bossSpeed,0);
       }
       if(mTank.x()<enemy->x()){
       enemy->setRotation(270);
       enemy->moveBy(-enemy->bossSpeed,0);
       }}
       if(dir%2==0){
       if(mTank.y()<enemy->y()){
       enemy->setRotation(0);
       enemy->moveBy(0,-enemy->bossSpeed);
       }
       if(mTank.y()>enemy->y()){
       enemy->setRotation(180);
       enemy->moveBy(0,enemy->bossSpeed);
       }
       }}
    });
}

void MainWindow::myTankCollide1()
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
                grade+=100;
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

void MainWindow::myTankCollide3()
{
    Time =new QTimer (this);
    Time->start(10);
    connect(Time,&QTimer::timeout,[this](){
       for(auto bullet : bBullet)
       {
           if(bullet->collidesWithItem(&mTank)){
               bBullet.removeOne(bullet);
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

void MainWindow::BossCollide()
{
    Time =new QTimer (this);
    Time->start(10);
    connect(Time,&QTimer::timeout,[this](){
        for(auto enemy : mBoss){
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
                mTank.HP--;
                });
            }
        }
    });
}

void MainWindow::BuildingCollide1()
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
    mTank.HP=hp;
    killnum=0;
    for(int i=1;i<=5;i++){
        QTimer::singleShot(5000*i,this,[=](){
        CreatEnemy(200,600);
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
            GTime1->stop();
            this->hide();
            this->main2->show();
        }
    });
    connect(this->main2,&MainWindow2::next,[=](){
        this->show();
        this->main2->close();
        game2();
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
    mTank.HP=hp;
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
            GTime2->stop();
            this->hide();
            this->main2->show();
        }
    });
    connect(this->main2,&MainWindow2::next,[=](){
        this->show();
        this->main2->close();
        game3();
    });
    connect(this->main3,&GameOver::retry,[=](){
        this->close();
        this->show();
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
    mTank.HP=hp;
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
            GTime3->stop();
        }
    });
    connect(this->main2,&MainWindow2::next,[=](){
        this->show();
        this->main2->close();
        game4();
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
    mTank.HP=hp;
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
            GTime4->stop();
        }
    });
    connect(this->main2,&MainWindow2::next,[=](){
        this->show();
        this->main2->close();
        game5();
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
    mTank.HP=hp;
    for(int i=1;i<=5;i++){
        QTimer::singleShot(5000*i,this,[=](){
        CreatEnemy(200,150);
        });
        QTimer::singleShot(10000*i,this,[=](){
        CreatEnemy(760,200);
        });
    }
    connect(this->main2,&MainWindow2::next,[=](){
        this->show();
        this->main2->close();
        game6();
    });
}

void MainWindow::game6()
{
    clear();
    mTank.setX(560);
    mTank.setY(400);
    mTank.HP=3;
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
    CreatBoss(400,100);
}

void MainWindow::gameOver()
{
    if(mTank.HP<=0){
        mTank.HP=hp;
        this->hide();
        this->main3->show();
    }
}

void MainWindow::upgrade()
{

    QFile f("grade.txt");
    //f.open(QIODevice::WriteOnly | QIODevice::Text);
     /*if(f.open(QFile::WriteOnly|QIODevice::Text))
     {
         qDebug() << ("打开文件成功");

         QTextStream txtOutput(&f);
         QString str = "123";
         txtOutput << str;
     }*/
     /*if(f.open(QIODevice::WriteOnly|QIODevice::Truncate)){
         qDebug() << ("打开文件成功");
     QTextStream txtOutput(&f);
     QString str = "123";
     txtOutput << str;
     }*/
     f.close();

}
