#include "boss.h"

BOSS::BOSS(int x, int y)
{
    this->setPixmap(QPixmap("://90Tank/enemy/space_full_preview.png"));  // 设置BOSS的图像

    this->setPos(x, y);  // 设置BOSS的位置
}
