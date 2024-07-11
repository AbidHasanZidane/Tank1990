##ifndef MYTANK_H
#define MYTANK_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QWidget>

class MyTank : public QGraphicsPixmapItem
{
public:
    int HP; // 玩家坦克的生命值

    MyTank(); // 构造函数声明

    int mTankSpeed; // 坦克的速度属性

private:
};

#endif // MYTANK_H
