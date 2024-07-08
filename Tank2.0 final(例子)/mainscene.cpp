#include "mainscene.h"
#include "ui_mainscene.h"
#include<QPainter>
#include<QBrush>
#include<QTimer>
#include<QDebug>
#include"mypushbutton.h"
MainScene::MainScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScene)
{
    ui->setupUi(this);
    //设置窗口固定大小
    setFixedSize(1050,725);
    //设置标题
    setWindowTitle("坦克大战");
    //设置图标
    setWindowIcon(QIcon("://res/tank_up.jpg"));
    //模式选择场景
    choosemodelscene=new ChooseModelScene;
    //开始按钮
    MyPushButton*startBtn=new MyPushButton("://res2/start.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5-startBtn->width()*0.5,this->height()*0.5);
    connect(startBtn,&MyPushButton::clicked,[=](){
       startBtn->pop1();
       startBtn->pop2();
       QTimer::singleShot(500,this,[=](){
           this->hide();
           choosemodelscene->show();
           connect(choosemodelscene,&ChooseModelScene::chooseModelSceneBack,this,[=](){
               this->show();
               choosemodelscene->hide();
           });
       });

    });
    //退出按钮
    MyPushButton*quitBtn=new MyPushButton("://res3/quit.tga");
    quitBtn->setParent(this);
    quitBtn->move(this->width()*0.5-quitBtn->width()*0.5,this->height()*0.7);
    connect(quitBtn,&MyPushButton::clicked,[=](){
        quitBtn->pop1();
        quitBtn->pop2();
        QTimer::singleShot(500,this,[=](){
            this->close();
        });
    });

   //设置标签颜色
    ui->label->setStyleSheet("color:rgb(255, 255, 255)");
    ui->label_2->setStyleSheet("color:rgb(255, 255, 255)");
    ui->label_3->setStyleSheet("color:rgb(255, 255, 255)");
    ui->label_4->setStyleSheet("color:rgb(255, 255, 255)");
    ui->label_5->setStyleSheet("color:rgb(255, 255, 255)");
    ui->label_6->setStyleSheet("color:rgb(255, 255, 255)");


}
void MainScene::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QBrush Brush(Qt::black);
    QPixmap pixlogo;
    pixlogo.load("://res/logo.bmp");
    painter.setBrush(Brush);
    painter.drawRect(0,0,this->width(),this->height());
    painter.drawPixmap(230,75,600,200,pixlogo);
}

MainScene::~MainScene()
{
    delete ui;
}
