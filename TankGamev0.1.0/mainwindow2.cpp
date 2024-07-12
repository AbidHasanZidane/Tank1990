#include "mainwindow2.h"
#include "ui_mainwindow2.h"

MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
    connect(ui->NEXT,&QPushButton::clicked,[=](){
        emit this->next();
    });
    connect(ui->BACK,&QPushButton::clicked,[=](){

    });
}

MainWindow2::~MainWindow2()
{
    delete ui;
}
