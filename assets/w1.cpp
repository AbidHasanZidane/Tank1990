#include "w1.h"
#include "ui_w1.h"
#include <QPixmapCache>

w1::w1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::w1)
{
    ui->setupUi(this);
    QPixmapCache::setCacheLimit(1);
    ui->label->setPixmap(*pixmap);
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout,this,&w1::changePics);
    timer->start(1000);
}

w1::~w1()
{
    delete ui;
}

void w1::changePics()
{
    switch(count)
    {
        case 1:pixmap->load(":/pic/resources/plot_1.jpg");break;
        case 2:pixmap->load(":/pic/resources/plot_2.jpg");break;
        case 3:pixmap->load(":/pic/resources/plot_3.jpg");break;
        case 4:pixmap->load(":/pic/resources/plot_4.jpg");break;
        case 5:pixmap->load(":/pic/resources/plot_5.jpg");break;
    }
    ui->label->setPixmap(*pixmap);
    count++;
}
