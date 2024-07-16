#include "bossbullet.h"

BossBullet::BossBullet(QPoint _pos, QPixmap _pixmap, char _dir)
{
    this->setPos(_pos);  // 设置子弹初始位置

    this->setPixmap(QPixmap(_pixmap));  // 设置子弹图像

    this->_dir = _dir;  // 设置子弹移动方向
}

void BossBullet::BossBulletMove()
{
    switch (this->_dir) {
    case 'N':
        this->moveBy(0, -BossBulletSpeed);  // 向北移动
        break;
    case 'S':
        this->moveBy(0, BossBulletSpeed);  // 向南移动
        break;
    case 'W':
        this->moveBy(-BossBulletSpeed, 0);  // 向西移动
        break;
    case 'E':
        this->moveBy(BossBulletSpeed, 0);  // 向东移动
        break;
    default:
        break;
    }
}
