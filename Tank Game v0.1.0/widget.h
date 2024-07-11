#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSoundEffect>
#include <QKeyEvent>
#include <QTimer>
#include "w1.h"
#include "w2.h"

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

    QSoundEffect *effect = new QSoundEffect;  // 背景音效对象
    QSoundEffect *butEffect = new QSoundEffect;  // 按钮音效对象
    Ui::Widget *ui;  // UI对象指针
    QTimer *timer0 = new QTimer(this);  // 定时器对象
    QTimer *timer1 = new QTimer(this);  // 定时器对象
    double curVol0 = 70;  // 当前音量值
    double curVol1 = 70;  // 当前音量值
    bool upedge = true;  // 边界标志
    double opacity = 0;  // 不透明度
    int state = 0;  // 状态标志

signals:
    void spawnw2(double vol0, double vol1);  // 信号，用于生成w2窗口

private slots:
    void on_toolButton_clicked();  // 工具按钮点击槽函数
    void on_pushButton_2_clicked();  // 按钮点击槽函数
    void changeVolume0(int val);  // 改变音量0槽函数
    void changeVolume1(int val);  // 改变音量1槽函数
    void switchOn();  // 切换显示窗口槽函数
    void changeOpacity();  // 改变透明度槽函数
    void changeTexts();  // 改变文本内容槽函数

private:
    void keyPressEvent(QKeyEvent *event) override;  // 键盘按下事件重载
    bool eventFilter(QObject *obj, QEvent *event) override;  // 事件过滤器重载
    double factorx = 1, factory = 1;  // 缩放因子
};

#endif // WIDGET_H
