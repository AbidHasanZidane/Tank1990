#include "mainwindow2.h"
#include "ui_mainwindow2.h"

MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);  // 设置UI界面

    // 连接NEXT按钮的点击信号到next()信号的发射
    connect(ui->NEXT, &QPushButton::clicked, [=]() {
        emit this->next();
    });

    // 连接BACK按钮的点击信号到switch2main()信号的发射，并关闭当前窗口
    connect(ui->BACK, &QPushButton::clicked, [=]() {
        emit switch2main();
        this->close();
    });
}

MainWindow2::~MainWindow2()
{
    delete ui;  // 析构函数，释放UI对象的内存
}
