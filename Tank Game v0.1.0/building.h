#ifndef BUILDING_H
#define BUILDING_H
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include<QObject>

class Building : public QGraphicsPixmapItem,public QObject
{
public:
    int kind;
    Building(int x,int y,int kind);
};

#endif // BUILDING_H