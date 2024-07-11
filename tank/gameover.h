#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QMainWindow>

namespace Ui {
class GameOver;
}

class GameOver : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameOver(QWidget *parent = 0); // 显示构造函数声明
    ~GameOver(); // 显示析构函数声明

signals:
    void retry(); // retry信号声明

private:
    Ui::GameOver *ui; // UI界面指针声明
};

#endif // GAMEOVER_H

