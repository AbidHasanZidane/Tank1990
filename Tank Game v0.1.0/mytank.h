#ifndef MYTANK_H
#define MYTANK_H

#include <QObject>
#include<QGraphicsPixmapItem>
#include<QKeyEvent>

class MyTank : public QGraphicsPixmapItem
{
public:
    MyTank();

    int mTankSpeed=10;
private:

};

#endif // MYTANK_H
