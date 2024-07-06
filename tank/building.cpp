#include "building.h"

Building::Building(int kind)
{
    this->kind=kind;
    switch (this->kind) {
    case 1:
        this->setPixmap(QPixmap("://90Tank/building/Wall.png"));
        this->setPos(100,100);
        break;
    case 2:
        this->setPixmap(QPixmap("://90Tank/building/Iron.png"));
        this->setPos(200,200);
        break;
    case 3:
        this->setPixmap(QPixmap("://90Tank/building/Grass.png"));
        this->setPos(300,300);
        break;
    case 4:
        this->setPixmap(QPixmap("://90Tank/building/Water.png"));
        this->setPos(400,400);
        break;
    }
}
