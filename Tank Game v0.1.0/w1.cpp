#include "w1.h"
#include "ui_w1.h"

w1::w1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::w1)
{
    ui->setupUi(this);
}

w1::~w1()
{
    delete ui;
}
