#ifndef MYTANK_H
#define MYTANK_H

#include <QObject>
#include<QGraphicsPixmapItem>
#include<QKeyEvent>
#include<QWidget>

class MyTank : public QGraphicsPixmapItem
{
public:
    int HP;

    MyTank();

    int mTankSpeed;
private:

};

#endif // MYTANK_H
