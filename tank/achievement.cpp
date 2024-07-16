#include "achievement.h"
#include "qevent.h"  // 包含事件处理的头文件
#include "ui_achievement.h"  // 包含UI的头文件

achievement::achievement(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::achievement)
{
    ui->setupUi(this);  // 从UI文件设置UI界面
    ui->pushButton->setAttribute(Qt::WA_Hover, true);  // 启用按钮的鼠标悬停属性
    ui->pushButton->installEventFilter(this);  // 安装事件过滤器到按钮

    // 根据存储的设置设置标签内容
    ui->label_5->setText("总 杀 敌 数 :" + settings::readSettings("KillNum:"));
    ui->label_6->setText("总 死 亡 数 :" + settings::readSettings("Death:"));
    ui->label_7->setText("杀 敌 / 死 亡 比 :" +
                         (QString::number(settings::readSettings("KillNum:").toDouble() /
                                         settings::readSettings("Death:").toDouble())).left(5));
    ui->label_8->setText("总 通 关 数 :" + settings::readSettings("Accomplishment:"));
}

achievement::~achievement()
{
    delete ui;  // 析构函数：删除UI对象
}

void achievement::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape)
    {
        emit switch2w();  // 发送切换信号
        this->close();  // 关闭窗口
    }
}

void achievement::on_pushButton_clicked()
{
    emit switch2w();  // 发送切换信号
    this->close();  // 关闭窗口
}

bool achievement::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->pushButton)
    {
        if (event->type() == QEvent::HoverEnter)  // 处理鼠标进入事件
        {
            ui->pushButton->setStyleSheet("background-color:rgba(255,255,255,0.7)");  // 设置按钮样式
            butEffect->play();  // 播放声音效果
            return true;  // 事件已处理
        }
        if (event->type() == QEvent::HoverLeave)  // 处理鼠标离开事件
        {
            ui->pushButton->setStyleSheet("background-color:rgba(255,255,255,1)");  // 恢复按钮样式
            return true;  // 事件已处理
        }
    }
    return false;  // 默认情况：事件未处理
}
