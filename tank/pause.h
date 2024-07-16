#ifndef PAUSE_H
#define PAUSE_H

#include <QWidget>
#include "settings.h"  // 包含设置相关的头文件

namespace Ui {
class pause;
}

class pause : public QWidget
{
    Q_OBJECT

public:
    explicit pause(QWidget *parent = nullptr);  // 构造函数声明
    ~pause();  // 析构函数声明

signals:
    void retw1();         // 返回到游戏界面的信号
    void retmain();       // 返回到主菜单的信号
    void retsettings();   // 返回到设置界面的信号

private:
    void keyPressEvent(QKeyEvent *event) override;  // 键盘事件处理函数声明
    Ui::pause *ui;  // 指向 UI 对象的指针

protected:
private slots:
    void on_pushButton_clicked();    // "继续游戏"按钮点击时的槽函数声明
    void on_pushButton_2_clicked();  // "返回主菜单"按钮点击时的槽函数声明
    void on_pushButton_3_clicked();  // "退出游戏"按钮点击时的槽函数声明
    void on_pushButton_4_clicked();  // "设置"按钮点击时的槽函数声明
};

#endif // PAUSE_H
