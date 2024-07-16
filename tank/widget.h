#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSoundEffect>
#include <QKeyEvent>
#include <QTimer>
#include "w1.h"
#include "w2.h"
#include "achievement.h"
#include "shop.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);  // 构造函数
    ~Widget();  // 析构函数

    // 声音效果对象
    QSoundEffect *effect = new QSoundEffect;
    QSoundEffect *effect1 = new QSoundEffect;
    QSoundEffect *effect2 = new QSoundEffect;
    QSoundEffect *effect3 = new QSoundEffect;
    QSoundEffect *butEffect = new QSoundEffect;
    QSoundEffect *boomEffect = new QSoundEffect;

    Ui::Widget *ui;  // UI对象指针
    QTimer *timer0 = new QTimer(this);  // 定时器对象
    QTimer *timer1 = new QTimer(this);  // 定时器对象

    double curVol0 = 70;  // 当前音量0
    double curVol1 = 70;  // 当前音量1
    bool upedge = true;   // 边界标志
    double opacity = 0;   // 透明度
    int state = 0;        // 状态
    std::string scale;    // 缩放

signals:
    void spawnw2(double vol0, double vol1);  // 发送生成w2界面的信号
    void spawnshop(double vol);  // 发送生成商店界面的信号

private slots:
    // 槽函数，按钮点击事件
    void on_toolButton_clicked();
    void on_pushButton_2_clicked();

    // 槽函数，改变音量0和音量1的处理
    void changeVolume0(int val);
    void changeVolume1(int val);

    // 槽函数，切换界面的处理
    void switchOn();

    // 槽函数，改变透明度和文字的处理
    void changeOpacity();
    void changeTexts();

    // 槽函数，按钮点击事件
    void on_toolButton_2_clicked();

    // 槽函数，改变音乐的处理
    void changeMusic(int cnt);

    // 槽函数，播放爆炸音效的处理
    void on_toolButton_3_clicked();
    void playBoom();

private:
    void keyPressEvent(QKeyEvent *event) override;  // 处理按键事件的函数
    bool eventFilter(QObject *obj, QEvent *event) override;  // 事件过滤器
    double factorx = 1, factory = 1;  // 缩放因子
};

#endif // WIDGET_H
