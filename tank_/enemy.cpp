#include "enemy.h"

Enemy::Enemy()
{
    this->setPixmap(QPixmap("://90Tank/enemy/animation_sprite_126.png"));  // 设置敌人的图片

    this->setPos(rand() % 700, rand() % 900);  // 随机设置敌人的初始位置
}
