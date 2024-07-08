#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include<QObject>

class Enemy : public QGraphicsPixmapItem,public QObject
{
public:
    Enemy();
private:
};

#endif // ENEMY_H
