#include "playscene2.h"
#include<QPainter>
#include<QBrush>
#include<QString>
#include<QKeyEvent>
#include<QTimer>
#include<QDebug>
#include<queue>
#include<QSound>
using namespace std;

//上1下2左3右4
vector<vector<int>>mainmap2={
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
    {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1},
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

//构造函数
PlayScene2::PlayScene2(QWidget *parent) : QMainWindow(parent)
{    mainmap2=forevermap;     
    //设置窗口固定大小
    setFixedSize(1050,725);
    //设置标题
    setWindowTitle("坦克大战");
    //设置图标
    setWindowIcon(QIcon("://res/tank_up.jpg"));
    setFocusPolicy(Qt::StrongFocus);
    //返回按钮
    backBtn2=new MyPushButton("://res3/back.tga");
    backBtn2->setParent(this);
    backBtn2->move(1050,750);
    connect(backBtn2,&MyPushButton::clicked,[=](){
        backBtn2->pop1();
        backBtn2->pop2();
        QTimer::singleShot(500,this,[=](){
            emit this->playScene2Back();
        });
    });

     //再玩一次按钮
     playBtn2=new MyPushButton("://res5/playagain.png");
     playBtn2->setParent(this);
     playBtn2->move(1050,750);
     connect(playBtn2,&MyPushButton::clicked,[=](){
         playBtn2->pop1();
         playBtn2->pop2();
         QTimer::singleShot(500,this,[=](){
            emit this->playScene2Again();
         });
     });

     //创造道具
     PopOutTool2=new QTimer(this);
     connect(PopOutTool2,&QTimer::timeout,[=](){
         if(ToolInfo[2]==-1){
          ToolInfo=CreateRandomPosAndTool2();}
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
void PlayScene2::paintEvent(QPaintEvent*event){
    if(IsGameOver&&!Btnmove2){
        Btnmove2=true;
        backBtn2->move(this->width()*0.5-backBtn2->width()*0.5,this->height()*0.75);
        playBtn2->move(this->width()*0.5-playBtn2->width()*0.5,this->height()*0.61);
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

    //判断敌方坦克是否初始化 若未初始化将敌方坦克初始化
    if(!your_tank->isInit){
    initYour_Tank();
    your_tank->isInit=true;
    }
    //加载四个方向敌方tank图片
    QPixmap pixUpE;
    pixUpE.load("://res/p2tankU.gif");
    QPixmap pixDownE;
    pixDownE.load("://res/p2tankD.gif");
    QPixmap pixLeftE;
    pixLeftE.load("://res/p2tankL.gif");
    QPixmap pixRightE;
    pixRightE.load("://res/p2tankR.gif");
    //加载道具图片
    QPixmap pixGun;
    pixGun.load("://res2/gun.png");
    QPixmap pixShield;
    pixShield.load("://res2/shield.png");
    QPixmap pixMine;
    pixMine.load("://res2/bomb.png");
 /**************************/

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
           if(mainmap2[i][j]==1){painter.drawPixmap(25*j,25*i,25,25,pix1);}
           if(mainmap2[i][j]==2){painter.drawPixmap(25*j,25*i,25,25,pix2);}
           if(mainmap2[i][j]==204){painter.drawPixmap(25*j,25*i,50,50,pixRight);}
           if(mainmap2[i][j]==203){painter.drawPixmap(25*j,25*i,50,50,pixLeft);}
           if(mainmap2[i][j]==202){painter.drawPixmap(25*j,25*i,50,50,pixDown);}
           if(mainmap2[i][j]==201){painter.drawPixmap(25*j,25*i,50,50,pixUp);}
           if(mainmap2[i][j]==304){painter.drawPixmap(25*j,25*i,50,50,pixRightE);}
           if(mainmap2[i][j]==303){painter.drawPixmap(25*j,25*i,50,50,pixLeftE);}
           if(mainmap2[i][j]==302){painter.drawPixmap(25*j,25*i,50,50,pixDownE);}
           if(mainmap2[i][j]==301){painter.drawPixmap(25*j,25*i,50,50,pixUpE);}
           if(mainmap2[i][j]>200&&mainmap2[i][j]<205&&my_tank->ShieldOn){painter.drawPixmap(25*j+12.5,25*i+12.5,25,25,pixShield);}
           if(mainmap2[i][j]>300&&mainmap2[i][j]<305&&your_tank->ShieldOn){painter.drawPixmap(25*j+12.5,25*i+12.5,25,25,pixShield);}

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
   if(my_tank->LaserOn){PaintLaserIsHit(my_tank,your_tank);}
   if(your_tank->LaserOn){PaintLaserIsHit(your_tank,my_tank);}

   //判断我方坦克是不是还活着
   DeathEffect(my_tank);
   DeathEffect(your_tank);

   // 画子弹 同时判断子弹有没有击中tank
   paintBullet(bullet1);
   BulletHitTank(your_tank,bullet1);
   BulletHitTank(my_tank,bullet1);
   paintBullet(bullet2);
   BulletHitTank(your_tank,bullet2);
   BulletHitTank(my_tank,bullet2);
   paintBullet(bullet3);
   BulletHitTank(your_tank,bullet3);
   BulletHitTank(my_tank,bullet3);

   paintBullet(bullet1Y);
   BulletHitTank(your_tank,bullet1Y);
   BulletHitTank(my_tank,bullet1Y);
   paintBullet(bullet2Y);
   BulletHitTank(your_tank,bullet2Y);
   BulletHitTank(my_tank,bullet2Y);
   paintBullet(bullet3Y);
   BulletHitTank(your_tank,bullet3Y);
   BulletHitTank(my_tank,bullet3Y);

   paintMine(Mine);
   if(isPlaced){
   MineHitTank(your_tank,Mine);
   MineHitTank(my_tank,Mine);}

   if((!my_tank->alive||!your_tank->alive)&&!isOver){
       IsOver=new QTimer(this);
       connect(IsOver,&QTimer::timeout,[=](){
           isOver=true;
           IsOver->stop();
           update();
       });
       IsOver->start(3000);
   }
   if(isOver){
       GameOver();
   }
 }

//初始化我方tank
void PlayScene2::initMy_Tank(){
    PopOutTool2->start(10000);
      //背景音乐
      //QSound * startSound=new QSound("://music/background.wav",this);
      //startSound->play();
      my_tank->x=1;
      my_tank->y=1;
      my_tank->direction=4;
      my_tank->alive=true;
      my_tank->IsGood=true;
    //初始化我方tank的位置
      my_tank->LocationSetting(mainmap2,ToolInfo,my_tank->direction);
     movespeed=new QTimer(this);
     connect(movespeed,&QTimer::timeout,[=](){
        SpeedControl=true;
     });
     movespeed->start(200);
}

//初始化敌方tank
void PlayScene2::initYour_Tank(){
      your_tank->x=35;
      your_tank->y=20;
      your_tank->direction=3;
      your_tank->alive=true;
      your_tank->IsGood=false;
    //初始化敌方tank的位置
      your_tank->LocationSetting(mainmap2,ToolInfo,your_tank->direction);
     movespeed2=new QTimer(this);
     connect(movespeed2,&QTimer::timeout,[=](){
        SpeedControl2=true;
     });
     movespeed2->start(200);
}

//初始化子弹
void PlayScene2::initBullet(tank_s* tank,bullet_s*bullet,int direction){
    bullet->init(tank,direction);
    connect(bullet->timer,&QTimer::timeout,[=](){
        bullet->update=true;
        update();
    });
}

//创造道具
vector<int> PlayScene2::CreateRandomPosAndTool2(){
    vector<int>res2;
    int x=0,y=0;
    while(mainmap2[x][y]!=0){
     x=qrand()%29;
     y=qrand()%42;
    }
    int tooltype=qrand()%3;
   mainmap2[x][y]=250;
   res2.push_back(x);
   res2.push_back(y);
   res2.push_back(tooltype);
    return res2;
}

//我方坦克的移动-键盘事件控制
void PlayScene2::keyPressEvent(QKeyEvent *event){

    if(my_tank->alive){
    if(event->key()==Qt::Key_W&&SpeedControl){
        SpeedControl=false;
        if(my_tank->direction!=1)
        {my_tank->LocationSetting(mainmap2,ToolInfo,1);update();my_tank->direction=1;return;}
        if(my_tank->checkTankIsMoveable(mainmap2))
        {my_tank->update(mainmap2,ToolInfo);update();}

    }
    if(event->key()==Qt::Key_S&&SpeedControl){
        SpeedControl=false;
        if(my_tank->direction!=2)
        {my_tank->LocationSetting(mainmap2,ToolInfo,2);update();my_tank->direction=2;return;}
        if(my_tank->checkTankIsMoveable(mainmap2))
        {my_tank->update(mainmap2,ToolInfo);update();}
    }
    if(event->key()==Qt::Key_A&&SpeedControl){
        SpeedControl=false;
        if(my_tank->direction!=3)
        {my_tank->LocationSetting(mainmap2,ToolInfo,3);update(); my_tank->direction=3;return;}
        if(my_tank->checkTankIsMoveable(mainmap2))
        {my_tank->update(mainmap2,ToolInfo);update();}
    }
    if(event->key()==Qt::Key_D&&SpeedControl){
        SpeedControl=false;
        if(my_tank->direction!=4)
        {my_tank->LocationSetting(mainmap2,ToolInfo,4);update();my_tank->direction=4;return;}
        if(my_tank->checkTankIsMoveable(mainmap2))
        {my_tank->update(mainmap2,ToolInfo);update();}
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
                     laser->stop();
                 });
                 laser->start(1000);
                 my_tank->ToolType=-1;
                 update();
             }
             else if(my_tank->ToolType==1){
                 my_tank->ShieldOn=true;
                 my_tank->ToolType=-1;
                 update();
             }
             else if(my_tank->ToolType==2){
                 Mine->isMine=true;
                 isPlaced=false;
                 initBullet(my_tank,Mine,my_tank->direction);
                 Mine->timer->stop();
                 my_tank->ToolType=-1;
                 connect(Mine->timer,&QTimer::timeout,[=](){
                     isPlaced=true;
                     Mine->timer->stop();
                 });
                 Mine->timer->start(3000);
                 update();
             }
    }
}
    if(your_tank->alive){
    if(event->key()==Qt::Key_Up&&SpeedControl2){
        SpeedControl2=false;
        if(your_tank->direction!=1)
        {your_tank->LocationSetting(mainmap2,ToolInfo,1);update();your_tank->direction=1;return;}
        if(your_tank->checkTankIsMoveable(mainmap2))
        {your_tank->update(mainmap2,ToolInfo);update();}

    }
    if(event->key()==Qt::Key_Down&&SpeedControl2){
        SpeedControl2=false;
        if(your_tank->direction!=2)
        {your_tank->LocationSetting(mainmap2,ToolInfo,2);update();your_tank->direction=2;return;}
        if(your_tank->checkTankIsMoveable(mainmap2))
        {your_tank->update(mainmap2,ToolInfo);update();}
    }
    if(event->key()==Qt::Key_Left&&SpeedControl2){
        SpeedControl2=false;
        if(your_tank->direction!=3)
        {your_tank->LocationSetting(mainmap2,ToolInfo,3);update(); your_tank->direction=3;return;}
        if(your_tank->checkTankIsMoveable(mainmap2))
        {your_tank->update(mainmap2,ToolInfo);update();}
    }
    if(event->key()==Qt::Key_Right&&SpeedControl2){
        SpeedControl2=false;
        if(your_tank->direction!=4)
        {your_tank->LocationSetting(mainmap2,ToolInfo,4);update();your_tank->direction=4;return;}
        if(your_tank->checkTankIsMoveable(mainmap2))
        {your_tank->update(mainmap2,ToolInfo);update();}
    }
    if(event->key()==Qt::Key_1){
        SpeedControl2=false;
             if(bullet1Y->isHit){
         initBullet(your_tank,bullet1Y,your_tank->direction);
        }
        else if(bullet2Y->isHit){
         initBullet(your_tank,bullet2Y,your_tank->direction);
        }
        else if(bullet3Y->isHit){
         initBullet(your_tank,bullet3Y,your_tank->direction);
        }
    }
    if(event->key()==Qt::Key_2){
             if(your_tank->ToolType==0){

                 your_tank->LaserOn=true;
                 QTimer* laser=new QTimer(this);
                 connect(laser,&QTimer::timeout,[=](){
                     your_tank->LaserOn=false;
                     laser->stop();
                 });
                 laser->start(1000);
                 your_tank->ToolType=-1;
                 update();
             }
             else if(your_tank->ToolType==1){
                 your_tank->ShieldOn=true;
                 your_tank->ToolType=-1;
                 update();
             }
             else if(your_tank->ToolType==2){
                 Mine->isMine=true;
                 isPlaced=false;
                 initBullet(your_tank,Mine,your_tank->direction);
                 Mine->timer->stop();
                 your_tank->ToolType=-1;
                 connect(Mine->timer,&QTimer::timeout,[=](){
                     isPlaced=true;
                     Mine->timer->stop();
                 });
                 Mine->timer->start(3000);
                 update();
             }
    }
}
    QWidget::keyPressEvent(event);
}

//画子弹
void PlayScene2::paintBullet(bullet_s*bullet){
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
void PlayScene2::paintMine(bullet_s *mine){
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
void PlayScene2::PaintLaserIsHit(tank_s*tank,tank_s*tank2){
    QPainter painterlaser(this);
    QBrush Brushlaser(Qt::red);
    painterlaser.setBrush(Brushlaser);
    if(tank->direction==1){
        painterlaser.drawRect(tank->x*25+22.5,0,5,tank->y*25);
        if(tank->x+1>tank2->x&&tank->x+1<tank2->x+2){
            tank2->alive=false;
        }
    }
    else if(tank->direction==2){
       painterlaser.drawRect(tank->x*25+22.5,tank->y*25+50,5,1000);
       if(tank->x+1>tank2->x&&tank->x+1<tank2->x+2){
          tank2->alive=false;

       }
    }
    else if(tank->direction==3){
        painterlaser.drawRect(0,tank->y*25+22.5,tank->x*25,5);
        if(tank->y+1>tank2->y&&tank->y+1<tank2->y+2){
            tank2->alive=false;

        }
    }
    else if(tank->direction==4){
        painterlaser.drawRect(tank->x*25+50,tank->y*25+22.5,1000,5);
        if(tank->y+1>tank2->y&&tank->y+1<tank2->y+2){
            tank2->alive=false;
        }
    }
}

//画死亡效果
void PlayScene2::DeathEffect(tank_s*tank){
    if(!tank->alive){
        if(!tank->DieOnce)
        {QSound*BoomSound=new QSound("://music/boom.wav",this);
        BoomSound->play();}
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
void PlayScene2::BulletHitWall(bullet_s*bullet,int x,int y){
    if(mainmap2[y/25][x/25]==1){
       bullet->partBulletHitWall();
       update();
    }
    else if(mainmap2[y/25-1][x/25]==1){
        bullet->partBulletHitWall();
        update();
    }
    else if(mainmap2[y/25][x/25-1]==1){
        bullet->partBulletHitWall();
        update();
    }
    if(mainmap2[y/25][x/25]==2)
    {mainmap2[y/25][x/25]=0;
        bullet->BulletHit();
        update();
    }
    else if(mainmap2[y/25-1][x/25]==2)
    {mainmap2[y/25-1][x/25]=0;
        bullet->BulletHit();
        update();
    }
    else if(mainmap2[y/25][x/25-1]==2)
    {mainmap2[y/25][x/25-1]=0;
        bullet->BulletHit();
        update();
    }
}

//判断子弹击中坦克
void PlayScene2::BulletHitTank(tank_s*tank,bullet_s*bullet){
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
        tank->alive=false;}

    }
}

//判断地雷击中坦克
void PlayScene2::MineHitTank(tank_s*tank,bullet_s*mine){
    int x=tank->x*25-12.5;
    int y=tank->y*25-12.5;
    bool f1=mine->x>x&&mine->x<x+50;
    bool f2=mine->y>y&&mine->y<y+50;
   if(f1&&f2&&tank->alive){
        mine->BulletHit();
        update();
        tank->alive=false;
    }
}

//游戏结束
void PlayScene2::GameOver(){
      QPixmap over;
      over.load("://res3/gameover.jpg");
      QPainter overpainter(this);
      overpainter.drawPixmap
     (this->width()*0.5-over.width(),this->height()*0.17,over.width()*2,over.height()*2,over);
      IsGameOver=true;
}
