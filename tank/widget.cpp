#include "widget.h"
#include "ui_w2.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 设置窗口的最小化、最大化和关闭按钮
    this->setWindowFlags(Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint);

    // 设置按钮的样式表
    ui->pushButton_2->setStyleSheet("background-color:rgba(255,255,255,1);border:4px groove gray;border-radius:30px;padding:2px 4px;border-style: outset;");
    ui->toolButton->setStyleSheet("background-color:rgba(255,255,255,1);border:0px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;");
    ui->toolButton_2->setStyleSheet("background-color:rgba(255,255,255,1);border:0px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;");
    ui->toolButton_3->setStyleSheet("background-color:rgba(255,255,255,1);border:0px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;");

    // 设置音效对象的属性和播放
    effect->setSource(QUrl::fromLocalFile(":/music/resources/menuTheme.wav"));
    effect->setLoopCount(QSoundEffect::Infinite);
    effect->setVolume(curVol0);
    effect->play();
    butEffect->setSource(QUrl::fromLocalFile(":/music/resources/bell.wav"));
    butEffect->setVolume(curVol1);
    boomEffect->setSource(QUrl::fromLocalFile(":/music/resources/TANKBOOM.wav"));
    boomEffect->setVolume(curVol1);

    // 设置按钮的鼠标悬停事件过滤器
    ui->pushButton_2->setAttribute(Qt::WA_Hover,true);
    ui->pushButton_2->installEventFilter(this);
    ui->toolButton->setAttribute(Qt::WA_Hover,true);
    ui->toolButton->installEventFilter(this);
    ui->toolButton_2->setAttribute(Qt::WA_Hover,true);
    ui->toolButton_2->installEventFilter(this);
    ui->toolButton_3->setAttribute(Qt::WA_Hover,true);
    ui->toolButton_3->installEventFilter(this);

    // 连接定时器的超时信号与槽函数
    connect(timer0, SIGNAL(timeout()), this, SLOT(changeOpacity()));
    timer0->start(20);
    connect(timer1, SIGNAL(timeout()), this, SLOT(changeTexts()));
    timer1->start(800);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_toolButton_clicked()
{
    // 创建w2窗口，并设置固定大小和显示
    w2 *w = new w2();
    w->setFixedSize(1280, 720);
    w->show();

    // 隐藏当前窗口
    this->hide();

    // 连接w2窗口的信号与槽
    connect(w, SIGNAL(sendVolume0(int)), this, SLOT(changeVolume0(int)));
    connect(w, SIGNAL(sendVolume1(int)), this, SLOT(changeVolume1(int)));
    connect(w, SIGNAL(switch2w()), this, SLOT(switchOn()));
    connect(this, SIGNAL(spawnw2(double, double)), w, SLOT(spawned(double, double)));

    // 发送生成w2界面的信号，并传递当前音量
    emit spawnw2(curVol0, curVol1);

    // 根据缩放比例设置w2界面的分辨率选择框
    if (scale == "0.8")
        w->ui->comboBox->setCurrentIndex(5);
    else if (scale == "1")
        w->ui->comboBox->setCurrentIndex(4);
    else if (scale == "1.25")
        w->ui->comboBox->setCurrentIndex(3);
    else if (scale == "1.5")
        w->ui->comboBox->setCurrentIndex(2);
    else if (scale == "2")
        w->ui->comboBox->setCurrentIndex(1);
}

void Widget::on_pushButton_2_clicked()
{
    // 关闭当前窗口
    this->close();
}

void Widget::changeVolume0(int val)
{
    // 更新当前音量0，并设置音效对象的音量
    curVol0 = val;
    effect->setVolume(curVol0 / 100);
}

void Widget::changeVolume1(int val)
{
    // 更新当前音量1，并设置按钮音效和爆炸音效对象的音量
    curVol1 = val;
    butEffect->setVolume(curVol1 / 100);
    boomEffect->setVolume(curVol1 / 100);
}

void Widget::switchOn()
{
    // 显示当前窗口
    this->show();
}

bool Widget::eventFilter(QObject *obj, QEvent *event)
{
    // 按钮的鼠标悬停事件处理
    if (obj == ui->pushButton_2)
    {
        if (event->type() == QEvent::HoverEnter)
        {
            ui->pushButton_2->setStyleSheet("background-color:rgba(255,255,255,0.7);border:4px groove gray;border-radius:30px;padding:2px 4px;border-style: outset;");
            butEffect->play();
            return true;
        }
        if (event->type() == QEvent::HoverLeave)
        {
            ui->pushButton_2->setStyleSheet("background-color:rgba(255,255,255,1);border:4px groove gray;border-radius:30px;padding:2px 4px;border-style: outset;");
            return true;
        }
    }
    else if (obj == ui->toolButton)
    {
        if (event->type() == QEvent::HoverEnter)
        {
            ui->toolButton->setStyleSheet("background-color:rgba(255,255,255,0.7);border:0px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;");
            butEffect->play();
            return true;
        }
        if (event->type() == QEvent::HoverLeave)
        {
            ui->toolButton->setStyleSheet("background-color:rgba(255,255,255,1);border:0px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;");
            return true;
        }
    }
    else if (obj == ui->toolButton_2)
    {
        if (event->type() == QEvent::HoverEnter)
        {
            ui->toolButton_2->setStyleSheet("background-color:rgba(255,255,255,0.7);border:0px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;");
            butEffect->play();
            return true;
        }
        if (event->type() == QEvent::HoverLeave)
        {
            ui->toolButton_2->setStyleSheet("background-color:rgba(255,255,255,1);border:0px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;");
            return true;
        }
    }
    else if (obj == ui->toolButton_3)
    {
        if (event->type() == QEvent::HoverEnter)
        {
            ui->toolButton_3->setStyleSheet("background-color:rgba(255,255,255,0.7);border:0px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;");
            butEffect->play();
            return true;
        }
        if (event->type() == QEvent::HoverLeave)
        {
            ui->toolButton_3->setStyleSheet("background-color:rgba(255,255,255,1);border:0px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;");
            return true;
        }
    }
    return QWidget::eventFilter(obj, event);
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    // 处理按键事件
    if (event->key() == Qt::Key_Escape)
        this->close();
    else
    {
        // 显示w1窗口，并连接信号与槽
        this->hide();
        w1 *w = new w1();
        connect(w, &w1::retmain, this, &Widget::switchOn);
        connect(w, SIGNAL(changeMusic(int)), this, SLOT(changeMusic(int)));
        connect(w, SIGNAL(boomEffect()), this, SLOT(playBoom()));
        connect(w, &w1::retsettings, this, &Widget::on_toolButton_clicked);
        w->setFixedSize(1280, 720);
        w->show();
    }
}

void Widget::changeOpacity()
{
    // 改变标签的透明度效果
    if (upedge)
    {
        opacity += 0.01;
        if (opacity > 1)
            upedge = false;
    }
    else
    {
        opacity -= 0.01;
        if (opacity < 0.3)
            upedge = true;
    }
    QString str = QString::number(opacity);
    QString style = "color:rgba(200,200,200," + str + ")";
    ui->label_2->setStyleSheet(style);
}

void Widget::changeTexts()
{
    // 改变标签的文字和位置
    switch (state)
    {
    case 0:
        state++;
        ui->label_2->setText("按 任 意 键 开 始 游 戏");
        ui->label_2->setGeometry(475, 545, 400, 40);
        break;
    case 1:
        state++;
        ui->label_2->setText("按 任 意 键 开 始 游 戏 .");
        ui->label_2->setGeometry(469, 545, 400, 40);
        break;
    case 2:
        state++;
        ui->label_2->setText("按 任 意 键 开 始 游 戏 . .");
        ui->label_2->setGeometry(463, 545, 400, 40);
        break;
    case 3:
        state = 0;
        ui->label_2->setText("按 任 意 键 开 始 游 戏 . . .");
        ui->label_2->setGeometry(457, 545, 400, 40);
        break;
    }
}

void Widget::on_toolButton_2_clicked()
{
    // 显示成就界面，隐藏当前窗口，并连接信号与槽
    achievement *w = new achievement();
    w->setFixedSize(1280, 720);
    w->show();
    this->hide();
    connect(w, SIGNAL(switch2w()), this, SLOT(switchOn()));
}

void Widget::changeMusic(int cnt)
{
    // 根据传入的参数切换背景音乐
    switch (cnt)
    {
    case 1:
        effect->stop();
        effect1->setSource(QUrl::fromLocalFile(":/music/resources/Lvl1Background.wav"));
        effect1->setLoopCount(QSoundEffect::Infinite);
        effect1->setVolume(curVol0);
        effect1->play();
        break;
    case 2:
        effect1->stop();
        effect2->setSource(QUrl::fromLocalFile(":/music/resources/Lvl2Background.wav"));
        effect2->setLoopCount(QSoundEffect::Infinite);
        effect2->setVolume(curVol0);
        effect2->play();
        break;
    case 3:
        effect2->stop();
        effect3->setSource(QUrl::fromLocalFile(":/music/resources/Lvl3BossMusic.wav"));
        effect3->setLoopCount(QSoundEffect::Infinite);
        effect3->setVolume(curVol0);
        effect3->play();
        break;
    default:
        effect3->stop();
        break;
    }
}

void Widget::on_toolButton_3_clicked()
{
    // 显示商店界面，隐藏当前窗口，并连接信号与槽
    shop *w = new shop;
    w->setFixedSize(1280, 720);
    w->show();
    this->hide();
    connect(w, SIGNAL(switch2w()), this, SLOT(switchOn()));
    connect(this, SIGNAL(spawnshop(double)), w, SLOT(spawned(double)));
    emit spawnshop(curVol1);
}

void Widget::playBoom()
{
    // 播放爆炸音效
    boomEffect->setVolume(curVol1);
    boomEffect->play();
}
