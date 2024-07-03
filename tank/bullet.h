#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>

class Bullet : public QGraphicsPixmapItem
{
public:

    Bullet(QPoint _pos,QPixmap _pixmap);
    
    void BulletMove(QPoint _dir=QPoint(0,-1));
    
    int mSpeed;
    
};
#endif // BULLET_H
