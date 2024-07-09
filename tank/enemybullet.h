#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include<QtDebug>
#include<QObject>

class enemyBullet : public QGraphicsPixmapItem,public QObject
{
public:
    char _dir;

    enemyBullet(QPoint _pos,QPixmap _pixmap,char _dir);

    int eBulletSpeed=25;

    void eBulletMove();
};

#endif // ENEMYBULLET_H
