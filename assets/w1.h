#ifndef W1_H
#define W1_H

#include <QWidget>
#include <QTimer>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QKeyEvent>
#include <QPixmapCache>
#include <QGraphicsOpacityEffect>
#include "pause.h"
#include "ui_w1.h"

namespace Ui {
class w1;
}

class w1 : public QWidget
{
    Q_OBJECT

public:
    explicit w1(QWidget *parent = nullptr);
    ~w1();
    QPixmap *pixmap=new QPixmap;
    int count=0;
    int remainingTime;
    bool runType=true;
    QTimer *timer = new QTimer;
    QTimer *timer0 = new QTimer;
    QTimer *timer1 = new QTimer;
    QTimer *timer2=new QTimer;
    QTimer *timer3=new QTimer;
    pause *pausew=new pause;
    void changePics();
    void opacityUp();
    void opacityDown(int time);
    QGraphicsOpacityEffect *m_pGraphicsOpacityEffect;
    QPropertyAnimation *animation;

signals:
    void retmain();

private slots:
    void fromPause2w1();
    void fromPause2main();
private:
    void keyPressEvent(QKeyEvent *event) override;
    Ui::w1 *ui;
};

#endif // W1_H
