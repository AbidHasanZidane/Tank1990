#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include <QGraphicsPixmapItem>  // 包含图形项类的头文件
#include <QGraphicsItem>  // 包含图形项类的头文件
#include <QtDebug>  // 包含Qt调试类的头文件
#include <QObject>  // 包含QObject类的头文件，以便继承

class enemyBullet : public QGraphicsPixmapItem, public QObject
{
public:
    char _dir;  // 子弹移动方向

    enemyBullet(QPoint _pos, QPixmap _pixmap, char _dir);  // 构造函数声明

    int eBulletSpeed = 40;  // 子弹移动速度

    void eBulletMove();  // 子弹移动函数声明
};

#endif // ENEMYBULLET_H
