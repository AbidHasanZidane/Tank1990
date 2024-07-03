#ifndef W1_H
#define W1_H

#include <QWidget>
#include "widget.h"
namespace Ui {
class w1;
}

class w1 : public QWidget
{
    Q_OBJECT

public:
    explicit w1(QWidget *parent = nullptr);
    ~w1();

private:
    Ui::w1 *ui;
};

#endif // W1_H
