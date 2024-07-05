#include "enemy.h"

Enemy::Enemy()
{
    this->setPixmap(QPixmap("://F:/90_tank/enemy/animation_sprite_126.png"));

    this->setPos(rand()%700,rand()%900);

}


   /*setPixmap(QPixmap("://F:/90_tank/boom/insect_sprite.png"));
   setPos(_pos);
   setPixmap(QPixmap("://F:/90_tank/boom/insect_sprite2.png"));
   setPos(_pos);
   setPixmap(QPixmap("://F:/90_tank/boom/insect_sprite3.png"));
   setPos(_pos);
   setPixmap(QPixmap("://F:/90_tank/boom/insect_sprite4.png"));
   setPos(_pos);
   setPixmap(QPixmap("://F:/90_tank/boom/insect_sprite5.png"));
   setPos(_pos);*/

