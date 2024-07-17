#include "boss.h"

// BOSS 类的构造函数，接受两个整数参数 x 和 y 作为位置坐标
BOSS::BOSS(int x, int y)
{
    // 设置 BOSS 对象的图片 pixmap，图片路径是相对路径
    this->setPixmap(QPixmap("://90Tank/enemy/space_full_preview.png"));

    // 设置 BOSS 对象在场景中的位置
    this->setPos(x, y);
}
