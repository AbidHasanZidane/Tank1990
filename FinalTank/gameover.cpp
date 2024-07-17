#include "gameover.h"
#include "ui_gameover.h"

GameOver::GameOver(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameOver)
{
    ui->setupUi(this);  // 使用UI文件中的布局和控件初始化界面

    // 连接“重试”按钮的点击事件，点击时发送 retry 信号
    connect(ui->ReTty, &QPushButton::clicked, [=]() {
        emit this->retry();
    });

    // 连接“退出”按钮的点击事件，点击时退出应用程序并返回退出码 1280
    connect(ui->pushButton, &QPushButton::clicked, [=]() {
        qApp->exit(1280);
    });
}

GameOver::~GameOver()
{
    delete ui;  // 析构函数，释放界面对象内存
}
