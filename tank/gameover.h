#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QMainWindow>

// 前置声明 Ui 命名空间
namespace Ui {
    class GameOver;
}

// GameOver 类继承自 QMainWindow
class GameOver : public QMainWindow
{
    Q_OBJECT

public:
    // 构造函数
    explicit GameOver(QWidget *parent = 0);

    // 析构函数
    ~GameOver();

signals:
    // 信号：在重试和返回主菜单动作发生时发出
    void retry();        // 点击“重试”按钮时发出的信号
    void switch2main();  // 点击“返回主菜单”按钮时发出的信号

private:
    Ui::GameOver *ui;   // 指向 UI 对象的指针
};

#endif // GAMEOVER_H
