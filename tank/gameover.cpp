#include "gameover.h"
#include "ui_gameover.h"

GameOver::GameOver(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameOver) // 在堆上创建一个新的 Ui::GameOver 对象
{
    ui->setupUi(this); // 调用 Ui::GameOver 类的 setupUi 方法来设置当前窗口
}

GameOver::~GameOver() // 析构函数的定义
{
    delete ui; // 删除在堆上创建的 Ui::GameOver 对象，释放内存
}
