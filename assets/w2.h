#ifndef W2_H
#define W2_H

#include <QWidget>
#include "widget.h"
namespace Ui {
class w2;
}

class w2 : public QWidget
{
    Q_OBJECT

public:
    explicit w2(QWidget *parent = nullptr);
    ~w2();

private:
    Ui::w2 *ui;
};

#endif // W2_H
