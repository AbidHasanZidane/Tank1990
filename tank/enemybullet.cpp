#include "enemybullet.h"

enemyBullet::enemyBullet(QPoint _pos, QPixmap _pixmap, char _dir)
{
    this->setPos(_pos);

    this->setPixmap(QPixmap(_pixmap));

    this->_dir=_dir;
}

void enemyBullet::eBulletMove()
{
    switch (this->_dir) {
    case 'N':
        this->moveBy(0,-eBulletSpeed);
        break;
    case 'S':
        this->moveBy(0,eBulletSpeed);
        break;
    case 'W':
        this->moveBy(-eBulletSpeed,0);
        break;
    case 'E':
        this->moveBy(eBulletSpeed,0);
        break;
    default:
        break;
    }
}
