#include "pause.h"
#include "qevent.h"
#include "ui_pause.h"

pause::pause(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::pause)
{
    ui->setupUi(this);
    ui->label_4->setText(settings::readSettings("Grade:"));
}

pause::~pause()
{
    delete ui;
}

void pause::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Escape)
    {
        emit retw1();
    }
}

void pause::on_pushButton_clicked()
{
    emit retw1();
}

void pause::on_pushButton_2_clicked()
{
    emit retmain();
    this->close();
}

void pause::on_pushButton_3_clicked()
{
    qApp->quit();
}


void pause::on_pushButton_4_clicked()
{
    emit retsettings();
    this->close();
}

