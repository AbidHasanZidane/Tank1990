#include "heart.h"

Heart::Heart(int x,int y)
{
    this->setPixmap(QPixmap("://90Tank/player_tank/Heart.png"));
    this->setPos(40*x,40*y);
}
