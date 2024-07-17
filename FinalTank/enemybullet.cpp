#include "enemybullet.h"

enemyBullet::enemyBullet(QPoint _pos, QPixmap _pixmap, char _dir)
{
    // 构造函数，初始化敌人子弹对象
    this->setPos(_pos);     // 设置子弹的初始位置
    this->setPixmap(QPixmap(_pixmap));  // 设置子弹的图像

    this->_dir = _dir;      // 设置子弹的移动方向
}

void enemyBullet::eBulletMove()
{
    // 敌人子弹移动函数，根据当前方向移动子弹的位置
    switch (this->_dir) {
    case 'N':   // 北方向
        this->moveBy(0, -eBulletSpeed);   // 向上移动
        break;
    case 'S':   // 南方向
        this->moveBy(0, eBulletSpeed);    // 向下移动
        break;
    case 'W':   // 西方向
        this->moveBy(-eBulletSpeed, 0);   // 向左移动
        break;
    case 'E':   // 东方向
        this->moveBy(eBulletSpeed, 0);    // 向右移动
        break;
    default:
        break;
    }
}
