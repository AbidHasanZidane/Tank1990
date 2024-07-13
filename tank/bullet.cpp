#include "bullet.h"

Bullet::Bullet(QPoint _pos, QPixmap _pixmap,char _dir)
{

    this->setPos(_pos);

    this->setPixmap(QPixmap(_pixmap));

    this->_dir=_dir;
}

void Bullet::BulletMove()
{
    switch (this->_dir) {
    case 'N':
        this->moveBy(0,-mBulletSpeed);
        break;
    case 'S':
        this->moveBy(0,mBulletSpeed);
        break;
    case 'W':
        this->moveBy(-mBulletSpeed,0);
        break;
    case 'E':
        this->moveBy(mBulletSpeed,0);
        break;
    default:
        break;
    }
}
