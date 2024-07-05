#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include<QtDebug>
#include<QObject>

class Bullet : public QGraphicsPixmapItem,public QObject
{
public:

    Bullet(QPoint _pos,QPixmap _pixmap);
    
    int mBulletSpeed=25;

    ~Bullet(){
        qDebug()<<"bug"<<endl;
    }
    
};
#endif // BULLET_H
