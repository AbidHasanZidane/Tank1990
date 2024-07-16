#include "gameover.h"
#include "ui_gameover.h"

// 构造函数实现
GameOver::GameOver(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameOver)  // 分配 UI 对象的内存空间
{
    ui->setupUi(this);  // 设置在 ui_gameover.h 中定义的 UI 组件

    // 将“重试”按钮的点击连接到发出 retry 信号的 Lambda 函数
    connect(ui->ReTty, &QPushButton::clicked, [=](){
        emit this->retry();
    });

    // 将“返回主菜单”按钮的点击连接到发出 switch2main 信号的 Lambda 函数
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        emit switch2main();  // 发出返回主菜单的信号
        this->close();       // 关闭游戏结束窗口
    });
}

// 析构函数实现
GameOver::~GameOver()
{
    delete ui;  // 释放为 UI 对象分配的内存空间
}
