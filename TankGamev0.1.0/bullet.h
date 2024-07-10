#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include<QtDebug>
#include<QObject>

class Bullet : public QGraphicsPixmapItem,public QObject
{
public:
    char _dir;

    Bullet(QPoint _pos,QPixmap _pixmap,char _dir);
    
    int mBulletSpeed=25;

    void BulletMove();
    
};
#endif // BULLET_H
