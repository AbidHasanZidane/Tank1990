#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QMainWindow>

namespace Ui {
class GameOver; // 声明命名空间 Ui 中的 GameOver 类
}

class GameOver : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameOver(QWidget *parent = 0); // 构造函数声明，parent 参数默认为 0
    ~GameOver(); // 析构函数声明

private:
    Ui::GameOver *ui; // Ui 命名空间中的 GameOver 类的指针
};

#endif // GAMEOVER_H
