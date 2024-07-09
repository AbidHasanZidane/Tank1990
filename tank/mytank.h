#ifndef MYTANK_H
#define MYTANK_H

#include <QObject>
#include<QGraphicsPixmapItem>
#include<QKeyEvent>
#include<QWidget>

class MyTank : public QGraphicsPixmapItem
{
public:
    int HP=3;

    MyTank();

    int mTankSpeed=10;
private:

};

#endif // MYTANK_H
