#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    MyPushButton(QString normalImg);
    QString normalImgPath;
    //弹跳特效
    void pop1(); //向下跳
    void pop2(); //向上跳
signals:

public slots:
};

#endif // MYPUSHBUTTON_H
