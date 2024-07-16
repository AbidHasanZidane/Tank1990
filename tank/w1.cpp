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
    connect(timer2, &QTimer::timeout,this,[this]{timer->start(5000);w1::changePics();});
    connect(timer3, &QTimer::timeout,this,[this]{w1::opacityDown(1000);});
    timer->start(5000);
    pausew->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::ToolTip);
    connect(pausew,&pause::retw1,this,&w1::fromPause2w1);
    connect(pausew,&pause::retmain,this,&w1::fromPause2main);
    connect(pausew,&pause::retsettings,this,&w1::fromPause2settings);
}

w1::~w1()
{
    delete ui;
}

void w1::changePics()
{
    switch(count)
    {
        case 0:pixmap->load(":/pic/resources/Scene1/0.0intro1.png");break;
        case 1:pixmap->load(":/pic/resources/Scene1/0.1intro2.jpg");break;
        case 2:pixmap->load(":/pic/resources/Scene1/scene1.0.jpg");break;
        case 3:pixmap->load(":/pic/resources/Scene1/scene1.2.jpg");break;
        case 4:pixmap->load(":/pic/resources/Scene1/scene1.3.jpg");break;
        case 5:pixmap->load(":/pic/resources/Scene1/scene1.4.jpg");break;
        case 6:pixmap->load(":/pic/resources/Scene1/scene1.5.jpg");break;
        case 7:pixmap->load(":/pic/resources/Scene1/scene1.6.jpg");break;
        case 8:pixmap->load(":/pic/resources/Scene1/scene1.7.jpg");break;
        case 9:pixmap->load(":/pic/resources/Scene1/scene1.8.jpg");break;
        case 10:
        {
            MainWindow *w=new MainWindow;
            connect(w,SIGNAL(changeMusic(int)),this,SLOT(passSignal(int)));
            connect(w,SIGNAL(boomEffect()),this,SLOT(passBoom()));
            connect(w,SIGNAL(switch2main()),this,SLOT(pass2main()));
            connect(w,SIGNAL(switch2w1()),this,SLOT(switchOn()));
            connect(this,SIGNAL(switch2game()),w,SLOT(switchOn()));
            w->show();
            timer->stop();
            this->hide();
            break;
        }
        case 11:pixmap->load(":/pic/resources/Scene2/2.1.jpg");break;
        case 12:pixmap->load(":/pic/resources/Scene2/2.2.jpg");break;
        case 13:pixmap->load(":/pic/resources/Scene2/2.3.jpg");break;
        case 14:
        {
            emit switch2game();
            timer->stop();
            this->hide();
            break;
        }
        case 15:pixmap->load(":/pic/resources/Scene3/3.0.jpg");break;
        case 16:pixmap->load(":/pic/resources/Scene3/3.1.jpg");break;
        case 17:pixmap->load(":/pic/resources/Scene3/3.2.jpg");break;
        case 18:
        {
            emit switch2game();
            timer->stop();
            this->hide();
            break;
        }
        case 19:pixmap->load(":/pic/resources/Scene4/4.1.jpg");break;
        case 20:pixmap->load(":/pic/resources/Scene4/4.2.jpg");break;
        case 21:pixmap->load(":/pic/resources/Scene4/4.3.jpg");break;
        case 22:pixmap->load(":/pic/resources/Scene4/4.4.jpg");break;
        case 23:pixmap->load(":/pic/resources/Scene4/4.5.jpg");break;
        case 24:
        {
            emit switch2game();
            timer->stop();
            this->hide();
            break;
        }
        case 25:pixmap->load(":/pic/resources/Scene5/5.1.jpg");break;
        case 26:pixmap->load(":/pic/resources/Scene5/5.2.jpg");break;
        case 27:
        {
            emit switch2game();
            timer->stop();
            this->hide();
            break;
        }
        case 28:pixmap->load(":/pic/resources/Scene6/6.1.jpg");break;
        case 29:pixmap->load(":/pic/resources/Scene6/6.2.jpg");break;
        case 30:pixmap->load(":/pic/resources/Scene6/6.3.jpg");break;
        case 31:
        {
            pixmap->load(":/pic/resources/Scene6/6.4.png");break;
            timer->stop();
            QTimer::singleShot(5000,this,[this]{emit retmain();this->close();});
        }
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
            timer3->stop();
            remainingTime=timer->remainingTime();
            if(remainingTime==-1)
            {
                remainingTime=timer2->remainingTime();
                timer2->stop();
            }
            timer->stop();
            runType=false;
            pausew->show();
            pausew->activateWindow();
        }
        else
        {
            if(remainingTime<1000)
                w1::opacityDown(remainingTime);
            else
            {
                timer3->start(remainingTime-1000);
                timer3->setSingleShot(1);
            }
            timer2->start(remainingTime);
            timer2->setSingleShot(1);
            runType=true;
            pausew->hide();
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

void w1::fromPause2w1()
{
    if(remainingTime<1000)
        w1::opacityDown(remainingTime);
    else
    {
        timer3->start(remainingTime-1000);
        timer3->setSingleShot(1);
    }
    timer2->start(remainingTime);
    timer2->setSingleShot(1);
    runType=true;
    pausew->hide();
}

void w1::fromPause2main()
{
    emit retmain();
    this->close();
}

void w1::passSignal(int cnt)
{
    emit changeMusic(cnt);
}

void w1::fromPause2settings()
{
    emit retsettings();
    this->close();
}

void w1::passBoom()
{
    emit boomEffect();
}

void w1::pass2main()
{
    emit retmain();
}

void w1::switchOn()
{
    this->show();
    changePics();
    opacityUp();
    timer->start(5000);
}
