#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include<QtDebug>
#include<QObject>

class enemyBullet : public QGraphicsPixmapItem,public QObject
{
public:
    char _dir;// 子弹的移动方向 ('N', 'S', 'W', 'E')

    enemyBullet(QPoint _pos,QPixmap _pixmap,char _dir);// 构造函数，初始化子弹的位置、图像和方向

    int eBulletSpeed=40;// 子弹的移动速度

    void eBulletMove(); // 子弹移动的方法

};

#endif // ENEMYBULLET_H
