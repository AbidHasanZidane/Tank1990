#include "w1.h"

w1::w1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::w1)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint);
    QPixmapCache::setCacheLimit(1);
    changePics();
    opacityUp();
    connect(timer, &QTimer::timeout,this,&w1::changePics);
    connect(timer0, &QTimer::timeout,this,[this]{w1::opacityDown(1000);});
    connect(timer1, &QTimer::timeout,this,&w1::opacityUp);
    timer->start(1000);
    pausew->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::ToolTip);
    pausew->setWindowModality(Qt::ApplicationModal);
}

w1::~w1()
{
    delete ui;
}

void w1::changePics()
{
    switch(count)
    {
        case 0:pixmap->load(":/pic/resources/plot_0.jpg");break;
        case 1:pixmap->load(":/pic/resources/plot_1.jpg");break;
        case 2:pixmap->load(":/pic/resources/plot_2.jpg");break;
        case 3:pixmap->load(":/pic/resources/plot_3.jpg");break;
        case 4:pixmap->load(":/pic/resources/plot_4.jpg");break;
        case 5:pixmap->load(":/pic/resources/plot_5.jpg");break;
        default:MainWindow *w=new MainWindow;w->show();timer->stop();this->close();
    }
    timer0->setSingleShot(1);
    timer0->start(4000);
    ui->label->setPixmap(*pixmap);
    count++;
}

void w1::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Escape)
    {
        if(runType)
        {
            timer0->stop();
            timer1->stop();
            remainingTime=timer->remainingTime();
            timer->stop();
            runType=false;
        }
        else
        {
            if(remainingTime<1000)
                w1::opacityDown(remainingTime);
            else QTimer::singleShot(remainingTime-1000,this,[this]{w1::opacityDown(1000);});
            QTimer::singleShot(remainingTime,this,[this]
            {
                timer->start();
                w1::changePics();
            });
            runType=true;
        }
    }
}

void w1::opacityUp()
{
    m_pGraphicsOpacityEffect = new QGraphicsOpacityEffect(ui->label);
    m_pGraphicsOpacityEffect->setOpacity(1);
    ui->label->setGraphicsEffect(m_pGraphicsOpacityEffect);
    animation = new QPropertyAnimation(m_pGraphicsOpacityEffect,"opacity",this);
    animation->setDuration(1000);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void w1::opacityDown(int time)
{
    m_pGraphicsOpacityEffect = new QGraphicsOpacityEffect(ui->label);
    m_pGraphicsOpacityEffect->setOpacity(1);
    ui->label->setGraphicsEffect(m_pGraphicsOpacityEffect);
    animation = new QPropertyAnimation(m_pGraphicsOpacityEffect,"opacity",this);
    animation->setDuration(time);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
    timer1->setSingleShot(1);
    timer1->start(1000);
}
