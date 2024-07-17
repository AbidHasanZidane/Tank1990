#ifndef HEART_H
#define HEART_H
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include<QObject>

class Heart: public QGraphicsPixmapItem,public QObject
{
public:
    Heart(int x,int y);
};

#endif // HEART_H
