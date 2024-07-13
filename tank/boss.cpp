#include "boss.h"

BOSS::BOSS(int x,int y)
{
    this->setPixmap(QPixmap("://90Tank/enemy/space_full_preview.png"));

    this->setPos(x,y);
}
