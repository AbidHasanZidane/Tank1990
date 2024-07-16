#include "building.h"

Building::Building(int y,int x,int kind)
{
    this->kind=kind;
    switch (this->kind) {
    case 1:
        this->setPixmap(QPixmap("://90Tank/building/Wall.png"));
        this->setPos(40*x,40*y);
        break;
    case 2:
        this->setPixmap(QPixmap("://90Tank/building/Iron.png"));
        this->setPos(40*x,40*y);
        break;
    case 3:
        this->setPixmap(QPixmap("://90Tank/building/Grass.png"));
        this->setPos(40*x,40*y);
        break;
    case 4:
        this->setPixmap(QPixmap("://90Tank/building/Water.png"));
        this->setPos(40*x,40*y);
        break;
    }
}
