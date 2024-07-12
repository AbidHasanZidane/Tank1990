#include "gameover.h"
#include "ui_gameover.h"

GameOver::GameOver(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameOver)
{
    ui->setupUi(this);
    connect(ui->ReTty,&QPushButton::clicked,[=](){
        emit this->retry();
    });
}

GameOver::~GameOver()
{
    delete ui;
}
