#include "choosemodelscene.h"
#include<QPainter>
#include<QTimer>
#include<QDebug>
#include"mypushbutton.h"
ChooseModelScene::ChooseModelScene(QWidget *parent) : QMainWindow(parent)
{    //设置窗口固定大小
    setFixedSize(1050,725);
    //设置标题
    setWindowTitle("坦克大战");
    //设置图标
    setWindowIcon(QIcon("://res/tank_up.jpg"));
    //创建场景
    playscene=new PlayScene(this);
    playscene2=new PlayScene2(this);
    //设置按钮
    MyPushButton*oneBtn=new MyPushButton("://res2/1player.png");
    MyPushButton*twoBtn=new MyPushButton("://res2/2player.png");
    oneBtn->setParent(this);
    twoBtn->setParent(this);
    oneBtn->move(this->width()*0.5-oneBtn->width()*0.5,this->height()*0.6);
    twoBtn->move(this->width()*0.5-twoBtn->width()*0.5,this->height()*0.7);

    connect(oneBtn,&MyPushButton::clicked,[=](){
       oneBtn->pop1();
       oneBtn->pop2();
       QTimer::singleShot(500,this,[=](){
           this->hide();
           playscene->show();
       });
       connect(playscene,&PlayScene::playSceneBack,[=](){
           playscene->close();
           delete playscene;
           playscene=new PlayScene(this);
           this->show();
       });
       connect(playscene,&PlayScene::playSceneAgain,[=](){
           playscene->close();
           delete playscene;
           playscene=new PlayScene(this);
           oneBtn->click();
           playscene->show();
       });
    });


    connect(twoBtn,&MyPushButton::clicked,[=](){
       twoBtn->pop1();
       twoBtn->pop2();
       QTimer::singleShot(500,this,[=](){
           this->hide();
           playscene2->show();
       });
       connect(playscene2,&PlayScene2::playScene2Back,[=](){          
           playscene2->close();
           delete playscene2;
           playscene2=new PlayScene2(this);
           this->show();
       });
       connect(playscene2,&PlayScene2::playScene2Again,[=](){
           playscene2->close();
           delete playscene2;
           playscene2=new PlayScene2(this);
           twoBtn->click();
           playscene2->show();
       });

    });
    //返回按钮
    MyPushButton*backBtn=new MyPushButton("://res3/back.tga");
    backBtn->setParent(this);
    backBtn->move(this->width()*0.5-backBtn->width()*0.5,this->height()*0.8);
    connect(backBtn,&MyPushButton::clicked,[=](){
        backBtn->pop1();
        backBtn->pop2();
        QTimer::singleShot(500,this,[=](){
            emit this->chooseModelSceneBack();

        });
    });
}
void ChooseModelScene::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QBrush Brush(Qt::black);
    QPixmap pixlogo;
    pixlogo.load("://res/logo.bmp");
    painter.setBrush(Brush);
    painter.drawRect(0,0,this->width(),this->height());
    painter.drawPixmap(230,75,600,200,pixlogo);
}
