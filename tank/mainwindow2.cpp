#include "mainwindow2.h"
#include "ui_mainwindow2.h"

MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this); // 设置UI界面

    // 连接NEXT按钮的点击信号与next信号
    connect(ui->NEXT, &QPushButton::clicked, [=]() {
        emit this->next(); // 发送next信号
    });

    // 连接BACK按钮的点击信号与空槽
    connect(ui->BACK, &QPushButton::clicked, [=]() {
        // 这里可以添加后退功能的实现
    });
}

MainWindow2::~MainWindow2()
{
    delete ui; // 删除UI界面指针
}
