#ifndef SHOP_H
#define SHOP_H

#include <QWidget>
#include <QKeyEvent>
#include <QSoundEffect>
#include <QTimer>
#include "settings.h"  // 引入设置类头文件

namespace Ui {
class shop;
}

class shop : public QWidget
{
    Q_OBJECT

public:
    explicit shop(QWidget *parent = nullptr);  // 构造函数声明，parent默认为nullptr
    ~shop();  // 析构函数声明
    Ui::shop *ui;  // UI界面对象指针
    QSoundEffect *butEffect = new QSoundEffect;  // 按钮音效对象指针
    void refresh();  // 刷新界面函数声明

signals:
    void switch2w();  // 自定义信号：切换到游戏界面信号

private slots:
    void on_pushButton_clicked();  // 按钮点击槽函数声明
    void spawned(double vol);  // 按钮音量控制槽函数声明

    void on_pushButton_2_clicked();  // 按钮2点击槽函数声明

    void on_pushButton_3_clicked();  // 按钮3点击槽函数声明

    void on_pushButton_4_clicked();  // 按钮4点击槽函数声明

private:
    void keyPressEvent(QKeyEvent *event) override;  // 键盘按下事件重载
    bool eventFilter(QObject *obj, QEvent *event) override;  // 事件过滤器重载
};

#endif // SHOP_H

