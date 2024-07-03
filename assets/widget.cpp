#include "widget.h"
#include "./ui_widget.h"
#include "ctrl.h"

Widget* Widget::mywidget = nullptr;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mywidget = this;
    mywidget->ui->pushButton->setStyleSheet("background-color:rgba(255,255,255,1)");
    mywidget->ui->pushButton_2->setStyleSheet("background-color:rgba(255,255,255,1)");
    mywidget->ui->toolButton->setStyleSheet("background-color:rgba(255,255,255,1)");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    this->close();
    w1 *pic=new w1();
    pic->show();
}


void Widget::on_toolButton_clicked()
{
    this->close();
    w2 *pic=new w2();
    pic->show();
}


void Widget::on_pushButton_2_clicked()
{
    this->close();
}

