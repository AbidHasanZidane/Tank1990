#ifndef MAINWINDOW3_H
#define MAINWINDOW3_H

#include <QMainWindow>
#include <QPushButton>  // 包含QPushButton类的头文件

namespace Ui {
class MainWindow3;
}

class MainWindow3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow3(QWidget *parent = 0);  // 显式声明构造函数
    ~MainWindow3();  // 析构函数

signals:
    void back();  // 自定义信号：返回操作

private:
    Ui::MainWindow3 *ui;  // 指向UI对象的指针
};

#endif // MAINWINDOW3_H
