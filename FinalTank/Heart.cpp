#include "heart.h"

Heart::Heart(int x, int y)
{
    // 构造函数，初始化心形图标对象
    this->setPixmap(QPixmap("://90Tank/player_tank/Heart.png"));  // 设置心形图标的图片资源
    this->setPos(40 * x, 40 * y);  // 根据传入的坐标参数设置心形图标的位置
}
