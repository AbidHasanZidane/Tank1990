#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Enemy : public QGraphicsPixmapItem, public QObject
{
public:
Enemy(int x，int y,int Ehp);  // 敌人类的构造函数
int enemyspeed=10;//敌人的速度
int EHP;//敌人血量

private:
};

#endif // ENEMY_H
