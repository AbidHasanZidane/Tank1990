#ifndef W2_H
#define W2_H

#include <QWidget>
#include <QSoundEffect>
#include <QPixmap>
#include <QImage>
#include <QPixmapCache>
#include <QFile>

namespace Ui {
class w2;
}

class w2 : public QWidget
{
    Q_OBJECT

public:
    explicit w2(QWidget *parent = nullptr);  // 显式构造函数
    ~w2();  // 析构函数

    Ui::w2 *ui;  // UI对象指针
    QSoundEffect *butEffect = new QSoundEffect;  // 声音效果对象
    QImage *image0 = new QImage(":/pic/resources/sound.png");  // 图片资源
    QImage *image1 = new QImage(":/pic/resources/muted.png");

signals:
    void sendVolume0(int val);  // 发送音量控制信号
    void sendVolume1(int val);
    void switch2w();  // 切换窗口信号

private slots:
    void on_pushButton_clicked();  // 按钮点击槽函数
    void on_horizontalSlider_valueChanged(int value);  // 滑动条数值变化槽函数
    void on_horizontalSlider_2_valueChanged(int value);
    void spawned(double vol0, double vol1);  // 处理音量变化的槽函数
    void on_pushButton_2_clicked();  // 另一个按钮点击槽函数

private:
    bool eventFilter(QObject *obj, QEvent *event) override;  // 事件过滤器重载
};

#endif // W2_H
