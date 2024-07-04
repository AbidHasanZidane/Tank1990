#include "bullet.h"

Bullet::Bullet(QPoint _pos, QPixmap _pixmap)
{

    this->setPos(_pos);

    this->setPixmap(QPixmap(_pixmap));


}
