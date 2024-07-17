#include "enemy.h"

Enemy::Enemy(int x, int y, int Ehp)
{
    EHP = Ehp;   // 初始化敌人的生命值

    // 设置敌人的图像，假设图片路径是相对路径
    this->setPixmap(QPixmap("://90Tank/enemy/animation_sprite_126.png"));

    // 设置敌人的初始位置
    this->setPos(x, y);
}
