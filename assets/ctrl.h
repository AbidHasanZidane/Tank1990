#include <QWidget>
#include "widget.h"
#include "ui_widget.h"

class ctrl : public QWidget
{
    Q_OBJECT
public:
    explicit ctrl(QWidget *parent = nullptr);
    Ui::Widget *ui = Widget::mywidget->ui;
    void act0();
};
