#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include "mainwindow.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::Widget)
{
    ui->setupUi(this);  // 设置UI

    ui->pushButton_2->setStyleSheet("background-color:rgba(255,255,255,1)");  // 设置按钮样式
    ui->toolButton->setStyleSheet("background-color:rgba(255,255,255,1)");  // 设置工具按钮样式

    effect->setSource(QUrl::fromLocalFile(":/music/resources/background.wav"));  // 设置背景音效源
    effect->setLoopCount(QSoundEffect::Infinite);  // 设置音效循环次数
    effect->setVolume(0.7);  // 设置音量
    effect->play();  // 播放音效

    butEffect->setSource(QUrl::fromLocalFile(":/music/resources/bell.wav"));  // 设置按钮音效源
    butEffect->setVolume(0.7);  // 设置音量

    ui->pushButton_2->setAttribute(Qt::WA_Hover, true);  // 启用按钮的悬停事件
    ui->pushButton_2->installEventFilter(this);  // 安装按钮的事件过滤器

    ui->toolButton->setAttribute(Qt::WA_Hover, true);  // 启用工具按钮的悬停事件
    ui->toolButton->installEventFilter(this);  // 安装工具按钮的事件过滤器

    connect(timer0, SIGNAL(timeout()), this, SLOT(changeOpacity()));  // 连接定时器信号和槽函数
    timer0->start(20);  // 启动定时器

    connect(timer1, SIGNAL(timeout()), this, SLOT(changeTexts()));  // 连接定时器信号和槽函数
    timer1->start(800);  // 启动定时器
}

Widget::~Widget()
{
    delete ui;  // 释放UI资源
}

void Widget::on_toolButton_clicked()
{
    w2 *w = new w2();  // 创建w2窗口对象
    w->show();  // 显示w2窗口
    this->hide();  // 隐藏当前窗口

    connect(w, SIGNAL(sendVolume0(int)), this, SLOT(changeVolume0(int)));  // 连接信号和槽函数
    connect(w, SIGNAL(sendVolume1(int)), this, SLOT(changeVolume1(int)));  // 连接信号和槽函数
    connect(w, SIGNAL(switch2w()), this, SLOT(switchOn()));  // 连接信号和槽函数
    connect(this, SIGNAL(spawnw2(double, double)), w, SLOT(spawned(double, double)));  // 连接信号和槽函数

    emit spawnw2(curVol0, curVol1);  // 发射信号，生成w2窗口并传递当前音量值
}

void Widget::on_pushButton_2_clicked()
{
    this->close();  // 关闭窗口
}

void Widget::changeVolume0(int val)
{
    curVol0 = val;  // 更新音量值
    effect->setVolume(curVol0 / 100);  // 设置背景音效音量
}

void Widget::changeVolume1(int val)
{
    curVol1 = val;  // 更新音量值
    butEffect->setVolume(curVol1 / 100);  // 设置按钮音效音量
}

void Widget::switchOn()
{
    this->show();  // 显示窗口
}

bool Widget::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->pushButton_2)
    {
        if (event->type() == QEvent::HoverEnter)
        {
            ui->pushButton_2->setStyleSheet("background-color:rgba(255,255,255,0.7)");  // 按钮悬停时改变样式
            butEffect->play();  // 播放按钮音效
            return true;
        }
        if (event->type() == QEvent::HoverLeave)
        {
            ui->pushButton_2->setStyleSheet("background-color:rgba(255,255,255,1)");  // 恢复按钮原样式
            return true;
        }
    }
    else if (obj == ui->toolButton)
    {
        if (event->type() == QEvent::HoverEnter)
        {
            butEffect->play();  // 播放工具按钮音效
            return true;
        }
    }
    return QWidget::eventFilter(obj, event);  // 默认事件处理
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape)
        this->close();  // 按下Esc键关闭窗口
    else
    {
        this->hide();  // 隐藏当前窗口
        MainWindow *w = new MainWindow();  // 创建MainWindow对象
        w->show();  // 显示MainWindow窗口
    }
}

void Widget::changeOpacity()
{
    if (upedge)
    {
        opacity += 0.01;  // 增加不透明度
        if (opacity > 1)
            upedge = false;  // 达到上限，改变标志位
    }
    else
    {
        opacity -= 0.01;  // 减少不透明度
        if (opacity < 0.3)
            upedge = true;  // 达到下限，改变标志位
    }

    QString str = QString::number(opacity);  // 转换为字符串
    QString style = "color:rgba(200,200,200," + str + ")";  // 设置样式
    ui->label_2->setStyleSheet(style);  // 应用样式
}

void Widget::changeTexts()
{
    switch (state)
    {
    case 0:
    {
        state++;
        ui->label_2->setText("按 任 意 键 开 始 游 戏");  // 更新文本内容
        ui->label_2->setGeometry(475, 545, 400, 40);  // 更新位置
        break;
    }
    case 1:
    {
        state++;
        ui->label_2->setText("按 任 意 键 开 始 游 戏 .");  // 更新文本内容
        ui->label_2->setGeometry(469,545,400,40); // 更新位置
        break;
     }
        case 2:
        {
            state++;
            ui->label_2->setText("按 任 意 键 开 始 游 戏 . ."); // 更新文本内容
            ui->label_2->setGeometry(463,545,400,40); // 更新位置
            break;
        }
        case 3:
        {
            state=0;
            ui->label_2->setText("按 任 意 键 开 始 游 戏 . . ."); // 更新文本内容
            ui->label_2->setGeometry(457,545,400,40); // 更新位置
            break;
        }
    }
}
