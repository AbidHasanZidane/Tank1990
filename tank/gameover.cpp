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
            emit switch2main();
            this->close();
    });
}

GameOver::~GameOver()
{
    delete ui;
}
