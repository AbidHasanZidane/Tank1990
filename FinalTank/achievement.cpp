#include "achievement.h"
#include "qevent.h"
#include "ui_achievement.h"

achievement::achievement(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::achievement)
{
    // 初始化界面
    ui->setupUi(this);

    // 设置按钮支持鼠标悬停
    ui->pushButton->setAttribute(Qt::WA_Hover, true);

    // 安装事件过滤器，用于处理特定对象的事件
    ui->pushButton->installEventFilter(this);

    // 设置成就界面的文本内容
    ui->label_5->setText("总 杀 敌 数 :" + settings::readSettings("KillNum:"));
    ui->label_6->setText("总 死 亡 数 :" + settings::readSettings("Death:"));

    // 计算杀敌/死亡比例并显示，限制为小数点前5位
    double killNum = settings::readSettings("KillNum:").toDouble();
    double deathNum = settings::readSettings("Death:").toDouble();
    QString killDeathRatio = QString::number(killNum / deathNum, 'f', 5);
    ui->label_7->setText("杀 敌 / 死 亡 比 :" + killDeathRatio);

    // 设置总通关数
    ui->label_8->setText("总 通 关 数 :" + settings::readSettings("Accomplishment:"));
}

achievement::~achievement()
{
    delete ui;
}

void achievement::keyPressEvent(QKeyEvent *event)
{
    // 捕捉按键事件，如果是按下ESC键，则发送切换信号并关闭界面
    if (event->key() == Qt::Key_Escape)
    {
        emit switch2w();
        this->close();
    }
}

void achievement::on_pushButton_clicked()
{
    // 按钮点击事件，发送切换信号并关闭界面
    emit switch2w();
    this->close();
}

bool achievement::eventFilter(QObject *obj, QEvent *event)
{
    // 事件过滤器，用于处理按钮的悬停事件
    if (obj == ui->pushButton)
    {
        if (event->type() == QEvent::HoverEnter) // 鼠标进入事件
        {
            ui->pushButton->setStyleSheet("background-color: rgba(255, 255, 255, 0.7)");
            // 播放按钮特效
            butEffect->play();
            return true;
        }
        if (event->type() == QEvent::HoverLeave) // 鼠标离开事件
        {
            ui->pushButton->setStyleSheet("background-color: rgba(255, 255, 255, 1)");
            return true;
        }
    }
    // 其他情况下返回默认处理
    return false;
}
