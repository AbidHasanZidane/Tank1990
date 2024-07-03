#include "w2.h"
#include "ui_w2.h"

w2::w2(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::w2)
{
    ui->setupUi(this);
}

w2::~w2()
{
    delete ui;
}
