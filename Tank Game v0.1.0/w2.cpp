#include "w2.h"
#include "ui_w2.h"
#include "widget.h"

w2::w2(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::w2)
{
    ui->setupUi(this);  // 使用生成的函数设置UI

    butEffect->setSource(QUrl::fromLocalFile(":/music/resources/bell.wav"));  // 设置声音效果源
    ui->pushButton->setAttribute(Qt::WA_Hover, true);  // 启用按钮的悬停事件
    ui->pushButton->installEventFilter(this);  // 安装按钮的事件过滤器
}

w2::~w2()
{
    delete ui;  // 释放UI资源
}

void w2::on_pushButton_clicked()
{
    emit switch2w();  // 发送切换窗口信号
    this->close();  // 关闭当前窗口
}

void w2::on_horizontalSlider_valueChanged(int value)
{
    if (value == 0)
    {
        ui->label->setPixmap(QPixmap::fromImage(*image1));  // 根据滑动条值设置图片
    }
    else
    {
        ui->label->setPixmap(QPixmap::fromImage(*image0));
    }
    emit sendVolume0(value);  // 发送音量信号
}

void w2::on_horizontalSlider_2_valueChanged(int value)
{
    if (value == 0)
    {
        ui->label_4->setPixmap(QPixmap::fromImage(*image1));  // 根据滑动条值设置图片
    }
    else
    {
        ui->label_4->setPixmap(QPixmap::fromImage(*image0));
    }
    double dvalue = value;
    butEffect->setVolume(dvalue / 100);  // 设置声音效果的音量
    emit sendVolume1(value);  // 发送音量信号
}

bool w2::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->pushButton)
    {
        if (event->type() == QEvent::HoverEnter)
        {
            ui->pushButton->setStyleSheet("background-color:rgba(255,255,255,0.7)");  // 鼠标悬停时改变按钮样式
            butEffect->play();  // 播放声音效果
            return true;
        }
        if (event->type() == QEvent::HoverLeave)
        {
            ui->pushButton->setStyleSheet("background-color:rgba(255,255,255,1)");  // 鼠标离开时恢复按钮样式
            return true;
        }
    }
    return false;
}

void w2::spawned(double vol0, double vol1)
{
    if (vol0 == 0)
    {
        ui->label->setPixmap(QPixmap::fromImage(*image1));  // 根据音量设置图片
    }
    else
    {
        ui->label->setPixmap(QPixmap::fromImage(*image0));
    }
    if (vol1 == 0)
    {
        ui->label_4->setPixmap(QPixmap::fromImage(*image1));  // 根据音量设置图片
    }
    else
    {
        ui->label_4->setPixmap(QPixmap::fromImage(*image0));
    }
    ui->horizontalSlider->setValue(vol0);  // 设置滑动条值
    ui->horizontalSlider_2->setValue(vol1);
    double dvol = vol1;
    butEffect->setVolume(dvol / 100);  // 设置声音效果的音量
}

void w2::on_pushButton_2_clicked()
{
    qApp->exit(13);  // 退出应用程序，并指定退出代码
}
