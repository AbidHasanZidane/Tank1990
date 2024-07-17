#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <QMainWindow>
#include<QPushButton>

namespace Ui {
class MainWindow2;
}

class MainWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow2(QWidget *parent = 0);
    ~MainWindow2();
signals:
    void next();
    void switch2main();

private:
    Ui::MainWindow2 *ui;
};

#endif // MAINWINDOW2_H
