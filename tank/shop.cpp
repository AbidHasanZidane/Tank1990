#include "shop.h"
#include "ui_shop.h"

shop::shop(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::shop)
{
    ui->setupUi(this);
    ui->label_10->setVisible(0);
    ui->label_11->setVisible(0);
    ui->label_12->setVisible(0);
    refresh();
    ui->pushButton->setAttribute(Qt::WA_Hover,true);
    ui->pushButton->installEventFilter(this);
    ui->pushButton_2->setAttribute(Qt::WA_Hover,true);
    ui->pushButton_2->installEventFilter(this);
    ui->pushButton_3->setAttribute(Qt::WA_Hover,true);
    ui->pushButton_3->installEventFilter(this);
    ui->pushButton_4->setAttribute(Qt::WA_Hover,true);
    ui->pushButton_4->installEventFilter(this);
    butEffect->setSource(QUrl::fromLocalFile(":/music/resources/bell.wav"));
}

shop::~shop()
{
    delete ui;
}

void shop::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Escape)
    {
        emit switch2w();
        this->close();
    }
}

void shop::on_pushButton_clicked()
{
    emit switch2w();
    this->close();
}

bool shop::eventFilter(QObject *obj, QEvent *event)
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
    else if(obj==ui->pushButton_2)
    {
        if(event->type() == QEvent::HoverEnter)
        {
            ui->label_4->setGeometry(530,-10,220,220);
            return true;
        }
        if(event->type()==QEvent::HoverLeave)
        {
            ui->label_4->setGeometry(560,20,160,160);
            return true;
        }
    }
    else if(obj==ui->pushButton_3)
    {
        if(event->type() == QEvent::HoverEnter)
        {
            ui->label_5->setGeometry(530,190,220,220);
            return true;
        }
        if(event->type()==QEvent::HoverLeave)
        {
            ui->label_5->setGeometry(560,220,160,160);
            return true;
        }
    }
    else if(obj==ui->pushButton_4)
    {
        if(event->type() == QEvent::HoverEnter)
        {
            ui->label_6->setGeometry(530,390,220,220);
            return true;
        }
        if(event->type()==QEvent::HoverLeave)
        {
            ui->label_6->setGeometry(560,420,160,160);
            return true;
        }
    }
}

void shop::spawned(double vol)
{
    butEffect->setVolume(vol/100);
}

void shop::on_pushButton_2_clicked()
{
    butEffect->play();
    if(settings::readSettings("Hp:").toInt()<8)
        if(settings::readSettings("Grade:").toInt()>=2000)
        {
            settings::modifySettings("Grade:",QString::number(settings::readSettings("Grade:").toInt()-2000));
            settings::modifySettings("Hp:",QString::number(settings::readSettings("Hp:").toInt()+1));
        }
        else
        {
            ui->label_14->setStyleSheet("color:rgba(255,0,0,1)");
            QTimer::singleShot(1000,this,[this]{ui->label_14->setStyleSheet("color:rgba(0,255,0,1)");});
        }
    else
    {
        ui->label_10->setStyleSheet("color:rgba(255,0,0,1)");
        QTimer::singleShot(1000,this,[this]{ui->label_10->setStyleSheet("color:rgba(0,255,0,1)");});
    }
    refresh();
}

void shop::on_pushButton_3_clicked()
{
    butEffect->play();
    if(settings::readSettings("Speed:").toInt()<20)
        if(settings::readSettings("Grade:").toInt()>=2000)
        {
            settings::modifySettings("Grade:",QString::number(settings::readSettings("Grade:").toInt()-2000));
            settings::modifySettings("Speed:",QString::number(settings::readSettings("Speed:").toInt()+2));
        }
        else
        {
            ui->label_14->setStyleSheet("color:rgba(255,0,0,1)");
            QTimer::singleShot(1000,this,[this]{ui->label_14->setStyleSheet("color:rgba(0,255,0,1)");});
        }
    else
    {
        ui->label_11->setStyleSheet("color:rgba(255,0,0,1)");
        QTimer::singleShot(1000,this,[this]{ui->label_11->setStyleSheet("color:rgba(0,255,0,1)");});
    }
    refresh();
}


void shop::on_pushButton_4_clicked()
{
    butEffect->play();
    if(settings::readSettings("Fire:").toInt()>300)
        if(settings::readSettings("Grade:").toInt()>=2000)
        {
            settings::modifySettings("Grade:",QString::number(settings::readSettings("Grade:").toInt()-2000));
            settings::modifySettings("Fire:",QString::number(settings::readSettings("Fire:").toInt()-40));
        }
        else
        {
            ui->label_14->setStyleSheet("color:rgba(255,0,0,1)");
            QTimer::singleShot(1000,this,[this]{ui->label_14->setStyleSheet("color:rgba(0,255,0,1)");});
        }
    else
    {
        ui->label_12->setStyleSheet("color:rgba(255,0,0,1)");
        QTimer::singleShot(1000,this,[this]{ui->label_12->setStyleSheet("color:rgba(0,255,0,1)");});
    }
    refresh();
}

void shop::refresh()
{
    switch(settings::readSettings("Hp:").toInt())
    {
        case 3:ui->label_7->setText("0/5");break;
        case 4:ui->label_7->setText("1/5");break;
        case 5:ui->label_7->setText("2/5");break;
        case 6:ui->label_7->setText("3/5");break;
        case 7:ui->label_7->setText("4/5");break;
        case 8:ui->label_7->setText("5/5");ui->label_10->setVisible(1);break;
    }
    switch(settings::readSettings("Speed:").toInt())
    {
        case 10:ui->label_8->setText("0/5");break;
        case 12:ui->label_8->setText("1/5");break;
        case 14:ui->label_8->setText("2/5");break;
        case 16:ui->label_8->setText("3/5");break;
        case 18:ui->label_8->setText("4/5");break;
        case 20:ui->label_8->setText("5/5");ui->label_11->setVisible(1);break;
    }
    switch(settings::readSettings("Fire:").toInt())
    {
        case 500:ui->label_9->setText("0/5");break;
        case 460:ui->label_9->setText("1/5");break;
        case 420:ui->label_9->setText("2/5");break;
        case 380:ui->label_9->setText("3/5");break;
        case 340:ui->label_9->setText("4/5");break;
        case 300:ui->label_9->setText("5/5");ui->label_12->setVisible(1);break;
    }
    ui->label_14->setText(settings::readSettings("Grade:"));
}
