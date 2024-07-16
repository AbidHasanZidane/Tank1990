#ifndef MYTANK_H
#define MYTANK_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class MyTank : public QGraphicsPixmapItem
{
public:
    int HP;//我方坦克血量

    MyTank();  // 我方坦克类的构造函数

    int mTankSpeed;  // 我方坦克的移动速度

private:

};

#endif // MYTANK_H
