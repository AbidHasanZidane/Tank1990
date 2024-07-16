#ifndef BOSSBULLET_H
#define BOSSBULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QtDebug>
#include <QObject>

class BossBullet : public QGraphicsPixmapItem, public QObject
{
public:
    char _dir;  // 子弹移动方向

    BossBullet(QPoint _pos, QPixmap _pixmap, char _dir);  // 构造函数声明

    int BossBulletSpeed = 40;  // 子弹移动速度

    void BossBulletMove();  // 子弹移动函数声明
};

#endif // BOSSBULLET_H
