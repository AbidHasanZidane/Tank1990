#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pushButton_2->setStyleSheet("background-color:rgba(255,255,255,1)");
    ui->toolButton->setStyleSheet("background-color:rgba(255,255,255,1)");
    effect->setSource(QUrl::fromLocalFile(":/music/resources/background.wav"));
    effect->setLoopCount(QSoundEffect::Infinite);
    effect->setVolume(0.7);
    effect->play();
    butEffect->setSource(QUrl::fromLocalFile(":/music/resources/bell.wav"));
    butEffect->setVolume(0.7);
    ui->pushButton_2->setAttribute(Qt::WA_Hover,true);
    ui->pushButton_2->installEventFilter(this);
    ui->toolButton->setAttribute(Qt::WA_Hover,true);
    ui->toolButton->installEventFilter(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_toolButton_clicked()
{
    w2 *w=new w2();
    w->show();
    this->hide();
    connect(w,SIGNAL(sendVolume0(int)),this,SLOT(changeVolume0(int)));
    connect(w,SIGNAL(sendVolume1(int)),this,SLOT(changeVolume1(int)));
    connect(w,SIGNAL(switch2w()),this,SLOT(switchOn()));
    connect(this,SIGNAL(spawnw2(double,double)),w,SLOT(spawned(double,double)));
    emit spawnw2(curVol0,curVol1);
}

void Widget::on_pushButton_2_clicked()
{
    this->close();
}

void Widget::changeVolume0(int val)
{
    curVol0=val;
    effect->setVolume(curVol0/100);
}

void Widget::changeVolume1(int val)
{
    curVol1=val;
    butEffect->setVolume(curVol1/100);
}

void Widget::switchOn()
{
    this->show();
}

bool Widget::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == ui->pushButton_2)
    {
        if(event->type() == QEvent::HoverEnter)
        {
            ui->pushButton_2->setStyleSheet("background-color:rgba(255,255,255,0.7)");
            butEffect->play();
            return true;
        }
        if(event->type()==QEvent::HoverLeave)
        {
            ui->pushButton_2->setStyleSheet("background-color:rgba(255,255,255,1)");
            return true;
        }
    }
    else if(obj == ui->toolButton)
    {
        if(event->type() == QEvent::HoverEnter)
        {
            butEffect->play();
            return true;
        }
    }
    return QWidget::eventFilter(obj,event);
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Escape)
        this->close();
    else
    {
        this->hide();
        w1 *w=new w1();
        w->show();
    }
}
