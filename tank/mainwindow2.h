#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <QMainWindow>
#include <QPushButton>  // 包含QPushButton类的头文件

namespace Ui {
class MainWindow2;
}

class MainWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow2(QWidget *parent = 0);  // 显式声明构造函数
    ~MainWindow2();  // 析构函数

signals:
    void next();  // 自定义信号：下一步操作
    void switch2main();  // 自定义信号：切换回主界面

private:
    Ui::MainWindow2 *ui;  // 指向UI对象的指针
};

#endif // MAINWINDOW2_H
