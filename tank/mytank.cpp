#include "mytank.h"

MyTank::MyTank()
{
    this->setPixmap(QPixmap("://90Tank/player_tank/mTank.png")); // 设置玩家坦克的图片资源

    this->setPos(200, 200); // 设置玩家坦克的初始位置为(200, 200)
}
