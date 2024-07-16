#include "w2.h"
#include "ui_w2.h"
#include "widget.h"

w2::w2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::w2)
{
    ui->setupUi(this);

    // 设置窗口属性，包括最小化、最大化和关闭按钮
    this->setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint);

    // 设置按钮音效的源文件
    butEffect->setSource(QUrl::fromLocalFile(":/music/resources/bell.wav"));

    // 设置按钮支持鼠标悬停事件，并安装事件过滤器
    ui->pushButton->setAttribute(Qt::WA_Hover, true);
    ui->pushButton->installEventFilter(this);
    ui->pushButton_2->setAttribute(Qt::WA_Hover, true);
    ui->pushButton_2->installEventFilter(this);

    // 初始化下拉框选项并连接信号与槽
    QStringList list;
    list << "全屏" << "2560 x 1440" << "1920 x 1080" << "1600 x 900" << "1280 x 720" << "1024 x 576";
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
    // 发送切换到 w 界面的信号并关闭当前窗口
    emit switch2w();
    this->close();
}

void w2::on_horizontalSlider_valueChanged(int value)
{
    // 根据滑动条的值设置标签显示的图片，并发送音量0的信号
    if (value == 0)
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
    // 根据滑动条的值设置标签显示的图片，并设置音效的音量，同时发送音量1的信号
    if (value == 0)
    {
        ui->label_4->setPixmap(QPixmap::fromImage(*image1));
    }
    else
    {
        ui->label_4->setPixmap(QPixmap::fromImage(*image0));
    }
    double dvalue = value;
    butEffect->setVolume(dvalue / 100);
    emit sendVolume1(value);
}

bool w2::eventFilter(QObject *obj, QEvent *event)
{
    // 事件过滤器处理按钮的鼠标悬停事件
    if (obj == ui->pushButton)
    {
        if (event->type() == QEvent::HoverEnter)
        {
            ui->pushButton->setStyleSheet("background-color:rgba(255,255,255,0.5)");
            butEffect->play();
            return true;
        }
        if (event->type() == QEvent::HoverLeave)
        {
            ui->pushButton->setStyleSheet("background-color:rgba(255,255,255,1)");
            return true;
        }
    }
    else if (obj == ui->pushButton_2)
    {
        if (event->type() == QEvent::HoverEnter)
        {
            ui->pushButton_2->setStyleSheet("background-color:rgba(255,255,255,0.5)");
            butEffect->play();
            return true;
        }
        if (event->type() == QEvent::HoverLeave)
        {
            ui->pushButton_2->setStyleSheet("background-color:rgba(255,255,255,1)");
            return true;
        }
    }
    return false;
}

void w2::spawned(double vol0, double vol1)
{
    // 根据传入的音量值设置标签显示的图片和滑动条的值，并设置音效的音量
    if (vol0 == 0)
    {
        ui->label->setPixmap(QPixmap::fromImage(*image1));
    }
    else
    {
        ui->label->setPixmap(QPixmap::fromImage(*image0));
    }
    if (vol1 == 0)
    {
        ui->label_4->setPixmap(QPixmap::fromImage(*image1));
    }
    else
    {
        ui->label_4->setPixmap(QPixmap::fromImage(*image0));
    }
    ui->horizontalSlider->setValue(vol0);
    ui->horizontalSlider_2->setValue(vol1);
    double dvol = vol1;
    butEffect->setVolume(dvol / 100);
}

void w2::checkIndexChangedSignal(int index)
{
    // 根据下拉框的索引值执行相应的操作
    switch (index)
    {
    case 0:
    {
        // 获取主屏幕的大小并退出应用程序
        QScreen *screen = QGuiApplication::primaryScreen();
        qApp->exit(screen->size().height());
    }
    case 1: qApp->exit(2560); break;
    case 2: qApp->exit(1920); break;
    case 3: qApp->exit(1600); break;
    case 4: qApp->exit(1280); break;
    case 5: qApp->exit(1024); break;
    }
}

void w2::on_pushButton_2_clicked()
{
    // 点击按钮将滑动条的值设置为70
    ui->horizontalSlider->setValue(70);
    ui->horizontalSlider_2->setValue(70);
}

void w2::keyPressEvent(QKeyEvent *event)
{
    // 处理按键事件，如果按下的是 Escape 键，则发送切换到 w 界面的信号并关闭当前窗口
    if (event->key() == Qt::Key_Escape)
    {
        emit switch2w();
        this->close();
    }
}
