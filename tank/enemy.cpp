#include "enemy.h"

Enemy::Enemy(int x,int y,int Ehp)
{
    EHP=Ehp;
    this->setPixmap(QPixmap("://90Tank/enemy/animation_sprite_126.png"));

    this->setPos(x,y);

}
