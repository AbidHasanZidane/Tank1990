#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include<QObject>

class Enemy : public QGraphicsPixmapItem,public QObject
{
public:
    Enemy(int x,int y,int Ehp);
    int enemySpeed=10;
    int EHP;
};

#endif // ENEMY_H
