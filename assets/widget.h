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
    double curVol0=70;
    double curVol1=70;

signals:
    void spawnw2(double vol0,double vol1);

private slots:
    void on_toolButton_clicked();
    void on_pushButton_2_clicked();
    void changeVolume0(int val);
    void changeVolume1(int val);
    void switchOn();
private:
    void keyPressEvent(QKeyEvent *event) override;
    bool eventFilter(QObject *obj, QEvent *event) override;
    void textsLoop();
};
#endif // WIDGET_H
