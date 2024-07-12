#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include<QObject>

class Enemy : public QGraphicsPixmapItem,public QObject
{
public:
    Enemy(int x,int y);
    int enemySpeed=10;
private:
};

#endif // ENEMY_H
