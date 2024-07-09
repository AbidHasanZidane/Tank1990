#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSoundEffect>
#include <QKeyEvent>
#include <QTimer>
#include "w1.h"
#include "w2.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QSoundEffect *effect=new QSoundEffect;
    QSoundEffect *butEffect=new QSoundEffect;
    Ui::Widget *ui;
    QTimer *timer0 = new QTimer(this);
    QTimer *timer1 = new QTimer(this);
    double curVol0=70;
    double curVol1=70;
    bool upedge=true;
    double opacity=0;
    int state=0;
    std::string scale;

signals:
    void spawnw2(double vol0,double vol1);

private slots:
    void on_toolButton_clicked();
    void on_pushButton_2_clicked();
    void changeVolume0(int val);
    void changeVolume1(int val);
    void switchOn();
    void changeOpacity();
    void changeTexts();

private:
    void keyPressEvent(QKeyEvent *event) override;
    bool eventFilter(QObject *obj, QEvent *event) override;
    double factorx=1,factory=1;
};
#endif // WIDGET_H
