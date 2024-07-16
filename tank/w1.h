#ifndef W1_H
#define W1_H

#include <QWidget>
#include <QTimer>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QKeyEvent>
#include <QPixmapCache>
#include <QGraphicsOpacityEffect>
#include "pause.h"
#include "ui_w1.h"
#include "mainwindow.h"

// w1 类声明头文件

namespace Ui {
class w1;
}

class w1 : public QWidget
{
    Q_OBJECT

public:
    explicit w1(QWidget *parent = nullptr);  // 构造函数声明
    ~w1();  // 析构函数声明

    QPixmap *pixmap = new QPixmap;  // 图片对象指针
    int count = 0;  // 计数器变量
    int remainingTime;  // 剩余时间变量
    bool runType = true;  // 运行类型标志
    QTimer *timer = new QTimer;  // 定时器对象
    QTimer *timer0 = new QTimer;  // 另一个定时器对象
    QTimer *timer1 = new QTimer;  // 另一个定时器对象
    QTimer *timer2 = new QTimer;  // 另一个定时器对象
    QTimer *timer3 = new QTimer;  // 另一个定时器对象
    pause *pausew = new pause;  // 暂停窗口对象指针

    // 函数声明
    void changePics();  // 切换图片函数
    void opacityUp();  // 透明度增加函数
    void opacityDown(int time);  // 透明度减少函数，带时间参数
    QGraphicsOpacityEffect *m_pGraphicsOpacityEffect;  // 图形透明度效果指针
    QPropertyAnimation *animation;  // 属性动画指针

signals:
    void changeMusic(int cnt);  // 改变音乐信号
    void retmain();  // 返回主界面信号
    void retsettings();  // 返回设置界面信号
    void boomEffect();  // 爆炸效果信号
    void switch2game();  // 切换到游戏信号

private slots:
    // 槽函数声明
    void passSignal(int cnt);  // 传递信号函数，带计数器参数
    void fromPause2w1();  // 从暂停界面返回当前界面函数
    void fromPause2main();  // 从暂停界面返回主界面函数
    void fromPause2settings();  // 从暂停界面返回设置界面函数
    void passBoom();  // 传递爆炸信号函数
    void pass2main();  // 传递返回主界面信号函数
    void switchOn();  // 开关函数

private:
    void keyPressEvent(QKeyEvent *event) override;  // 键盘按下事件处理函数声明
    Ui::w1 *ui;  // Ui界面指针
};

#endif // W1_H
