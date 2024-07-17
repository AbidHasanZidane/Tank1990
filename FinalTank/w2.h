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
    explicit w2(QWidget *parent = nullptr);
    ~w2();
    Ui::w2 *ui;
    QSoundEffect *butEffect=new QSoundEffect;
    QImage *image0=new QImage(":/pic/resources/sound.png");
    QImage *image1=new QImage(":/pic/resources/muted.png");

signals:
    void sendVolume0(int val);
    void sendVolume1(int val);
    void switch2w();

private slots:
    void on_pushButton_clicked();
    void on_horizontalSlider_valueChanged(int value);
    void on_horizontalSlider_2_valueChanged(int value);
    void spawned(double vol0,double vol1);
    void checkIndexChangedSignal(int index);
    void on_pushButton_2_clicked();

private:
    void keyPressEvent(QKeyEvent *event) override;
    bool eventFilter(QObject *obj, QEvent *event) override;

};

#endif // W2_H
