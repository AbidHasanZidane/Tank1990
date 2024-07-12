#include "achivement.h"
#include "qevent.h"
#include "ui_achivement.h"

achivement::achivement(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::achivement)
{
    ui->setupUi(this);
}

achivement::~achivement()
{
    delete ui;
}

void achivement::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Escape)
    {
        emit switch2w();
        this->close();
    }
}
