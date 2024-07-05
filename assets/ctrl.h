#include <QWidget>
#include "widget.h"
#include "ui_widget.h"
#include "w2.h"
#include "ui_w2.h"
class ctrl : public QWidget
{
    Q_OBJECT
public:
    explicit ctrl(QWidget *parent = nullptr);
    Ui::Widget *ui = Widget::mywidget->ui;
    Ui::w2 *ui2 = w2::myw2->ui;
};
