#include "enemy.h"

Enemy::Enemy()
{
    this->setPixmap(QPixmap("://90Tank/enemy/animation_sprite_126.png"));

    this->setPos(rand()%700,rand()%900);

}
