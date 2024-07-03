#include "bullet.h"

Bullet::Bullet(QPoint _pos, QPixmap _pixmap)
{
    this->setPos(_pos);
    this->setPixmap(QPixmap(_pixmap));
    mSpeed=0;
}

void Bullet::BulletMove(QPoint _dir)
{
    this->moveBy(_dir.x()*mSpeed,_dir.y()*mSpeed);
}
