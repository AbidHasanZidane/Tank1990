#include "bossbullet.h"

BossBullet::BossBullet(QPoint _pos,QPixmap _pixmap,char _dir)
{
    this->setPos(_pos);

    this->setPixmap(QPixmap(_pixmap));

    this->_dir=_dir;
}

void BossBullet::BossBulletMove()
{
    switch (this->_dir) {
    case 'N':
        this->moveBy(0,-BossBulletSpeed);
        break;
    case 'S':
        this->moveBy(0,BossBulletSpeed);
        break;
    case 'W':
        this->moveBy(-BossBulletSpeed,0);
        break;
    case 'E':
        this->moveBy(BossBulletSpeed,0);
        break;
    default:
        break;
    }
}
