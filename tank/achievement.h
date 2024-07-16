#ifndef ACHIEVEMENT_H
#define ACHIEVEMENT_H

#include <QWidget>
#include <QSoundEffect>
#include "settings.h"  // 包含自定义设置的头文件

namespace Ui {
class achievement;
}

class achievement : public QWidget
{
    Q_OBJECT

public:
    explicit achievement(QWidget *parent = nullptr);  // 构造函数
    ~achievement();  // 析构函数

    QSoundEffect *butEffect = new QSoundEffect;  // 声音效果对象

    Ui::achievement *ui;  // UI对象指针

signals:
    void switch2w();  // 切换到另一个窗口的信号

private slots:
    void on_pushButton_clicked();  // 按钮点击的槽函数

private:
    void keyPressEvent(QKeyEvent *event) override;  // 重写键盘按下事件处理函数
    bool eventFilter(QObject *obj, QEvent *event) override;  // 重写事件过滤器函数
};

#endif // ACHIEVEMENT_H
