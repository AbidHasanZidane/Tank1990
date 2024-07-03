#include "mypushbutton.h"
#include<QDebug>
#include<QPropertyAnimation>
MyPushButton::MyPushButton(QString normalImg){
    this->normalImgPath=normalImg;
    QPixmap pix;   
    bool ret=pix.load(normalImg);
    if(!ret){
        qDebug()<<"Failed";
        return;
    }
    this->setFixedSize(pix.width(),pix.height());
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));
}
 void MyPushButton:: pop1(){
     QPropertyAnimation*animation=new QPropertyAnimation(this,"geometry");
     animation->setDuration(200);
     animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
     animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
     animation->setEasingCurve(QEasingCurve::OutBounce);
     animation->start();
 }
 void MyPushButton:: pop2(){
     QPropertyAnimation*animation=new QPropertyAnimation(this,"geometry");
     animation->setDuration(200);
     animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
     animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
     animation->setEasingCurve(QEasingCurve::OutBounce);
     animation->start();
 }
