#include "achievement.h"
#include "qevent.h"
#include "ui_achievement.h"

achievement::achievement(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::achievement)
{
    ui->setupUi(this);
    ui->pushButton->setAttribute(Qt::WA_Hover,true);
    ui->pushButton->installEventFilter(this);
    ui->label_5->setText("总 杀 敌 数 :"+settings::readSettings("KillNum:"));
    ui->label_6->setText("总 死 亡 数 :"+settings::readSettings("Death:"));
    ui->label_7->setText("杀 敌 / 死 亡 比 :"+(QString::number(settings::readSettings("KillNum:").toDouble()/settings::readSettings("Death:").toDouble())).left(5));
    ui->label_8->setText("总 通 关 数 :"+settings::readSettings("Accomplishment:"));
}

achievement::~achievement()
{
    delete ui;
}

void achievement::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Escape)
    {
        emit switch2w();
        this->close();
    }
}

void achievement::on_pushButton_clicked()
{
    emit switch2w();
    this->close();
}

bool achievement::eventFilter(QObject *obj, QEvent *event)
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
