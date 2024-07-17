#include "building.h"

// Building 类的构造函数，接受 y 坐标、x 坐标和 kind（建筑物类型）作为参数
Building::Building(int y, int x, int kind)
{
    this->kind = kind; // 设置建筑物的种类

    // 根据建筑物的种类不同，设置不同的图片和位置
    switch (this->kind) {
    case 1:
        this->setPixmap(QPixmap("://90Tank/building/Wall.png")); // 墙壁类型，设置墙壁图片
        this->setPos(40 * x, 40 * y); // 设置墙壁的位置
        break;
    case 2:
        this->setPixmap(QPixmap("://90Tank/building/Iron.png")); // 铁墙类型，设置铁墙图片
        this->setPos(40 * x, 40 * y); // 设置铁墙的位置
        break;
    case 3:
        this->setPixmap(QPixmap("://90Tank/building/Grass.png")); // 草地类型，设置草地图片
        this->setPos(40 * x, 40 * y); // 设置草地的位置
        break;
    case 4:
        this->setPixmap(QPixmap("://90Tank/building/Water.png")); // 水域类型，设置水域图片
        this->setPos(40 * x, 40 * y); // 设置水域的位置
        break;
    }
}
