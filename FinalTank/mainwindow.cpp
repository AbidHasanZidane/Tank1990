#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QKeyEvent>
#include<QsoundEffect>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->main2=new MainWindow2;
    connect(main2,&MainWindow2::switch2main,this,&MainWindow::fromw2main);
    this->main3=new GameOver;
    connect(main3,&GameOver::switch2main,this,&MainWindow::fromw2main);
    this->main4=new MainWindow3;
    mTank.HP=settings::readSettings("Hp:").toInt();

    hp=settings::readSettings("Hp:").toInt();

    mTank.mTankSpeed=settings::readSettings("Speed:").toInt();

    mtankspeed=settings::readSettings("Speed:").toInt();

    Fire=settings::readSettings("Fire:").toInt();

    grade=settings::readSettings("Grade:").toInt();

    Death=settings::readSettings("Death:").toInt();

    KillNum=settings::readSettings("KillNum:").toInt();

    accomplishment=settings::readSettings("Accomplishment:").toInt();

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
    BulletTime = new QTimer(this);
    BulletTime->start(50);
    connect(BulletTime, &QTimer::timeout, [this](){
        for(auto bullet : mBullet){
            bullet->BulletMove();
        }
    });
    game1();
    Time = new QTimer (this);
    Time->start(100);
    connect(Time,&QTimer::timeout,this,&MainWindow::gameOver);
    Time = new QTimer (this);
    Time->start(Fire);
    connect(Time,&QTimer::timeout,this,&MainWindow::BulletShoot2);
    connect(this->main3,&GameOver::retry,[=](){
    this->main3->close();
    Time->stop();
    QProcess::startDetached(qApp->applicationFilePath(), QStringList());
    });
    Time = new QTimer (this);
    Time->start(100);
    connect(Time,&QTimer::timeout,[this](){
        QString g=QString::number (grade);
       settings::modifySettings("Grade:",g);
       QString k=QString::number (KillNum);
       settings::modifySettings("KillNum:",k);
       QString d=QString::number(Death);
       settings::modifySettings("Death:",d);
       settings::modifySettings("Accomplishment:",QString::number(accomplishment));
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
     case Qt::Key_K:{
         settings::modifySettings("a:","123");
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
    Enemy* enemy=new Enemy(x,y,Ehp);
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
               enemy->deleteLater();
               });
               killnum++;
               KillNum++;
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
               KillNum+=50;
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
    Death++;
    Time =new QTimer (this);
    Time->start(10);
    connect(Time,&QTimer::timeout,[this](){
        for(auto enemy : mEnemy){
            if(mTank.collidesWithItem(enemy)){
                mEnemy.removeOne(enemy);
                emit boomEffect();
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
                    mTank.mTankSpeed=mtankspeed;
                    for(auto bullet : mBullet){
                        mBullet.removeOne(bullet);
                        bullet->deleteLater();
                    }
                    mTank.HP--;
                    for(auto Heart : mHeart){
                        mHeart.removeOne(Heart);
                        Heart->deleteLater();
                    }
                    showHeart(mTank.HP);
                });
                killnum++;
                grade+=100;
            }
        }
    });
}

void MainWindow::myTankCollide2()
{
    Death++;
    Time =new QTimer (this);
    Time->start(10);
    connect(Time,&QTimer::timeout,[this](){
        for(auto bullet : eBullet)
        {
            if(bullet->collidesWithItem(&mTank)){
                eBullet.removeOne(bullet);
                bullet->deleteLater();
                mTank.mTankSpeed=0;
                emit boomEffect();
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
                    mTank.mTankSpeed=mtankspeed;
                    for(auto bullet : mBullet){
                        mBullet.removeOne(bullet);
                        bullet->deleteLater();
                    }
                    mTank.HP--;
                    for(auto Heart : mHeart){
                        mHeart.removeOne(Heart);
                        Heart->deleteLater();
                    }
                    showHeart(mTank.HP);
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
                emit boomEffect();
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
                    mTank.mTankSpeed=mtankspeed;
                    for(auto bullet : mBullet){
                        mBullet.removeOne(bullet);
                        bullet->deleteLater();
                    }
                    mTank.HP--;
                    for(auto Heart : mHeart){
                        mHeart.removeOne(Heart);
                        Heart->deleteLater();
                    }
                    showHeart(mTank.HP);
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
    Time = new QTimer(this); // 创建一个新的 QTimer 对象，并设置父对象为当前窗口
    Time->start(10); // 启动定时器，间隔为10毫秒
    connect(Time, &QTimer::timeout, [this]() {
        for (auto enemy : mBoss) { // 遍历所有的 Boss 对象
            if (mTank.collidesWithItem(enemy)) { // 如果玩家坦克与当前 Boss 对象发生碰撞
                mTank.mTankSpeed = 0; // 玩家坦克速度设为0，即停止移动
                emit boomEffect(); // 发射爆炸效果的信号，可能用于播放音效或动画效果

                // 设置玩家坦克的爆炸动画
                mTank.setPixmap(QPixmap("://90Tank/boom/insect_sprite.png"));
                QTimer::singleShot(50, this, [=]() {
                    mTank.setPixmap(QPixmap("://90Tank/boom/insect_sprite2.png"));
                });
                QTimer::singleShot(100, this, [=]() {
                    mTank.setPixmap(QPixmap("://90Tank/boom/insect_sprite3.png"));
                });
                QTimer::singleShot(150, this, [=]() {
                    mTank.setPixmap(QPixmap("://90Tank/boom/insect_sprite4.png"));
                });
                QTimer::singleShot(200, this, [=]() {
                    mTank.setPixmap(QPixmap("://90Tank/boom/insect_sprite5.png"));
                });

                // 250毫秒后恢复玩家坦克正常状态并执行伤害处理
                QTimer::singleShot(250, this, [=]() {
                    mTank.setPixmap(QPixmap("://90Tank/player_tank/mTank.png")); // 恢复正常状态的坦克图片
                    mTank.setX(200); // 重置坦克的 X 坐标
                    mTank.setY(200); // 重置坦克的 Y 坐标
                    mTank.mTankSpeed = mtankspeed; // 恢复坦克的移动速度
                    mTank.HP--; // 玩家坦克生命值减一

                    // 删除一个心形生命图标并更新显示
                    for (auto Heart : mHeart) {
                        mHeart.removeOne(Heart); // 从列表中移除当前心形对象
                        Heart->deleteLater(); // 延迟删除心形对象，以避免在迭代过程中修改列表
                    }
                    showHeart(mTank.HP); // 更新显示玩家坦克的生命值（心形图标）
                });
            }
        }
    });
}
void MainWindow::BuildingCollide1()
{
    Time = new QTimer(this); // 创建一个新的 QTimer 对象，并设置父对象为当前窗口
    Time->start(10); // 启动定时器，间隔为10毫秒
    connect(Time, &QTimer::timeout, [this]() {
        for (auto building : mBuilding) { // 遍历所有的建筑物对象
            for (auto bullet : mBullet) { // 遍历所有的子弹对象
                if (building->collidesWithItem(bullet)) { // 如果建筑物与子弹发生碰撞
                    if (building->kind == 1) { // 如果建筑物类型为1
                        mBullet.removeOne(bullet); // 从子弹列表中移除该子弹
                        bullet->deleteLater(); // 删除子弹对象，延迟到下一个事件循环周期
                        mBuilding.removeOne(building); // 从建筑物列表中移除该建筑物
                        building->deleteLater(); // 删除建筑物对象，延迟到下一个事件循环周期
                    } else if (building->kind == 2) { // 如果建筑物类型为2
                        mBullet.removeOne(bullet); // 从子弹列表中移除该子弹
                        bullet->deleteLater(); // 删除子弹对象，延迟到下一个事件循环周期
                    } else if (building->kind == 3) { // 如果建筑物类型为3
                        mScene.removeItem(building); // 从场景中移除建筑物对象
                        mScene.addItem(building); // 将建筑物对象重新添加到场景中，用于更新显示顺序
                    }
                }
            }
        }
    });
}

void MainWindow::BuildingCollide2()
{
    Time = new QTimer(this); // 创建一个新的 QTimer 对象，并设置父对象为当前窗口
    Time->start(1); // 启动定时器，间隔为1毫秒
    connect(Time, &QTimer::timeout, [this]() {
        // 定时器超时时执行的lambda表达式
        for (auto building : mBuilding) { // 遍历所有的建筑物对象
            if (mTank.collidesWithItem(building)) { // 如果坦克与建筑物发生碰撞
                if (building->kind != 3) { // 如果建筑物类型不为3
                    // 根据坦克的旋转角度进行位置调整
                    if (mTank.rotation() == 0) {
                        mTank.setY(building->y() + building->pixmap().height());
                        mTank.setX(mTank.x());
                    }
                    else if (mTank.rotation() == 180) {
                        mTank.setY(building->y() - mTank.pixmap().height());
                        mTank.setX(mTank.x());
                    }
                    else if (mTank.rotation() == 90) {
                        mTank.setY(mTank.y());
                        mTank.setX(building->x() - mTank.pixmap().width());
                    }
                    else if (mTank.rotation() == 270) {
                        mTank.setY(mTank.y());
                        mTank.setX(building->x() + building->pixmap().width());
                    }
                }
            }
        }
    });
}

void MainWindow::BuildingCollide3()
{
    Time = new QTimer(this); // 创建一个新的 QTimer 对象，并设置父对象为当前窗口
    Time->start(1); // 启动定时器，间隔为1毫秒
    connect(Time, &QTimer::timeout, [this]() {
        // 定时器超时时执行的lambda表达式
        for (auto building : mBuilding) { // 遍历所有的建筑物对象
            for (auto enemy : mEnemy) { // 遍历所有的敌方单位对象
                if (enemy->collidesWithItem(building)) { // 如果敌方单位与建筑物发生碰撞
                    if (building->kind != 3) { // 如果建筑物类型不为3
                        // 根据敌方单位的旋转角度进行位置调整
                        if (enemy->rotation() == 0) {
                            enemy->setY(building->y() + building->pixmap().height());
                            enemy->setX(enemy->x());
                        }
                        else if (enemy->rotation() == 180) {
                            enemy->setY(building->y() - enemy->pixmap().height());
                            enemy->setX(enemy->x());
                        }
                        else if (enemy->rotation() == 90) {
                            enemy->setY(enemy->y());
                            enemy->setX(building->x() - enemy->pixmap().width());
                        }
                        else if (enemy->rotation() == 270) {
                            enemy->setY(enemy->y());
                            enemy->setX(building->x() + building->pixmap().width());
                        }
                    }
                    if (building->kind == 3) { // 如果建筑物类型为3
                        mScene.removeItem(building); // 从场景中移除建筑物对象
                        mScene.addItem(building); // 将建筑物对象重新添加到场景中，用于更新显示顺序
                    }
                    // 对敌方单位进行边界检查，确保不超出窗口边界
                    if (enemy->x() < 0) {
                        enemy->setX(0);
                    }
                    if (enemy->y() < 0) {
                        enemy->setY(0);
                    }
                    if (enemy->x() + enemy->pixmap().width() > 1280) {
                        enemy->setX(1280 - enemy->pixmap().width());
                    }
                    if (enemy->y() + enemy->pixmap().height() > 720) {
                        enemy->setY(720 - enemy->pixmap().height());
                    }
                }
            }
        }
    });
}

void MainWindow::BuildingCollide4()
{
    Time = new QTimer(this); // 创建一个新的 QTimer 对象，并设置父对象为当前窗口
    Time->start(10); // 启动定时器，间隔为10毫秒
    connect(Time, &QTimer::timeout, [this]() {
        // 定时器超时时执行的lambda表达式
        for (auto building : mBuilding) { // 遍历所有的建筑物对象
            for (auto bullet : eBullet) { // 遍历所有的敌方子弹对象
                if (building->collidesWithItem(bullet)) { // 如果建筑物与子弹相撞
                    if (building->kind == 1) { // 如果建筑物类型为1
                        eBullet.removeOne(bullet); // 从敌方子弹容器中移除当前子弹对象
                        bullet->deleteLater(); // 延迟释放子弹对象的内存
                        mBuilding.removeOne(building); // 从建筑物容器中移除当前建筑物对象
                        building->deleteLater(); // 延迟释放建筑物对象的内存
                    }
                    if (building->kind == 2) { // 如果建筑物类型为2
                        eBullet.removeOne(bullet); // 从敌方子弹容器中移除当前子弹对象
                        bullet->deleteLater(); // 延迟释放子弹对象的内存
                    }
                    if (building->kind == 3) { // 如果建筑物类型为3
                        mScene.removeItem(building); // 从场景中移除建筑物对象
                        mScene.addItem(building); // 将建筑物对象重新添加到场景中，用于更新显示顺序
                    }
                }
            }
        }
    });
}
void MainWindow::showHeart(int number)
{
    for(int i = 0; i < number; i++) {
        Heart *h = new Heart(0, i); // 创建一个新的 Heart 对象，位置为 (0, i)
        mScene.addItem(h); // 将 Heart 对象添加到场景 mScene 中显示
        mHeart.append(h); // 将 Heart 对象添加到 mHeart 容器中保存
    }
}

void MainWindow::clear()
{
    // 清空 mBuilding 容器中的建筑物对象
    for(auto building : mBuilding){
        mBuilding.removeOne(building); // 从容器中移除当前建筑物对象
        building->deleteLater(); // 延迟释放建筑物对象的内存
    }

    // 清空 mEnemy 容器中的敌人对象
    for(auto enemy : mEnemy){
        mEnemy.removeOne(enemy); // 从容器中移除当前敌人对象
        enemy->deleteLater(); // 延迟释放敌人对象的内存
    }

    // 清空 mBullet 容器中的子弹对象
    for(auto bullet : mBullet){
        mBullet.removeOne(bullet); // 从容器中移除当前子弹对象
        bullet->deleteLater(); // 延迟释放子弹对象的内存
    }
}

void MainWindow::game1()
{
    QTimer::singleShot(100, this, [this] { emit changeMusic(1); }); // 在延迟100毫秒后发射 changeMusic(1) 信号，可能用于播放音乐切换
    clear(); // 清空游戏场景或状态，进行初始化

    mTank.setX(560); // 设置坦克的初始 X 坐标
    mTank.setY(400); // 设置坦克的初始 Y 坐标

    // 在四周创建建筑物，保护区域边界
    for(int j = 0; j < 18; j++) {
        BuildingCreate(j, -2, 2); // 顶部
    }
    for(int j = 0; j < 18; j++) {
        BuildingCreate(j, 33, 2); // 底部
    }
    for(int i = 0; i < 32; i++) {
        BuildingCreate(-1, i, 2); // 左侧
    }
    for(int i = 0; i < 32; i++) {
        BuildingCreate(18, i, 2); // 右侧
    }

    // 根据地图数据创建更多的建筑物
    for(int i = 0; i < 32; i++) {
        for(int j = 0; j < 18; j++) {
            if(map1[j][i] != 0) {
                BuildingCreate(j, i, map1[j][i]); // 在指定位置创建地图数据中定义的建筑物
            }
        }
    }

    mTank.HP = hp; // 设置坦克的生命值为初始值 hp
    showHeart(mTank.HP); // 显示坦克当前的生命值

    killnum = 0; // 初始化击杀数量为0

    // 使用定时器在不同的时间间隔后创建敌人
    for(int i = 1; i <= 5; i++) {
        QTimer::singleShot(5000 * i, this, [=]() {
            CreatEnemy(200, 600); // 在指定位置创建敌人
        });
        QTimer::singleShot(10000 * i, this, [=]() {
            CreatEnemy(1100, 600); // 在指定位置创建敌人
        });
    }

    // 创建定时器 GTime1，每隔100毫秒触发一次
    GTime1 = new QTimer(this);
    GTime1->start(100);

    // 连接定时器的 timeout 信号到 lambda 表达式
    connect(GTime1, &QTimer::timeout, [this]() {
        if(killnum >= 10) { // 如果击杀数量达到10个或以上
            killnum = 0; // 重置击杀数量
            if(mTank.HP == hp) {
                Ehp++; // 如果坦克生命值仍为初始值 hp，则增加敌人的生命值
            }
            accomplishment++; // 完成任务计数加一
            GTime1->stop(); // 停止定时器 GTime1
            this->hide(); // 隐藏当前的 MainWindow 主窗口
            this->main2->show(); // 显示另一个窗口 main2（假设 main2 是 MainWindow 类的另一个成员变量）
        }
    });

    // 连接 main2 窗口的 next 信号到 lambda 表达式
    connect(this->main2, &MainWindow2::next, [=]() {
        this->main2->close(); // 关闭 main2 窗口
        emit switch2w1(); // 发送 switch2w1 信号，可能用于切换到另一个界面或状态
    });
}

void MainWindow::game2()
{
    clear(); // 清空游戏场景或状态，进行初始化

    mTank.setX(360); // 设置坦克的初始 X 坐标
    mTank.setY(400); // 设置坦克的初始 Y 坐标

    // 在四周创建建筑物，保护区域边界
    for(int j = 0; j < 18; j++) {
        BuildingCreate(j, -2, 2); // 顶部
    }
    for(int j = 0; j < 18; j++) {
        BuildingCreate(j, 33, 2); // 底部
    }
    for(int i = 0; i < 32; i++) {
        BuildingCreate(-1, i, 2); // 左侧
    }
    for(int i = 0; i < 32; i++) {
        BuildingCreate(18, i, 2); // 右侧
    }

    // 根据地图数据创建更多的建筑物
    for(int i = 0; i < 32; i++) {
        for(int j = 0; j < 18; j++) {
            if(map2[j][i] != 0) {
                BuildingCreate(j, i, map2[j][i]); // 在指定位置创建地图数据中定义的建筑物
            }
        }
    }

    mTank.HP = hp; // 设置坦克的生命值为初始值 hp
    showHeart(mTank.HP); // 显示坦克当前的生命值

    // 使用定时器创建敌人
    for(int i = 1; i <= 5; i++) {
        QTimer::singleShot(5000 * i, this, [=]() {
            CreatEnemy(200, 150); // 在指定位置创建敌人
        });
        QTimer::singleShot(10000 * i, this, [=]() {
            CreatEnemy(760, 200); // 在指定位置创建敌人
        });
    }

    // 创建定时器 GTime2，每隔100毫秒触发一次
    GTime2 = new QTimer(this);
    GTime2->start(100);

    // 连接定时器的 timeout 信号到 lambda 表达式
    connect(GTime2, &QTimer::timeout, [this]() {
        if(killnum >= 10) { // 如果击杀数量达到10个或以上
            killnum = 0; // 重置击杀数量
            if(mTank.HP == hp) {
                Ehp++; // 如果坦克生命值仍为初始值 hp，则增加敌人的生命值
            }
            accomplishment++; // 完成任务计数加一
            GTime2->stop(); // 停止定时器 GTime2
            this->hide(); // 隐藏当前的 MainWindow 主窗口
            this->main2->show(); // 显示另一个窗口 main2（假设 main2 是 MainWindow 类的另一个成员变量）
        }
    });

    // 连接 main2 窗口的 next 信号到 lambda 表达式
    connect(this->main2, &MainWindow2::next, [=]() {
        this->main2->close(); // 关闭 main2 窗口
        emit switch2w1(); // 发送 switch2w1 信号，可能用于切换到另一个界面或状态
    });
}
void MainWindow::game3()
{
    // 设置定时器，在100毫秒后发射一个单次的信号，切换音乐（假设 emit changeMusic(2); 是切换音乐的信号发射函数）
    QTimer::singleShot(100, this, [this] { emit changeMusic(2); });

    clear(); // 清空游戏场景或状态，进行初始化

    // 设置坦克的初始位置
    mTank.setX(560);
    mTank.setY(400);

    // 在四周创建建筑物，保护区域边界
    for (int j = 0; j < 18; j++) {
        BuildingCreate(j, -2, 2); // 顶部
    }
    for (int j = 0; j < 18; j++) {
        BuildingCreate(j, 33, 2); // 底部
    }
    for (int i = 0; i < 32; i++) {
        BuildingCreate(-1, i, 2); // 左侧
    }
    for (int i = 0; i < 32; i++) {
        BuildingCreate(18, i, 2); // 右侧
    }

    // 根据地图数据创建更多的建筑物
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 18; j++) {
            if (map3[j][i] != 0) {
                BuildingCreate(j, i, map3[j][i]); // 在指定位置创建地图数据中定义的建筑物
            }
        }
    }

    mTank.HP = hp; // 设置坦克的生命值为初始值 hp
    showHeart(mTank.HP); // 显示坦克当前的生命值

    // 使用定时器创建敌人
    for (int i = 1; i <= 5; i++) {
        QTimer::singleShot(5000 * i, this, [=]() {
            CreatEnemy(200, 150); // 在指定位置创建敌人
        });
        QTimer::singleShot(10000 * i, this, [=]() {
            CreatEnemy(760, 200); // 在指定位置创建敌人
        });
    }

    // 创建定时器 GTime3，每隔100毫秒触发一次
    GTime3 = new QTimer(this);
    GTime3->start(100);

    // 连接定时器的 timeout 信号到 lambda 表达式
    connect(GTime3, &QTimer::timeout, [this]() {
        if (killnum >= 10) { // 如果击杀数量达到10个或以上
            killnum = 0; // 重置击杀数量
            if (mTank.HP == hp) {
                Ehp++; // 如果坦克生命值仍为初始值 hp，则增加敌人的生命值
            }
            accomplishment++; // 完成任务计数加一
            GTime3->stop(); // 停止定时器 GTime3
            this->hide(); // 隐藏当前的 MainWindow 主窗口
            this->main2->show(); // 显示另一个窗口 main2（假设 main2 是 MainWindow 类的另一个成员变量）
        }
    });

    // 连接 main2 窗口的 next 信号到 lambda 表达式
    connect(this->main2, &MainWindow2::next, [=]() {
        this->main2->close(); // 关闭 main2 窗口
        emit switch2w1(); // 发送 switch2w1 信号，可能用于切换到另一个界面或状态
    });
}
void MainWindow::game4()
{
    clear(); // 清空游戏场景或状态，进行初始化

    // 设置坦克的初始位置
    mTank.setX(560);
    mTank.setY(400);

    // 在边界位置创建建筑物
    for(int j = 0; j < 18; j++) {
        BuildingCreate(j, -2, 2); // 在上边界创建建筑物
    }
    for(int j = 0; j < 18; j++) {
        BuildingCreate(j, 33, 2); // 在下边界创建建筑物
    }
    for(int i = 0; i < 32; i++) {
        BuildingCreate(-1, i, 2); // 在左边界创建建筑物
    }
    for(int i = 0; i < 32; i++) {
        BuildingCreate(18, i, 2); // 在右边界创建建筑物
    }

    // 根据地图数组 `map4` 创建建筑物
    for(int i = 0; i < 32; i++) {
        for(int j = 0; j < 18; j++) {
            if(map4[j][i] != 0) {
                BuildingCreate(j, i, map4[j][i]); // 在指定位置创建特定类型的建筑物
            }
        }
    }

    mTank.HP = hp; // 设置坦克的生命值为初始值 hp
    showHeart(mTank.HP); // 显示坦克当前的生命值

    // 使用定时器创建敌人
    for(int i = 1; i <= 5; i++) {
        QTimer::singleShot(5000 * i, this, [=]() {
            CreatEnemy(200, 150); // 在指定位置创建敌人
        });
        QTimer::singleShot(10000 * i, this, [=]() {
            CreatEnemy(760, 200); // 在指定位置创建敌人
        });
    }

    GTime4 = new QTimer(this); // 创建定时器 GTime4
    GTime4->start(100); // 启动定时器，每隔100毫秒触发一次

    // 连接定时器的 timeout 信号到 lambda 表达式
    connect(GTime4, &QTimer::timeout, [this]() {
        if(killnum >= 10) { // 如果击杀数量达到10个
            killnum = 0; // 重置击杀数量

            if(mTank.HP == hp) {
                Ehp++; // 如果坦克的生命值未减少，增加敌人的生命值计数 Ehp
            }

            accomplishment++; // 完成任务计数加一
            GTime4->stop(); // 停止定时器 GTime4
            this->hide(); // 隐藏当前的 MainWindow 主窗口
            this->main2->show(); // 显示另一个窗口 main2

        }
    });

    // 连接 main2 窗口的 next 信号到 lambda 表达式
    connect(this->main2, &MainWindow2::next, [=]() {
        this->main2->close(); // 关闭 main2 窗口
        emit switch2w1(); // 发送 switch2w1 信号，可能用于切换到另一个界面或状态
    });
}

void MainWindow::game5()
{
    // 设置定时器，在100毫秒后发射一个单次的信号，切换音乐（假设 emit changeMusic(3); 是切换音乐的信号发射函数）
    QTimer::singleShot(100, this, [this] { emit changeMusic(3); });

    clear(); // 清空游戏场景或状态，进行初始化

    // 设置坦克的初始位置
    mTank.setX(560);
    mTank.setY(400);

    // 在四周创建建筑物
    for (int j = 0; j < 18; j++) {
        BuildingCreate(j, -2, 2); // 在顶部创建建筑物
    }
    for (int j = 0; j < 18; j++) {
        BuildingCreate(j, 33, 2); // 在底部创建建筑物
    }
    for (int i = 0; i < 32; i++) {
        BuildingCreate(-1, i, 2); // 在左侧创建建筑物
    }
    for (int i = 0; i < 32; i++) {
        BuildingCreate(18, i, 2); // 在右侧创建建筑物
    }

    // 根据地图数据创建更多的建筑物
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 18; j++) {
            if (map5[j][i] != 0) {
                BuildingCreate(j, i, map5[j][i]); // 在指定位置创建地图数据中定义的建筑物
            }
        }
    }

    mTank.HP = hp; // 设置坦克的生命值为初始值 hp
    showHeart(mTank.HP); // 显示坦克当前的生命值

    // 使用定时器创建敌人
    for (int i = 1; i <= 5; i++) {
        QTimer::singleShot(5000 * i, this, [=]() {
            CreatEnemy(200, 150); // 在指定位置创建敌人
        });
        QTimer::singleShot(10000 * i, this, [=]() {
            CreatEnemy(760, 200); // 在指定位置创建敌人
        });
    }

    // 创建定时器 GTime5，每隔100毫秒触发一次
    GTime5 = new QTimer(this);
    GTime5->start(100);

    // 连接定时器的 timeout 信号到 lambda 表达式
    connect(GTime5, &QTimer::timeout, [this]() {
        if (killnum >= 10) { // 如果击杀数量达到10个或以上
            killnum = 0; // 重置击杀数量
            Ehp = 2; // 重置敌人的生命值（假设 Ehp 是敌人的初始生命值）
            accomplishment++; // 完成任务计数加一
            GTime5->stop(); // 停止定时器 GTime5
            this->hide(); // 隐藏当前的 MainWindow 主窗口
            this->main2->show(); // 显示另一个窗口 main2（假设 main2 是 MainWindow 类的另一个成员变量）
        }
    });

    // 连接 main2 窗口的 next 信号到 lambda 表达式
    connect(this->main2, &MainWindow2::next, [=]() {
        this->main2->close(); // 关闭 main2 窗口
        emit switch2w1(); // 发送 switch2w1 信号，可能用于切换到另一个界面或状态
    });
}

void MainWindow::game6()
{
    clear(); // 清空游戏场景或状态，进行初始化

    // 设置坦克的初始位置和生命值
    mTank.setX(560);
    mTank.setY(400);
    mTank.HP = hp; // 将坦克的生命值设置为初始值 hp
    showHeart(mTank.HP); // 显示坦克当前的生命值（假设 showHeart() 是显示生命值的函数）

    // 创建游戏地图上的建筑物
    for(int j = 0; j < 18; j++) {
        BuildingCreate(j, -2, 2); // 在指定位置创建建筑物（假设 BuildingCreate() 是创建建筑物的函数）
    }
    for(int j = 0; j < 18; j++) {
        BuildingCreate(j, 33, 2); // 在指定位置创建建筑物
    }
    for(int i = 0; i < 32; i++) {
        BuildingCreate(-1, i, 2); // 在指定位置创建建筑物
    }
    for(int i = 0; i < 32; i++) {
        BuildingCreate(18, i, 2); // 在指定位置创建建筑物
    }

    CreatBoss(400, 100); // 创建 Boss 敌人，设置其初始位置

    // 创建定时器 GTime6，每隔100毫秒触发一次
    GTime6 = new QTimer(this);
    GTime6->start(100);

    // 连接定时器的 timeout 信号到 lambda 表达式
    connect(GTime6, &QTimer::timeout, [this]() {
        // 如果击杀数量大于等于1
        if(killnum >= 1) {
            killnum = 0; // 重置击杀数量
            accomplishment++; // 完成任务计数加一
            GTime6->stop(); // 停止定时器 GTime6

            this->main2->show(); // 显示另一个窗口 main2（假设 main2 是 MainWindow 类的另一个成员变量）
            this->hide(); // 隐藏当前的 MainWindow 主窗口
        }
    });

    // 连接 main2 窗口的 next 信号到 lambda 表达式
    connect(this->main2, &MainWindow2::next, [=]() {
        this->main2->close(); // 关闭 main2 窗口
        emit switch2w1(); // 发送 switch2w1 信号，可能用于切换到另一个界面或状态
    });
}
void MainWindow::gameOver()
{
    if(mTank.HP <= 0){
        mTank.HP = hp; // 将坦克的生命值重置为初始值 hp

        this->hide(); // 隐藏当前的主窗口

        // 显示名为 main3 的窗口（假设 main3 是 MainWindow 类的一个成员变量，且是另一个窗口的实例）
        this->main3->show();
    }
}

void MainWindow::fromw2main()
{
    emit switch2main();
}

void MainWindow::switchOn()
{
    this->show(); // 显示主窗口，确保窗口可见

    // 根据变量 count 的值执行不同的游戏函数
    switch(count)
    {
    case 0:
        game2(); // 如果 count 为 0，调用 game2() 函数
        break;
    case 1:
        game3(); // 如果 count 为 1，调用 game3() 函数
        break;
    case 2:
        game4(); // 如果 count 为 2，调用 game4() 函数
        break;
    case 3:
        game5(); // 如果 count 为 3，调用 game5() 函数
        break;
    case 4:
        game6(); // 如果 count 为 4，调用 game6() 函数
        break;
    }

    count++; // 每次调用函数后，将 count 自增，用于下一次调用时执行下一个游戏函数
}
