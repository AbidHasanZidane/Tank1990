#include "mainwindow3.h"
#include "ui_mainwindow3.h"
mainwindow3::mainwindow3(QWidget *parent):
        QMainWindow(parent),
        ui(new Ui::MainWindow3)
    {
        ui->setupUi(this);
        connect(ui->BACK,&QPushButton::clicked,[=](){

        });
    }

    MainWindow3::~MainWindow3()
    {
        delete ui;
    }

}
