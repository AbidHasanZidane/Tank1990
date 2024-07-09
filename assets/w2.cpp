#include "w2.h"
#include "ui_w2.h"
#include "widget.h"
w2::w2(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::w2)
{
    ui->setupUi(this);
    butEffect->setSource(QUrl::fromLocalFile(":/music/resources/bell.wav"));
    ui->pushButton->setAttribute(Qt::WA_Hover,true);
    ui->pushButton->installEventFilter(this);
    QStringList list;
    list<<"全屏"<<"2560 x 1440"<<"1920 x 1080"<<"1600 x 900"<<"1280 x 720"<<"1024 x 576";
    ui->comboBox->addItems(list);
    ui->comboBox->setCurrentIndex(4);
    connect(ui->comboBox, SIGNAL(activated(int)), this, SLOT(checkIndexChangedSignal(int)));
}

w2::~w2()
{
    delete ui;
}

void w2::on_pushButton_clicked()
{
    emit switch2w();
    this->close();
}

void w2::on_horizontalSlider_valueChanged(int value)
{
    if(value==0)
    {
        ui->label->setPixmap(QPixmap::fromImage(*image1));
    }
    else
    {
        ui->label->setPixmap(QPixmap::fromImage(*image0));
    }
    emit sendVolume0(value);
}

void w2::on_horizontalSlider_2_valueChanged(int value)
{
    if(value==0)
    {
        ui->label_4->setPixmap(QPixmap::fromImage(*image1));
    }
    else
    {
        ui->label_4->setPixmap(QPixmap::fromImage(*image0));
    }
    double dvalue=value;
    butEffect->setVolume(dvalue/100);
    emit sendVolume1(value);
}

bool w2::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == ui->pushButton)
    {
        if(event->type() == QEvent::HoverEnter)
        {
            ui->pushButton->setStyleSheet("background-color:rgba(255,255,255,0.7)");
            butEffect->play();
            return true;
        }
        if(event->type()==QEvent::HoverLeave)
        {
            ui->pushButton->setStyleSheet("background-color:rgba(255,255,255,1)");
            return true;
        }
    }
}

void w2::spawned(double vol0,double vol1)
{
    if(vol0==0)
    {
        ui->label->setPixmap(QPixmap::fromImage(*image1));
    }
    else
    {
        ui->label->setPixmap(QPixmap::fromImage(*image0));
    }
    if(vol1==0)
    {
        ui->label_4->setPixmap(QPixmap::fromImage(*image1));
    }
    else
    {
        ui->label_4->setPixmap(QPixmap::fromImage(*image0));
    }
    ui->horizontalSlider->setValue(vol0);
    ui->horizontalSlider_2->setValue(vol1);
    double dvol=vol1;
    butEffect->setVolume(dvol/100);
}

void w2::checkIndexChangedSignal(int index)
{
    switch(index)
    {
    case 0:
    {
        QScreen *screen = QGuiApplication::primaryScreen();
        qApp->exit(screen->size().height());
    }
    case 1:qApp->exit(2560);break;
    case 2:qApp->exit(1920);break;
    case 3:qApp->exit(1600);break;
    case 4:qApp->exit(1280);break;
    case 5:qApp->exit(1024);break;
    }
}

void w2::on_pushButton_2_clicked()
{
    ui->horizontalSlider->setValue(70);
    ui->horizontalSlider_2->setValue(70);
}

