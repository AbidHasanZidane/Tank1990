#include "gameover.h"
#include "ui_gameover.h"

GameOver::GameOver(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameOver)
{
    ui->setupUi(this); // 设置UI界面
    connect(ui->ReTty, &QPushButton::clicked, [=](){ // 连接点击按钮的信号和槽
        emit this->retry(); // 发送retry信号
    });
}

GameOver::~GameOver()
{
    delete ui; // 删除UI界面指针
}
