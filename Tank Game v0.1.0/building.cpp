#include "building.h"
// 构造函数，接受两个参数x和y用于设置建筑物的位置，一个kind决定建筑物种类
Building::Building(int y,int x,int kind)
{
    this->kind=kind;
    switch (this->kind) {
    case 1:
        this->setPixmap(QPixmap("://90Tank/building/Wall.png")); // 砖块图像
        this->setPos(40*x,40*y); // 设置位置
        break;
    case 2:
        this->setPixmap(QPixmap("://90Tank/building/Iron.png"));// 钢铁图像
        this->setPos(40*x,40*y); // 设置位置
        break;
    case 3:
        this->setPixmap(QPixmap("://90Tank/building/Grass.png"));// 树木图像
        this->setPos(40*x,40*y); // 设置位置
        break;
    case 4:
        this->setPixmap(QPixmap("://90Tank/building/Water.png"));// 水面图像
        this->setPos(40*x,40*y); // 设置位置
        break;
    }
}
