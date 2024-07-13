#include "pause.h"
#include "qevent.h"
#include "ui_pause.h"

pause::pause(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::pause)
{
    ui->setupUi(this);
}

pause::~pause()
{
    delete ui;
}

void pause::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Escape)
    {
        qDebug()<<"1";
        runType=true;
    }
}
