#include "pause.h"
#include "qevent.h"
#include "ui_pause.h"

pause::pause(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::pause)  // 分配 UI 对象的内存空间
{
    ui->setupUi(this);  // 设置在 ui_pause.h 中定义的 UI 组件
    ui->label_4->setText(settings::readSettings("Grade:"));  // 根据设置显示等级信息
}

pause::~pause()
{
    delete ui;  // 释放为 UI 对象分配的内存空间
}

void pause::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape)
    {
        emit retw1();  // 按下 Esc 键时发送返回游戏界面的信号
    }
}

void pause::on_pushButton_clicked()
{
    emit retw1();  // 点击“继续游戏”按钮发送返回游戏界面的信号
}

void pause::on_pushButton_2_clicked()
{
    emit retmain();  // 点击“返回主菜单”按钮发送返回主菜单的信号
    this->close();   // 关闭暂停界面
}

void pause::on_pushButton_3_clicked()
{
    qApp->quit();  // 点击“退出游戏”按钮退出应用程序
}

void pause::on_pushButton_4_clicked()
{
    emit retsettings();  // 点击“设置”按钮发送返回设置界面的信号
    this->close();       // 关闭暂停界面
}
