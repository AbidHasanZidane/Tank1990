#include "enemy.h"

Enemy::Enemy(int x,int y)
{
    this->setPixmap(QPixmap("://90Tank/enemy/animation_sprite_126.png"));  // 设置敌人的图片

    this->setPos(x,y);  // 设置敌人的初始位置
}
