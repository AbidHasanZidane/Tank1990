#include "gameover.h"
#include "ui_gameover.h"

GameOver::GameOver(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameOver)
{
    ui->setupUi(this);
    connect(ui->ReTty,&QPushButton::clicked,[=](){
        emit this->retry();});
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        qApp->exit(1280);
    });
}

GameOver::~GameOver()
{
    delete ui;
}
