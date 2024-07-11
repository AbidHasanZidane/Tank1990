#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Enemy : public QGraphicsPixmapItem, public QObject
{
public:
    Enemy();  // 敌人类的构造函数

private:
};

#endif // ENEMY_H
