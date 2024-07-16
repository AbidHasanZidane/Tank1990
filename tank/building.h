#ifndef BUILDING_H
#define BUILDING_H
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include<QObject>

// 定义一个Building类，继承自QGraphicsPixmapItem和QObject，用于表示游戏中的建筑物
class Building : public QGraphicsPixmapItem,public QObject
{
public:
int kind;
Building(int x,int y,int kind);
};

#endif // BUILDING_H
