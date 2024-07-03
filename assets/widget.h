#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "w1.h"
#include "w2.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    static Widget *mywidget;
    Ui::Widget *ui;
    void button1();

private slots:
    void on_pushButton_clicked();

    void on_toolButton_clicked();

    void on_pushButton_2_clicked();

private:

};
#endif // WIDGET_H
