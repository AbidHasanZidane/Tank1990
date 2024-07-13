#ifndef BOSSBULLET_H
#define BOSSBULLET_H
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include<QtDebug>
#include<QObject>

class BossBullet : public QGraphicsPixmapItem,public QObject
{
public:
    char _dir;

    BossBullet(QPoint _pos,QPixmap _pixmap,char _dir);

    int BossBulletSpeed=40;

    void BossBulletMove();
};

#endif // BOSSBULLET_H
