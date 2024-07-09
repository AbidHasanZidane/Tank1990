#ifndef W1_H
#define W1_H

#include <QWidget>
#include <QTimer>
namespace Ui {
class w1;
}

class w1 : public QWidget
{
    Q_OBJECT

public:
    explicit w1(QWidget *parent = nullptr);
    ~w1();
    QPixmap *pixmap=new QPixmap(":/pic/resources/plot_0.jpg");
    void changePics();
    int count=1;

private:
    Ui::w1 *ui;
};

#endif // W1_H
