#ifndef W2_H
#define W2_H

#include <QWidget>
#include <QSoundEffect>
#include <QPixmap>
#include <QImage>
#include <QPixmapCache>
#include <QFile>

// w2 类声明头文件

namespace Ui {
class w2;
}

class w2 : public QWidget
{
    Q_OBJECT

public:
    explicit w2(QWidget *parent = nullptr);  // 构造函数声明
    ~w2();  // 析构函数声明

    Ui::w2 *ui;  // Ui界面指针
    QSoundEffect *butEffect = new QSoundEffect;  // 按钮音效对象指针
    QImage *image0 = new QImage(":/pic/resources/sound.png");  // 图片对象指针，加载有声音标志图片
    QImage *image1 = new QImage(":/pic/resources/muted.png");  // 图片对象指针，加载静音标志图片

signals:
    void sendVolume0(int val);  // 发送音量0的信号，带整数参数
    void sendVolume1(int val);  // 发送音量1的信号，带整数参数
    void switch2w();  // 切换到 w 界面的信号

private slots:
    void on_pushButton_clicked();  // 按钮点击槽函数
    void on_horizontalSlider_valueChanged(int value);  // 滑动条数值改变槽函数
    void on_horizontalSlider_2_valueChanged(int value);  // 滑动条数值改变槽函数
    void spawned(double vol0, double vol1);  // 生成函数，带两个双精度浮点数参数
    void checkIndexChangedSignal(int index);  // 检查索引变化信号槽函数
    void on_pushButton_2_clicked();  // 按钮点击槽函数

private:
    void keyPressEvent(QKeyEvent *event) override;  // 键盘按下事件处理函数声明
    bool eventFilter(QObject *obj, QEvent *event) override;  // 事件过滤器函数声明
};

#endif // W2_H
