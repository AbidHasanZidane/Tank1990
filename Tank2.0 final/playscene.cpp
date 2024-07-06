#include "playscene.h"
#include<QPainter>
#include<QBrush>
#include<QString>
#include<QKeyEvent>
#include<QTimer>
#include<QDebug>
#include<queue>
#include<QSoundEffect>
#include <QRandomGenerator>
using namespace std;

//上1下2左3右4
vector<vector<int>>mainmap={
    // 1表示不能打碎的墙 2表示可以打碎的墙
    //1
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,2,2,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
    //2
    {1,0,0,2,0,0,0,0,0,1,0,0,0,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1},
    {1,0,0,2,0,0,0,0,0,1,0,0,0,2,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,2,0,0,0,0,0,1,0,0,0,2,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,2,2,2,0,0,0,0,0,1,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    //3
    {1,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    //4
    {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1},
    //5
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
    //6
    {1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1},
    //7
    {1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    //8
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
vector<vector<int> >tempmap=mainmap;
//构造函数
PlayScene::PlayScene(QWidget *parent) : QMainWindow(parent)
{   mainmap=forevermap;
    tempmap=forevermap;
    //设置窗口固定大小
    setFixedSize(1050,725);
    //设置标题
    setWindowTitle("坦克大战");
    //设置图标
    setWindowIcon(QIcon("://res/tank_up.jpg"));
    //返回按钮
    backBtn=new MyPushButton("://res3/back.tga");
    backBtn->setParent(this);
    backBtn->move(1050,750);
    connect(backBtn,&MyPushButton::clicked,[=](){
        backBtn->pop1();
        backBtn->pop2();
        QTimer::singleShot(500,this,[=](){
            emit this->playSceneBack();
        });
    });

    //再玩一次按钮
    playBtn=new MyPushButton("://res5/playagain.png");
    playBtn->setParent(this);
    playBtn->move(1050,750);
    connect(playBtn,&MyPushButton::clicked,[=](){
        playBtn->pop1();
        playBtn->pop2();
        QTimer::singleShot(500,this,[=](){
           emit this->playSceneAgain();
        });
    });

    //创造道具
    PopOutTool=new QTimer(this);
    connect(PopOutTool,&QTimer::timeout,[=](){
        if(ToolInfo[2]==-1){
         ToolInfo=CreateRandomPosAndTool();}
    });

    //河流流动
    riverflow=new QTimer(this);
     connect(riverflow,&QTimer::timeout,[=](){
         river1=river1?false:true;
         update();
     });
    riverflow->start(100);

}

//画基本地图 画坦克
void PlayScene::paintEvent(QPaintEvent*event){
if(IsGameOver&&!Btnmove)
{   Btnmove=true;
    backBtn->move(this->width()*0.5-backBtn->width()*0.5,this->height()*0.75);
    playBtn->move(this->width()*0.5-playBtn->width()*0.5,this->height()*0.61);
}

 /**************************/
    //判断我方坦克是否初始化 若未初始化将我方坦克初始化
    if(!my_tank->isInit){
    initMy_Tank();
    my_tank->isInit=true;
    }
    //加载四个方向我方tank图片
    QPixmap pixUp;
    pixUp.load("://res/tank_up.jpg");
    QPixmap pixDown;
    pixDown.load("://res/tank_down.jpg");
    QPixmap pixLeft;
    pixLeft.load("://res/tank_left.jpg");
    QPixmap pixRight;
    pixRight.load("://res/tank_right.jpg");
 /**************************/

    //判断敌方坦克是否初始化 若未初始化将敌方坦克初始化
    if(!enemy_tank->isInit){
    initEnemy_Tank();
    enemy_tank->isInit=true;
    }
    //加载四个方向敌方tank图片
    QPixmap pixUpE;
    pixUpE.load("://res3/enemy_tank_down.jpg");
    QPixmap pixDownE;
    pixDownE.load("://res/enemy_tank_up.jpg");
    QPixmap pixLeftE;
    pixLeftE.load("://res3/enemy_tank_left.jpg");
    QPixmap pixRightE;
    pixRightE.load("://res/enemy_tank_right.jpg");
 /**************************/
    //加载道具图片
    QPixmap pixGun;
    pixGun.load("://res2/gun.png");
    QPixmap pixShield;
    pixShield.load("://res2/shield.png");
    QPixmap pixMine;
    pixMine.load("://res2/bomb.png");

    QPainter painter(this);
    QBrush Brush(Qt::black);
    QPixmap pix1;
    pix1.load("://res/wall2.jpg");
    QPixmap pix2;
    pix2.load("://res/wall1.jpg");
    QPixmap pix3;
    pix3.load("://res2/tree.png");
    QPixmap pix4;
    pix4.load("://res2/river1.png");
    QPixmap pix5;
    pix5.load("://res2/river2.png");
    painter.setBrush(Brush);
    painter.drawRect(0,0,this->width(),this->height());

     //画河流
    for(int j=20;j<41;++j){
        if(river1){
        painter.drawPixmap(25*j,25*7,25,25,pix4);
        painter.drawPixmap(25*j,25*8,25,25,pix4);
        }
        else{
        painter.drawPixmap(25*j,25*7,25,25,pix5);
        painter.drawPixmap(25*j,25*8,25,25,pix5);
        }
    }

   for(int i=0;i<29;++i){
       for(int j=0;j<42;++j){
           if(mainmap[i][j]==1){painter.drawPixmap(25*j,25*i,25,25,pix1);}
           if(mainmap[i][j]==2){painter.drawPixmap(25*j,25*i,25,25,pix2);}
           if(mainmap[i][j]==204){painter.drawPixmap(25*j,25*i,50,50,pixRight);}
           if(mainmap[i][j]==203){painter.drawPixmap(25*j,25*i,50,50,pixLeft);}
           if(mainmap[i][j]==202){painter.drawPixmap(25*j,25*i,50,50,pixDown);}
           if(mainmap[i][j]==201){painter.drawPixmap(25*j,25*i,50,50,pixUp);}
           if(mainmap[i][j]==304){painter.drawPixmap(25*j,25*i,50,50,pixRightE);}
           if(mainmap[i][j]==303){painter.drawPixmap(25*j,25*i,50,50,pixLeftE);}
           if(mainmap[i][j]==302){painter.drawPixmap(25*j,25*i,50,50,pixDownE);}
           if(mainmap[i][j]==301){painter.drawPixmap(25*j,25*i,50,50,pixUpE);}
           if(mainmap[i][j]>200&&mainmap[i][j]<205&&my_tank->ShieldOn){painter.drawPixmap(25*j+12.5,25*i+12.5,25,25,pixShield);}
       }
   }

   //画草丛
   for(int i=5;i<11;++i){
       for(int j=14;j<20;++j){
           painter.drawPixmap(25*j,25*i,25,25,pix3);
       }
   } 

   //画道具
   if(ToolInfo[2]==0){
       painter.drawPixmap(25*ToolInfo[1],25*ToolInfo[0],30,30,pixGun);
   }
   else if(ToolInfo[2]==1){
       painter.drawPixmap(25*ToolInfo[1],25*ToolInfo[0],30,30,pixShield);
   }
   else if(ToolInfo[2]==2){
       painter.drawPixmap(25*ToolInfo[1],25*ToolInfo[0],30,30,pixMine);
   }

   //画镭射效果
   if(my_tank->LaserOn){PaintLaserIsHit(my_tank);}

   //判断我方坦克是不是还活着
   DeathEffect(my_tank);
   DeathEffect(enemy_tank);

   // 画子弹地雷 同时判断子弹地雷有没有击中tank
   paintBullet(bullet1);
   BulletHitTank(enemy_tank,bullet1);
   BulletHitTank(my_tank,bullet1);
   paintBullet(bullet2);
   BulletHitTank(enemy_tank,bullet2);
   BulletHitTank(my_tank,bullet2);
   paintBullet(bullet3);
   BulletHitTank(enemy_tank,bullet3);
   BulletHitTank(my_tank,bullet3);

   paintBullet(bullet1E);
   BulletHitTank(enemy_tank,bullet1E);
   BulletHitTank(my_tank,bullet1E);
   paintBullet(bullet2E);
   BulletHitTank(enemy_tank,bullet2E);
   BulletHitTank(my_tank,bullet2E);
   paintBullet(bullet3E);
   BulletHitTank(enemy_tank,bullet3E);
   BulletHitTank(my_tank,bullet3E);

   paintMine(Mine);
   if(isPlaced){
   MineHitTank(enemy_tank,Mine);
   MineHitTank(my_tank,Mine);}


   //游戏结束
  if((!my_tank->alive||!enemy_tank->alive)&&!isOver){
      IsOver=new QTimer(this);
      connect(IsOver,&QTimer::timeout,[=](){
          isOver=true;
          IsOver->stop();
          update();
      });
      IsOver->start(3000);
  }
  if(isOver){ GameOver(); }
}

//初始化我方tank
void PlayScene::initMy_Tank(){
     PopOutTool->start(10000);
      //背景音乐
      //QSound * startSound=new QSound("://music/background.wav",this);
      //startSound->play();
      my_tank->x=1;
      my_tank->y=1;
      my_tank->direction=4;
      my_tank->alive=true;
      my_tank->IsGood=true;
    //初始化我方tank的位置
      my_tank->LocationSetting(mainmap,ToolInfo,my_tank->direction);
     movespeed=new QTimer(this);
     connect(movespeed,&QTimer::timeout,[=](){
        SpeedControl=true;
     });
     movespeed->start(200);

}

//初始化敌方tank
void PlayScene::initEnemy_Tank(){
      enemy_tank->x=35;
      enemy_tank->y=20;
      enemy_tank->direction=3;
      enemy_tank->alive=true;
      enemy_tank->IsGood=false;
    //初始化敌方tank的位置
      enemy_tank->LocationSetting(mainmap,ToolInfo,enemy_tank->direction);
     reroute=new QTimer(this);
     EnemyTankMove();
     connect(reroute,&QTimer::timeout,[=](){
         EnemyTimer->stop();
         EnemyTankMove();

     });
     reroute->start(3000);

     DodgeTimer=new QTimer(this);
     connect(DodgeTimer,&QTimer::timeout,[=](){
         if(enemy_tank->alive&&SpeedControl2){
             DodgeBullet(bullet1);
             DodgeBullet(bullet2);
             DodgeBullet(bullet3);
             DodgeBullet(bullet1E);
             DodgeBullet(bullet2E);
             DodgeBullet(bullet3E);           
        }
         });
     DodgeTimer->start(600);

     movespeed2=new QTimer(this);
     connect(movespeed2,&QTimer::timeout,[=](){
        if(enemy_tank->alive){
        SpeedControl2=true;}
     });
     movespeed2->start(300);
}

//初始化子弹
void PlayScene::initBullet(tank_s* tank,bullet_s*bullet,int direction){
    bullet->init(tank,direction);
    connect(bullet->timer,&QTimer::timeout,[=](){
        bullet->update=true;
        update();
    });
}

//创造道具
vector<int> PlayScene::CreateRandomPosAndTool(){
    vector<int>res;
    int x = 0, y = 0;
    QRandomGenerator randomGenerator;

    while (mainmap[x][y] != 0) {
        x = randomGenerator.bounded(29);  // Generates a random integer in the range [0, 29)
        y = randomGenerator.bounded(42);  // Generates a random integer in the range [0, 42)
    }
    int tooltype=randomGenerator.bounded(3);
    mainmap[x][y]=250;
    res.push_back(x);
    res.push_back(y);
    res.push_back(tooltype);
    return res;
}

//我方坦克的移动-键盘事件控制
void PlayScene::keyPressEvent(QKeyEvent *event){
    if(my_tank->alive&&!IsGameOver){
    if(event->key()==Qt::Key_W&&SpeedControl){
        SpeedControl=false;
        if(my_tank->direction!=1)
        {my_tank->LocationSetting(mainmap,ToolInfo,1);update();my_tank->direction=1;return;}
        if(my_tank->checkTankIsMoveable(mainmap))
        {my_tank->update(mainmap,ToolInfo);update();}

    }
    if(event->key()==Qt::Key_S&&SpeedControl){
        SpeedControl=false;
        if(my_tank->direction!=2)
        {my_tank->LocationSetting(mainmap,ToolInfo,2);update();my_tank->direction=2;return;}
        if(my_tank->checkTankIsMoveable(mainmap))
        {my_tank->update(mainmap,ToolInfo);update();}
    }
    if(event->key()==Qt::Key_A&&SpeedControl){
        SpeedControl=false;
        if(my_tank->direction!=3)
        {my_tank->LocationSetting(mainmap,ToolInfo,3);update(); my_tank->direction=3;return;}
        if(my_tank->checkTankIsMoveable(mainmap))
        {my_tank->update(mainmap,ToolInfo);update();}
    }
    if(event->key()==Qt::Key_D&&SpeedControl){
        SpeedControl=false;
        if(my_tank->direction!=4)
        {my_tank->LocationSetting(mainmap,ToolInfo,4);update();my_tank->direction=4;return;}
        if(my_tank->checkTankIsMoveable(mainmap))
        {my_tank->update(mainmap,ToolInfo);update();}
    }
    if(event->key()==Qt::Key_J){
        SpeedControl=false;
             if(bullet1->isHit){
         initBullet(my_tank,bullet1,my_tank->direction);
        }
        else if(bullet2->isHit){
         initBullet(my_tank,bullet2,my_tank->direction);
        }
        else if(bullet3->isHit){
         initBullet(my_tank,bullet3,my_tank->direction);
        }
    }
    if(event->key()==Qt::Key_K){
             if(my_tank->ToolType==0){
                 my_tank->LaserOn=true;
                 QTimer* laser=new QTimer(this);
                 connect(laser,&QTimer::timeout,[=](){
                     my_tank->LaserOn=false;
                 });
                 laser->start(1000);
                 my_tank->ToolType=-1;
             }
             else if(my_tank->ToolType==1){
                 my_tank->ShieldOn=true;
                 my_tank->ToolType=-1;
             }
             else if(my_tank->ToolType==2){
                 Mine->isMine=true;
                 isPlaced=false;
                 initBullet(my_tank,Mine,my_tank->direction);
                 Mine->timer->stop();
                 my_tank->ToolType=-1;
                 connect(Mine->timer,&QTimer::timeout,[=](){
                     isPlaced=true;
                 });
                 Mine->timer->start(3000);

             }
    }
}
    QWidget::keyPressEvent(event);
}

//画子弹
void PlayScene::paintBullet(bullet_s*bullet){
    if(bullet->HitsNum>3){bullet->BulletHit();update();}
    if(!bullet->isHit){
        QPainter painterbullet(this);
        QBrush Brushbullet(Qt::gray);
        painterbullet.setBrush(Brushbullet);
    if(bullet->direction==1){
      painterbullet.drawEllipse(QPoint(bullet->x,bullet->y),5,5);
      if(bullet->update){
      bullet->update=false;
      --bullet->y;
      if(bullet->y<30){bullet->direction=2;++bullet->HitsNum;update();}
      BulletHitWall(bullet,bullet->x,bullet->y);}
    }
    if(bullet->direction==2){
      painterbullet.drawEllipse(QPoint(bullet->x,bullet->y),5,5);
      if(bullet->update){
      bullet->update=false;
      ++bullet->y;
      if(bullet->y>695){bullet->direction=1;++bullet->HitsNum;update();}
      BulletHitWall(bullet,bullet->x,bullet->y);}
    }
    if(bullet->direction==3){
      painterbullet.drawEllipse(QPoint(bullet->x,bullet->y),5,5);
      if(bullet->update){
      bullet->update=false;
      --bullet->x;
      if(bullet->x<30){bullet->direction=4;++bullet->HitsNum;update();}
      BulletHitWall(bullet,bullet->x,bullet->y);}
    }

    if(bullet->direction==4){
      painterbullet.drawEllipse(QPoint(bullet->x,bullet->y),5,5);
      if(bullet->update){
      bullet->update=false;
      ++bullet->x;
      if(bullet->x>1020){bullet->direction=3;++bullet->HitsNum;update();}
      BulletHitWall(bullet,bullet->x,bullet->y);}
    }
    }
}

//画地雷
void PlayScene::paintMine(bullet_s *mine){
    if(!mine->isHit&&!isPlaced){
        QPainter paintermine(this);
        QPixmap pixSnail;
        pixSnail.load("://res5/icon_bomb.png");
    if(mine->direction==1){
     paintermine.drawPixmap(mine->x,mine->y,25,25,pixSnail);
      if(mine->update){
      mine->update=false;}
    }
    if(mine->direction==2){
     paintermine.drawPixmap(mine->x,mine->y,25,25,pixSnail);
      if(mine->update){
      mine->update=false;}
    }
    if(mine->direction==3){
     paintermine.drawPixmap(mine->x,mine->y,25,25,pixSnail);
      if(mine->update){
      mine->update=false;}
    }

    if(mine->direction==4){
     paintermine.drawPixmap(mine->x,mine->y,25,25,pixSnail);
      if(mine->update){
      mine->update=false;}
    }
    }

}

//画镭射效果
void PlayScene::PaintLaserIsHit(tank_s*tank){
    QPainter painterlaser(this);
    QBrush Brushlaser(Qt::red);
    painterlaser.setBrush(Brushlaser);
    if(tank->direction==1){
        painterlaser.drawRect(tank->x*25+22.5,0,5,tank->y*25);
        if(tank->x+1>enemy_tank->x&&tank->x+1<enemy_tank->x+2){
            enemy_tank->alive=false;
            EnemyTimer->stop();
            reroute->stop();
        }
    }
    else if(tank->direction==2){
       painterlaser.drawRect(tank->x*25+22.5,tank->y*25+50,5,1000);
       if(tank->x+1>enemy_tank->x&&tank->x+1<enemy_tank->x+2){
           enemy_tank->alive=false;
           EnemyTimer->stop();
           reroute->stop();
       }
    }
    else if(tank->direction==3){
        painterlaser.drawRect(0,tank->y*25+22.5,tank->x*25,5);
        if(tank->y+1>enemy_tank->y&&tank->y+1<enemy_tank->y+2){
            enemy_tank->alive=false;
            EnemyTimer->stop();
            reroute->stop();
        }
    }
    else if(tank->direction==4){
        painterlaser.drawRect(tank->x*25+50,tank->y*25+22.5,1000,5);
        if(tank->y+1>enemy_tank->y&&tank->y+1<enemy_tank->y+2){
            enemy_tank->alive=false;
            EnemyTimer->stop();
            reroute->stop();
        }
    }
}

//画死亡效果
void PlayScene::DeathEffect(tank_s*tank){
    if(!tank->alive){

        tank->DieOnce=true;
        QPainter painter(this);
        QBrush Brush(Qt::black);
       painter.setBrush(Brush);
        QPixmap pixmap;
        QString str=QString("://res/blast8.gif");
        pixmap.load(str);
        painter.drawRect(tank->x*25,tank->y*25,50,50);
        painter.drawPixmap(tank->x*25,tank->y*25,50,50,pixmap);
    }
}

//判断子弹击中墙
void PlayScene::BulletHitWall(bullet_s*bullet,int x,int y){
    if(mainmap[y/25][x/25]==1){
       bullet->partBulletHitWall();
       update();
    }
    else if(mainmap[y/25-1][x/25]==1){
        bullet->partBulletHitWall();
        update();
    }
    else if(mainmap[y/25][x/25-1]==1){
        bullet->partBulletHitWall();
        update();
    }
    if(mainmap[y/25][x/25]==2)
    {mainmap[y/25][x/25]=0;
     tempmap[y/25][x/25]=0;
     bullet->BulletHit();
     update();
    }
    else if(mainmap[y/25-1][x/25]==2)
    {mainmap[y/25-1][x/25]=0;
     tempmap[y/25-1][x/25]=0;
     bullet->BulletHit();
     update();
    }
    else if(mainmap[y/25][x/25-1]==2)
    {mainmap[y/25][x/25-1]=0;
        tempmap[y/25][x/25-1]=0;
        bullet->BulletHit();
        update();
    }
}

//判断子弹击中坦克
void PlayScene::BulletHitTank(tank_s*tank,bullet_s*bullet){
    int x=tank->x*25;
    int y=tank->y*25;
    bool f1=bullet->x>x&&bullet->x<x+50;
    bool f2=bullet->y>y&&bullet->y<y+50;
    if(f1&&f2&&tank->alive){
        bullet->BulletHit();
        update();
        if(tank->ShieldOn){
        tank->ShieldOn=false;
        }
       else{
        tank->alive=false;
        EnemyTimer->stop();
        reroute->stop();
       }
    }
}

//判断地雷击中坦克
void PlayScene::MineHitTank(tank_s*tank,bullet_s*mine){
    int x=tank->x*25-12.5;
    int y=tank->y*25-12.5;
    bool f1=mine->x>x&&mine->x<x+50;
    bool f2=mine->y>y&&mine->y<y+50;
   if(f1&&f2&&tank->alive){
        mine->BulletHit();
        update();
        tank->alive=false;
        EnemyTimer->stop();
        reroute->stop();
    }
}

//敌方坦克的移动
void PlayScene::EnemyTankMove(){
    EnemyTimer=new QTimer(this);
    res=BFS(tempmap);
    num=res.size()-1;
    connect(EnemyTimer,&QTimer::timeout,[&](){
       if(num>=0){
           if(enemy_tank->direction!=res[num])
           {enemy_tank->LocationSetting(mainmap,ToolInfo,res[num]);update();enemy_tank->direction=res[num];}

           bool exist=CheckAheadBullet(bullet1,res[num])||
           CheckAheadBullet(bullet1E,res[num])||
           CheckAheadBullet(bullet2,res[num])||
           CheckAheadBullet(bullet3,res[num])||
           CheckAheadBullet(bullet2E,res[num])||
           CheckAheadBullet(bullet3E,res[num]);
           if(enemy_tank->checkTankIsMoveable(mainmap)&&SpeedControl2&&!exist){
           SpeedControl2=false;
           enemy_tank->update(mainmap,ToolInfo);
           update();
           --num;
           }
       }
       else
       {EnemyTimer->stop();
      }
       EnemyFire();
    });
    EnemyTimer->start(300);
}

//敌方开火
void PlayScene::EnemyFire(){
         if(enemy_tank->x==my_tank->x){
             if(enemy_tank->y>my_tank->y&&enemy_tank->direction==1){
                 EnemyTimer->stop();
                 ShootBulletE();
            }
        else if(enemy_tank->y<my_tank->y&&enemy_tank->direction==2){
                 EnemyTimer->stop();                
                 ShootBulletE();
             }
    }
    else if(enemy_tank->y==my_tank->y){
             if(enemy_tank->x>my_tank->x&&enemy_tank->direction==3){
                 EnemyTimer->stop();
                 ShootBulletE();
             }
        else if(enemy_tank->x<my_tank->x&&enemy_tank->direction==4){
                 EnemyTimer->stop();
                 ShootBulletE();
             }
    }
}

//敌方子弹的射出
void PlayScene::ShootBulletE(){
     if(bullet1E->isHit){
initBullet(enemy_tank,bullet1E,enemy_tank->direction);
}
else if(bullet2E->isHit){
initBullet(enemy_tank,bullet2E,enemy_tank->direction);
}
else if(bullet3E->isHit){
initBullet(enemy_tank,bullet3E,enemy_tank->direction);
}
}

//敌方躲子弹
void PlayScene::Dodge(){
    SpeedControl2=false;
    enemy_tank->update(mainmap,ToolInfo);update();
    EnemyTimer->stop();
}
void PlayScene::DodgeBullet(bullet_s*bullet){
int enemy_x=enemy_tank->x*25;
int enemy_y=enemy_tank->y*25;
bool f1=bullet->x>enemy_x&&bullet->x<enemy_x+50;
bool f2=bullet->y>enemy_y&&bullet->y<enemy_y+50;
bool f3=bullet->direction==1||bullet->direction==2;
bool f4=bullet->direction==3||bullet->direction==4;
bool f5=f1&&f2;
if(!bullet->isHit&&!bullet->isMine&&!f5){
    if(f1&&f3){
        enemy_tank->direction=4;
        if(enemy_tank->checkTankIsMoveable(mainmap)&&SpeedControl2){
           Dodge();
        }
        else{enemy_tank->direction=3;
        if(enemy_tank->checkTankIsMoveable(mainmap)&&SpeedControl2){
           Dodge();
        }}
    }
    else if(f2&&f4){
         enemy_tank->direction=1;
         if(enemy_tank->checkTankIsMoveable(mainmap)&&SpeedControl2){
           Dodge();
            }
         else{enemy_tank->direction=2;
         if(enemy_tank->checkTankIsMoveable(mainmap)&&SpeedControl2){
           Dodge();
          }}
    }
}
}

bool PlayScene::CheckAheadBullet(bullet_s*bullet,int direction){
    int enemy_x=enemy_tank->x*25;
    int enemy_y=enemy_tank->y*25;
    bool f=false;
    if(bullet->isHit){return false;}
    if(bullet->isMine){return false;}
    if(direction==1){
         f=bullet->y>=enemy_y-50&&bullet->y<=enemy_y;
    }
    else if(direction==2){
         f=bullet->y>=enemy_y+50&&bullet->y<=enemy_y+100;
    }
    else if(direction==3){
         f=bullet->x>=enemy_x-50&&bullet->x<=enemy_x;
    }
    else if(direction==4){
         f=bullet->x>=enemy_x+50&&bullet->x<=enemy_x+100;
    }
    return f;
}

/**************************/
//广度优先搜索找到最短路径
vector<int> PlayScene::BFS(vector<vector<int>>tempmap){
    if(!my_tank->alive){return vector<int>{};}
    int num=4;
    queue<point>r;
    int dx[4]={0,1,0,-1};//右下左上
    int dy[4]={1,0,-1,0};
    point start;
    start.x=enemy_tank->y;
    start.y=enemy_tank->x;
    start.step=3;
    point end;
    end.x=my_tank->y;
    end.y=my_tank->x;
    end.step=3;

    r.push(start);//起点入队
    tempmap[start.x][start.y]=3;

    while(!r.empty()){
        int x=r.front().x;
        int y=r.front().y;
        if(x==end.x&&y==end.y){
            break;
        }
        if (r.front().step == num) {
                   ++num;
               }
        for(int k=0;k<=3;++k){
            int tx,ty;
            tx=x+dx[k];
            ty=y+dy[k];
            bool moveable = false;
            bool judge=true;
            if(tempmap[tx+1][ty]==1||tempmap[tx+1][ty]==2){judge=false;}
            if(tempmap[tx+1][ty+1]==1||tempmap[tx+1][ty+1]==2){judge=false;}
            if(tempmap[tx][ty+1]==1||tempmap[tx][ty+1]==2){judge=false;}
           if (tx >= 0 && ty >= 0 && tx < 29 && ty < 42)
           {
            if (tempmap[tx][ty] == 0&&judge)
            { moveable = true; }
           }
            if(moveable){
                point temp;
                temp.x=tx;
                temp.y=ty;
                temp.step=num;
                r.push(temp);
                tempmap[tx][ty]=num;
            }
        }
        r.pop();
    }
    vector<int>mark;
    int x=end.x;
    int y=end.y;
    num=tempmap[end.x][end.y];
    //上1下2左3右4
    for(int i=3;i<=tempmap[end.x][end.y];++i){
        --num;
        if (tempmap[x + 1][y] == num)
         {   x += 1;
             mark.push_back(1); }
         else if (tempmap[x - 1][y] == num)
         {   x -= 1;
             mark.push_back(2); }
         else if (tempmap[x][y + 1] == num)
         {   y += 1;
             mark.push_back(3); }
         else if (tempmap[x][y - 1] == num)
         {   y -= 1;
             mark.push_back(4); }
    }
    return mark;
}
/**************************/

//游戏结束
void PlayScene::GameOver(){
      QPixmap over;
      over.load("://res3/gameover.jpg");
      QPainter overpainter(this);
      overpainter.drawPixmap
     (this->width()*0.5-over.width(),this->height()*0.17,over.width()*2,over.height()*2,over);
      IsGameOver=true;

}

