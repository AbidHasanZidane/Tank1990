#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFile>
#include <QTextStream>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    readTankData();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::readTankData()
{
    QFile file("hp.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
       QString health = in.readLine().trimmed();
       if (!health.isEmpty()) {
           ui->listWidget->addItem(health);
       }

       file.close();
}
