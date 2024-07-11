#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
class MainWindow2;
}

class MainWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow2(QWidget *parent = 0); // 显式构造函数声明
    ~MainWindow2(); // 析构函数声明

signals:
    void next(); // next信号声明
    void back(); // back信号声明

private:
    Ui::MainWindow2 *ui; // UI界面指针声明
};

#endif // MAINWINDOW2_H
