#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QtDebug>
#include <QObject>

class Bullet : public QGraphicsPixmapItem, public QObject
{
public:
    char _dir;  // 子弹的移动方向 ('N', 'S', 'W', 'E')

    Bullet(QPoint _pos, QPixmap _pixmap, char _dir);  // 构造函数，初始化子弹的位置、图像和方向

    int mBulletSpeed = 25;  // 子弹的移动速度

    void BulletMove();  // 子弹移动的方法

};
#endif // BULLET_H
