#include "mainwindow3.h"
#include "ui_mainwindow3.h"

MainWindow3::MainWindow3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow3)
{
    ui->setupUi(this);  // 设置UI界面

    // 连接BACK按钮的点击信号，但未指定任何操作

    connect(ui->BACK, &QPushButton::clicked, [=]() {
        // 点击BACK按钮时触发的操作可以在这里添加
    });
}

MainWindow3::~MainWindow3()
{
    delete ui;  // 析构函数，释放UI对象的内存
}
