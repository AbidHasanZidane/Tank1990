#include "heart.h"

// 实现Heart类的构造函数
Heart::Heart(int x, int y)
{
    // 设置Heart对象显示的像素图像为"://90Tank/player_tank/Heart.png"
    this->setPixmap(QPixmap("://90Tank/player_tank/Heart.png"));
    // 设置Heart对象在场景中的位置为(40*x, 40*y)，每个心的大小为40x40像素
    this->setPos(40 * x, 40 * y);
}
