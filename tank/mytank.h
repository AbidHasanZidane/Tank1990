#ifndef MYTANK_H
#define MYTANK_H

#include <QObject>
#include<QGraphicsPixmapItem>
#include<QKeyEvent>

class MyTank : public QGraphicsPixmapItem
{
public:
    int HP=3;

    MyTank();

    int mTankSpeed=15;
private:

};

#endif // MYTANK_H
