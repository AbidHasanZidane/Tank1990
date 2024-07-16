#include "shop.h"
#include "ui_shop.h"

shop::shop(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::shop)
{
    ui->setupUi(this);  // 设置UI界面

    ui->label_10->setVisible(0);  // 隐藏标签
    ui->label_11->setVisible(0);  // 隐藏标签
    ui->label_12->setVisible(0);  // 隐藏标签

    refresh();  // 刷新界面显示

    // 设置按钮悬停效果和事件过滤器
    ui->pushButton->setAttribute(Qt::WA_Hover, true);
    ui->pushButton->installEventFilter(this);
    ui->pushButton_2->setAttribute(Qt::WA_Hover, true);
    ui->pushButton_2->installEventFilter(this);
    ui->pushButton_3->setAttribute(Qt::WA_Hover, true);
    ui->pushButton_3->installEventFilter(this);
    ui->pushButton_4->setAttribute(Qt::WA_Hover, true);
    ui->pushButton_4->installEventFilter(this);

    butEffect->setSource(QUrl::fromLocalFile(":/music/resources/bell.wav"));  // 设置按钮音效来源
}

shop::~shop()
{
    delete ui;  // 删除UI界面对象
}

void shop::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape)  // 如果按下ESC键
    {
        emit switch2w();  // 发送切换到游戏界面的信号
        this->close();  // 关闭当前窗口
    }
}

void shop::on_pushButton_clicked()
{
    emit switch2w();  // 发送切换到游戏界面的信号
    this->close();  // 关闭当前窗口
}

bool shop::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == ui->pushButton)  // 如果事件对象是按钮1
    {
        if(event->type() == QEvent::HoverEnter)  // 如果是悬停进入事件
        {
            ui->pushButton->setStyleSheet("background-color:rgba(255,255,255,0.7)");  // 设置按钮背景色
            butEffect->play();  // 播放按钮音效
            return true;
        }
        if(event->type() == QEvent::HoverLeave)  // 如果是悬停离开事件
        {
            ui->pushButton->setStyleSheet("background-color:rgba(255,255,255,1)");  // 恢复按钮背景色
            return true;
        }
    }
    else if(obj == ui->pushButton_2)  // 如果事件对象是按钮2
    {
        if(event->type() == QEvent::HoverEnter)  // 如果是悬停进入事件
        {
            ui->label_4->setGeometry(530, -10, 220, 220);  // 设置标签位置
            return true;
        }
        if(event->type() == QEvent::HoverLeave)  // 如果是悬停离开事件
        {
            ui->label_4->setGeometry(560, 20, 160, 160);  // 恢复标签位置
            return true;
        }
    }
    else if(obj == ui->pushButton_3)  // 如果事件对象是按钮3
    {
        if(event->type() == QEvent::HoverEnter)  // 如果是悬停进入事件
        {
            ui->label_5->setGeometry(530, 190, 220, 220);  // 设置标签位置
            return true;
        }
        if(event->type() == QEvent::HoverLeave)  // 如果是悬停离开事件
        {
            ui->label_5->setGeometry(560, 220, 160, 160);  // 恢复标签位置
            return true;
        }
    }
    else if(obj == ui->pushButton_4)  // 如果事件对象是按钮4
    {
        if(event->type() == QEvent::HoverEnter)  // 如果是悬停进入事件
        {
            ui->label_6->setGeometry(530, 390, 220, 220);  // 设置标签位置
            return true;
        }
        if(event->type() == QEvent::HoverLeave)  // 如果是悬停离开事件
        {
            ui->label_6->setGeometry(560, 420, 160, 160);  // 恢复标签位置
            return true;
        }
    }
    return false;
}

void shop::spawned(double vol)
{
    butEffect->setVolume(vol / 100);  // 设置按钮音效音量
}

void shop::on_pushButton_2_clicked()
{
    butEffect->play();  // 播放按钮音效
    if(settings::readSettings("Hp:").toInt() < 8)  // 如果当前生命值小于8
    {
        if(settings::readSettings("Grade:").toInt() >= 1000)  // 如果当前等级大于等于1000
        {
            settings::modifySettings("Grade:", QString::number(settings::readSettings("Grade:").toInt() - 1000));  // 扣除等级
            settings::modifySettings("Hp:", QString::number(settings::readSettings("Hp:").toInt() + 1));  // 增加生命值
        }
        else
        {
            ui->label_14->setStyleSheet("color:rgba(255,0,0,1)");  // 显示红色警告文字
            QTimer::singleShot(1000, this, [this]{ ui->label_14->setStyleSheet("color:rgba(0,255,0,1)"); });  // 一秒后恢复颜色
        }
    }
    else
    {
        ui->label_10->setStyleSheet("color:rgba(255,0,0,1)");  // 显示红色警告文字
        QTimer::singleShot(1000, this, [this]{ ui->label_10->setStyleSheet("color:rgba(0,255,0,1)"); });  // 一秒后恢复颜色
    }
    refresh();  // 刷新界面显示
}

void shop::on_pushButton_3_clicked()
{
    butEffect->play();  // 播放按钮音效
    if(settings::readSettings("Speed:").toInt() < 20)  // 如果当前速度小于20
    {
        if(settings::readSettings("Grade:").toInt() >= 1000)  // 如果当前等级大于等于1000
        {
            settings::modifySettings("Grade:", QString::number(settings::readSettings("Grade:").toInt() - 1000));  // 扣除等级
            settings::modifySettings("Speed:", QString::number(settings::readSettings("Speed:").toInt() + 2));  // 增加速度
        }
        else
        {
            ui->label_14->setStyleSheet("color:rgba(255,0,0,1)");  // 显示红色警告文字
            QTimer::singleShot(1000, this, [this]{ ui->label_14->setStyleSheet("color:rgba(0,255,0,1)"); });  // 一秒后恢复颜色
        }
    }
    else
    {
        ui->label_11->setStyleSheet("color:rgba(255,0,0,1)");  // 显示红色警告文字
        QTimer::singleShot(1000, this, [this]{ ui->label_11->setStyleSheet("color:rgba(0,255,0,1)"); });  // 一秒后恢复颜色
    }
    refresh();  // 刷新界面显示
}

void shop::on_pushButton_4_clicked()
{
    butEffect->play();  // 播放按钮音效
    if(settings::readSettings("Fire:").toInt() > 300)  // 如果当前火力大于300
    {
        if(settings::readSettings("Grade:").toInt() >= 1000)  // 如果当前等级大于等于1000
        {
            settings::modifySettings("Grade:", QString::number(settings::readSettings("Grade:").toInt() - 1000));  // 扣除等级
            settings::modifySettings("Fire:", QString::number(settings::readSettings("Fire:").toInt() - 40));  // 减少火力
        }
        else
        {
            ui->label_14->setStyleSheet("color:rgba(255,0,0,1)");  // 显示红色警告文字
            QTimer::singleShot(1000, this, [this]{ ui->label_14->setStyleSheet("color:rgba(0,255,0,1)"); });  // 一秒后恢复颜色
        }
    }
    else
    {
        ui->label_12->setStyleSheet("color:rgba(255,0,0,1)");  // 显示红色警告文字
        QTimer::singleShot(1000, this, [this]{ ui->label_12->setStyleSheet("color:rgba(0,255,0,1)"); });  // 一秒后恢复颜色
    }
    refresh();  // 刷新界面显示
}

void shop::refresh()
{
    switch(settings::readSettings("Hp:").toInt())
    {
        case 3: ui->label_7->setText("0/5"); break;
        case 4: ui->label_7->setText("1/5"); break;
        case 5: ui->label_7->setText("2/5"); break;
        case 6: ui->label_7->setText("3/5"); break;
        case 7: ui->label_7->setText("4/5"); break;
        case 8: ui->label_7->setText("5/5"); ui->label_10->setVisible(1); break;
    }
    switch(settings::readSettings("Speed:").toInt())
    {
        case 10: ui->label_8->setText("0/5"); break;
        case 12: ui->label_8->setText("1/5"); break;
        case 14: ui->label_8->setText("2/5"); break;
        case 16: ui->label_8->setText("3/5"); break;
        case 18: ui->label_8->setText("4/5"); break;
        case 20: ui->label_8->setText("5/5"); ui->label_11->setVisible(1); break;
    }
    switch(settings::readSettings("Fire:").toInt())
    {
        case 500: ui->label_9->setText("0/5"); break;
        case 460: ui->label_9->setText("1/5"); break;
        case 420: ui->label_9->setText("2/5"); break;
        case 380: ui->label_9->setText("3/5"); break;
        case 340: ui->label_9->setText("4/5"); break;
        case 300: ui->label_9->setText("5/5"); ui->label_12->setVisible(1); break;
    }
    ui->label_14->setText(settings::readSettings("Grade:"));  // 显示等级信息
}
