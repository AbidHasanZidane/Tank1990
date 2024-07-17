#include "bossbullet.h"

// BossBullet 类的构造函数，接受子弹位置 _pos、子弹图片 _pixmap 和方向 _dir 作为参数
BossBullet::BossBullet(QPoint _pos, QPixmap _pixmap, char _dir)
{
    // 设置子弹的初始位置
    this->setPos(_pos);

    // 设置子弹的图像 pixmap
    this->setPixmap(QPixmap(_pixmap));

    // 设置子弹的方向
    this->_dir = _dir;
}

// BossBulletMove 方法用于移动子弹，根据子弹的方向 _dir 进行移动
void BossBullet::BossBulletMove()
{
    switch (this->_dir) {
    case 'N':
        this->moveBy(0, -BossBulletSpeed); // 向北移动
        break;
    case 'S':
        this->moveBy(0, BossBulletSpeed);  // 向南移动
        break;
    case 'W':
        this->moveBy(-BossBulletSpeed, 0); // 向西移动
        break;
    case 'E':
        this->moveBy(BossBulletSpeed, 0);  // 向东移动
        break;
    default:
        break; // 默认情况不移动
    }
}
