#include "bullet.h"

Bullet::Bullet(QPoint _pos, QPixmap _pixmap, char _dir)
{
    this->setPos(_pos);  // 设置子弹的初始位置
    this->setPixmap(QPixmap(_pixmap));  // 设置子弹的外观（图像）
    this->_dir = _dir;  // 设置子弹的移动方向
}

void Bullet::BulletMove()
{
    switch (this->_dir) {
    case 'N':
        this->moveBy(0, -mBulletSpeed);  // 向北移动子弹（向上）
        break;
    case 'S':
        this->moveBy(0, mBulletSpeed);   // 向南移动子弹（向下）
        break;
    case 'W':
        this->moveBy(-mBulletSpeed, 0);  // 向西移动子弹（向左）
        break;
    case 'E':
        this->moveBy(mBulletSpeed, 0);   // 向东移动子弹（向右）
        break;
    default:
        break;  // 默认情况，不做任何操作
    }
}
