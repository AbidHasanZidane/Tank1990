#include "mytank.h"

MyTank::MyTank()
{
    this->setPixmap(QPixmap("://90Tank/player_tank/mTank.png"));  // 设置我方坦克的图片

    this->setPos(200, 200);  // 设置我方坦克的初始位置为 (200, 200)
}