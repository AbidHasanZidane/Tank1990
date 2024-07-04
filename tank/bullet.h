#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include<QtDebug>

class Bullet : public QGraphicsPixmapItem
{
public:

    Bullet(QPoint _pos,QPixmap _pixmap);
    
    int mBulletSpeed=25;

    ~Bullet()
    {
        qDebug()<<"~bullet"<<endl;
    }
    
};
#endif // BULLET_H
