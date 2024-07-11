#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Enemy : public QGraphicsPixmapItem, public QObject
{
public:
   Enemy(int x,int y); // 敌人类的构造函数
   int enemySpeed=10;//设置敌人的速度
private:
};

#endif // ENEMY_H
